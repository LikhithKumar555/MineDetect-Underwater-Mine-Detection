const int irPin = A0;       // Analog pin connected to the IR sensor
const int threshold = 300;  // Threshold value for object detection
int sensorValue = 0;        // Variable to store the sensor value
const int motorPin1 = 2; // Motor 1 control pin
const int motorPin2 = 3; // Motor 2 control pin

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  Serial.begin(9600); // Initialize serial communication
}

void loop() {

  // Read IR sensor value
  int irValue = analogRead(irPin);
  char command = Serial.read();

  if (sensorValue > threshold) {
    if (command == 'i') {
      digitalWrite(motorPin1, HIGH); // Turn on motor 1
    }
    else if (command == 's') {
      char command = Serial.read();
      digitalWrite(motorPin1, LOW); // Stop motor 1
      digitalWrite(motorPin2, LOW); // Stop motor 2
      return; // Exit loop to prevent motors from restarting immediately
    } 
  }
  else {
    digitalWrite(motorPin1, LOW); // Stop motor 1
    digitalWrite(motorPin2, LOW); // Stop motor 2
    return; // Exit loop to prevent motors from restarting immediately

  }

  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'o') {
      digitalWrite(motorPin2, HIGH); // Turn on motor 2
    }
  }
}
