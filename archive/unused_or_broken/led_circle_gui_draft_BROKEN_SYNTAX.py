from PIL import Image, ImageDraw
import math
import tkinter as tk

# Initialize Tkinter
root = tk.Tk()

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
    # your update_prediction function code here

# Create a canvas to display the matplotlib figure
canvas = FigureCanvasTkAgg(fig, master=root)
canvas_widget = canvas.get_tk_widget()
canvas_widget.pack(side=tk.TOP, fill=tk.BOTH, expand=1)

# Create a new window for the LED circle
led_window = tk.Toplevel()
led_window.title('LED Circle')

# Create a canvas to draw the LED circle
led_canvas = tk.Canvas(led_window, width=300, height=300)
led_canvas.pack()

# Function to update the LED circle based on sensor values
def update_led_circle(root):  # Pass 'root' as an argument
    try:
        # Check if the values of sensors 1 to 8 are greater than 9000
        led_states = [sensor_value > 9000 for sensor_value in sensor_values[:8]]
        
        # Check if sensor 9 value is greater than 20
        if sensor_values[8] > 20:
            led_states.append(True)
        else:
            led_states.append(False)
        
        # Draw the LED circle
        led_canvas.delete("all")  # Clear previous drawings
        center_x, center_y = 150, 150  # Center of the circle
        radius = 100  # Radius of the circle
        num_leds = 9  # Number of LEDs
        angle_increment = 2 * math.pi / num_leds  # Angle increment for each LED
        for i, led_state in enumerate(led_states):
            angle = i * angle_increment
            x = int(center_x + radius * math.cos(angle))
            y = int(center_y + radius * math.sin(angle))
            color = 'red' if led_state else 'gray'
            led_canvas.create_oval(x - 10, y - 10, x + 10, y + 10, fill=color)  # Create LED circle
            
        led_window.update()  # Update the LED circle display
        root.after(100, lambda: update_led_circle(root))  # Schedule the next update
    except Exception as e:
        print(f"Error updating LED circle: {e}")

# Start updating the prediction label and graphs
update_prediction()

# Start the Tkinter event loop for the main window
root.mainloop()
