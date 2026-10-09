#include <SoftwareSerial.h>

SoftwareSerial BTSerial(8, 9); // RX, TX pins on Arduino
// Define the digital pin for the IR sensor
const int irSensorPin = 7;


void setup() {
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
  BTSerial.begin(9600); // HC-05 default baud rate
  // Set the IR sensor pin as input
  pinMode(irSensorPin, INPUT);
}

void loop() {
  // Read the state of the IR sensor
  int sensorState = digitalRead(irSensorPin);

  // Print the sensor state to the serial monitor
  Serial.println(sensorState);
  
  BTSerial.println(sensorState);

  // Delay for a short amount of time
  delay(100);
}
