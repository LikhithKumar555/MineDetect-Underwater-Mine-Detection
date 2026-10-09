import serial
import csv

# Serial port configuration
ser = serial.Serial('COM5', 9600)  # Change 'COM5' to your Arduino's serial port

# CSV file path
csv_file = "sensor_data.csv"

# Write data to CSV file
with open(csv_file, mode="w", newline="") as file:
    writer = csv.writer(file)
    writer.writerow(["Sensor", "Value"])  # Write header row

    while True:
        # Read line from serial
        line = ser.readline().decode('utf-8').rstrip()
        
        # Split line into sensor type and value
        sensor, value = line.split(',')
        
        # Write sensor data to CSV file
        writer.writerow([sensor.strip(), value.strip()])

        # Print sensor data to console
        print(sensor, value)

# Close serial port
ser.close()
