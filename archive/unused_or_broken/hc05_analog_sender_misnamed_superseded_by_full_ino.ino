#include <SoftwareSerial.h>

#define LED_PIN 13 // Pin connected to the LED
#define ANALOG_PIN A0 // Analog pin for reading input
SoftwareSerial BTSerial(2, 3); // RX, TX pins for HC-05

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(ANALOG_PIN, INPUT);
  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {
  // Read analog input from pin A0
  int sensorValue = analogRead(ANALOG_PIN);
  
  // Send sensor value to laptop via Bluetooth
  BTSerial.print(sensorValue);
  Serial.println(sensorValue);
  BTSerial.print('\n'); // Add a newline character to indicate end of transmission

  // Blink LED based on sensor value
  digitalWrite(LED_PIN, HIGH);
  delay(sensorValue); // Delay based on sensor value
  digitalWrite(LED_PIN, LOW);
  delay(sensorValue); // Delay based on sensor value
}
