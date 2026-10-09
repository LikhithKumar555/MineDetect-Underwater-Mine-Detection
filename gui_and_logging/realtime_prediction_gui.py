import joblib
import numpy as np
import serial
import csv
import tkinter as tk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg

# Load the saved model
model = joblib.load('model_svm.pkl')

# Initialize the serial port (update port and baudrate according to your setup)
ser = serial.Serial('COM6', 9600)

# Create a CSV file to store the predictions
csv_file = open('predictions.csv', 'w', newline='')
csv_writer = csv.writer(csv_file)
csv_writer.writerow(['Sensor 1', 'Sensor 2', 'Sensor 3', 'Sensor 4', 'Sensor 5', 'Sensor 6', 'Sensor 7', 'Sensor 8', 'Sensor 9', 'Prediction'])  # Write header to the CSV file

# Initialize Tkinter
# Initialize Tkinter
root = tk.Tk()
root.title('Prediction Display')
root.geometry("{0}x{1}+0+0".format(root.winfo_screenwidth(), root.winfo_screenheight()))  # Set window size to fill the screen


# Create a label to display the prediction
prediction_label = tk.Label(root, text='Waiting for prediction...', font=('Arial', 24))
prediction_label.pack()

# Create a single figure for all graphs
fig, axs = plt.subplots(3, 3, figsize=(12, 12))  # 3x3 grid for 9 subplots

# Initialize sensor values and timestamps for the graphs
sensor_values = [[] for _ in range(9)]
timestamps = []

# Function to continuously read data from the serial port, make predictions, and update the label and graphs
def update_prediction():
    try:
        data = ser.readline().decode('utf-8', errors='ignore').strip().split(',')
        if len(data) == 9:  # Assuming 9 sensor values are received
            sensor_values_current = list(map(float, data))
            timestamps.append(len(timestamps) + 1)
            for i in range(9):
                sensor_values[i].append(sensor_values_current[i])

            user_input = np.array([sensor_values_current])
            prediction = model.predict(user_input)[0]
            prediction_label.config(text=f'Prediction: {prediction}')
            csv_writer.writerow([*sensor_values_current, prediction])  # Write sensor values and prediction to the CSV file
            csv_file.flush()  # Flush the CSV file to ensure data is written immediately
            print(f"Sensor values: {sensor_values_current}, Prediction: {prediction}")

            # Update the graphs with new sensor values
            for i, ax_row in enumerate(axs):
                for j, ax in enumerate(ax_row):
                    index = i * 3 + j
                    if index < 9:
                        ax.clear()
                        ax.plot(timestamps, sensor_values[index], label=f'Sensor {index+1}')
                        ax.legend()
                        ax.set_xlabel('Time')
                        ax.set_ylabel('Sensor Value')
                        ax.set_title(f'Sensor {index+1} Value Over Time')

            plt.tight_layout()  # Adjust layout
            fig.canvas.draw()  # Redraw the canvas
        else:
            print("Invalid data received from serial port")
    except serial.SerialException as se:
        prediction_label.config(text='Serial port error')
        print(f"Serial port error: {se}")
    except Exception as e:
        prediction_label.config(text='Error processing data')
        print(f"Error processing data: {e}")

    # Schedule the next update after 100 milliseconds
    root.after(100, update_prediction)

# Create a canvas to display the matplotlib figure
canvas = FigureCanvasTkAgg(fig, master=root)
canvas_widget = canvas.get_tk_widget()
canvas_widget.pack(side=tk.TOP, fill=tk.BOTH, expand=1)

# Start updating the prediction label and graphs
update_prediction()

# Start the Tkinter event loop
root.mainloop()

# Close the CSV file and serial port
csv_file.close()
ser.close()
