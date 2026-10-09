import serial
import serial.tools.list_ports
import csv

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

portsList = []

for onePort in ports:
    portsList.append(str(onePort))
    print(str(onePort))

val = input("Select Port: COM")

for x in range(0, len(portsList)):
    if portsList[x].startswith("COM" + str(val)):
        portVar = "COM" + str(val)
        print(portVar)

serialInst.baudrate = 9600
serialInst.port = portVar

try:
    serialInst.open()

    with open('data.csv', mode='w', newline='') as file:
        writer = csv.writer(file)
        writer.writerow(['ID', 'PIR Sensor Frequency', 'ulrasonic1', 'ulrasonic2', 'microphone1', 'microphone2', 'microphone3',  'microphone4',  'microphone5', 'metaldetector', 'Obstacle'])

        order_number = 1
        data_dict = {
            'PIR Sensor Frequency': None,
            'ulrasonic1': None,
            'ulrasonic2': None,
            'microphone1': None,
            'microphone2': None,
            'microphone3': None,
            'microphone4': None,
            'microphone5': None,
            'metaldetector' : None,
            'obstacle': 'negative'
        }

        while True:
            try:
                data = serialInst.readline().decode('latin-1').strip()
                if data.startswith('obstacle'):
                    data_dict['obstacle'] = 'positive'
                elif data.startswith('PIR Sensor Frequency'):
                    data_dict['PIR Sensor Frequency'] = data.split(': ')[1].split(' ')[0]
                elif data.startswith('ulrasonic1'):
                    if ': ' in data:
                        data_dict['ulrasonic1'] = data.split(': ')[1].split(' ')[0]
                elif data.startswith('ulrasonic2'):
                    if ': ' in data:
                        data_dict['ulrasonic2'] = data.split(': ')[1].split(' ')[0]
                elif data.startswith('microphone1'):
                    if ': ' in data:
                        data_dict['microphone1'] = data.split(': ')[1].split(' ')[0]
                elif data.startswith('microphone2'):
                    if ': ' in data:
                        data_dict['microphone2'] = data.split(': ')[1].split(' ')[0]
                elif data.startswith('microphone3'):
                    if ': ' in data:
                        data_dict['microphone3'] = data.split(': ')[1].split(' ')[0]
                elif data.startswith('microphone4'):
                    if ': ' in data:
                        data_dict['microphone4'] = data.split(': ')[1].split(' ')[0]
                elif data.startswith('microphone5'):
                    if ': ' in data:
                        data_dict['microphone5'] = data.split(': ')[1].split(' ')[0]
                elif data.startswith('metaldetector'):
                    if ': ' in data:
                        data_dict['metaldetector'] = data.split(': ')[1].split(' ')[0]

                if all(data_dict.values()):
                    writer.writerow([order_number, data_dict['PIR Sensor Frequency'], data_dict['ulrasonic1'], data_dict['ulrasonic2'], data_dict['microphone1'], data_dict['microphone2'], data_dict['microphone3'], data_dict['microphone4'], data_dict['microphone5'], data_dict['metaldetector'], data_dict['obstacle']])
                    order_number += 1
                    data_dict = {
                        'PIR Sensor Frequency': None,
                        'ulrasonic1': None,
                        'ulrasonic2': None,
                        'microphone1': None,
                        'microphone2': None,
                        'microphone3': None,
                        'microphone4': None,
                        'microphone5': None,
                        'metaldetector' : None,
                        'obstacle': 'negative'
                    }
            except serial.SerialException:
                print("Connection to Arduino lost. Saving CSV file.")
                break
            except ValueError as e:
                print("ValueError:", e)
                continue

except serial.SerialException as e:
    print("Error opening serial port:", e)

finally:
    serialInst.close()
