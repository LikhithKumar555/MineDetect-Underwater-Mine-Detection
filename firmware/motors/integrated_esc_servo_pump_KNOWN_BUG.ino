#include <Servo.h>

Servo esc1;  
Servo esc2;  
Servo pumpservo;  // Create a servo object
bool shouldRotate = false;  // Flag to track if the servo should rotate
const int irPin = A0;       // Analog pin connected to the IR sensor
const int threshold = 300;  // Threshold value for object detection
int sensorValue = 0;        // Variable to store the sensor value
const int motorPin1 = 2; // Motor 1 control pin
const int motorPin2 = 3; // Motor 2 control pin



void setup() {
  esc1.attach(9);  
  esc2.attach(10); 
  esc1.writeMicroseconds(1000);  
  esc2.writeMicroseconds(1000);  // send a 1000us pulse to the second ESC (minimum throttle)
  delay(2000);  // wait for the ESCs to recognize the minimum throttle
  Serial.begin(9600);  // initialize serial communication

  // Run both motors at a fixed speed when power is connected
  esc1.writeMicroseconds(1500);  // set throttle for motor 1
  esc2.writeMicroseconds(1500);  // set throttle for motor 2
  delay(3000);  // run motors for 5 seconds
  esc1.writeMicroseconds(1000);  // stop motor 1
  esc2.writeMicroseconds(1000);  // stop motor 2
  pumpservo.attach(8);  // Attaches the servo on pin 8
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {

  //  bushless motor

  if (Serial.available() > 0) {
    char command = Serial.read();  // read the incoming command

    // determine the throttle values based on the command
    int throttle1 = 1000;  // default throttle for motor 1 (low speed)
    int throttle2 = 1000;  // default throttle for motor 2 (low speed)
    if (command == 'f') {
      throttle1 = 1000;  // low speed forward for motor 1
      throttle2 = 1000;  // low speed forward for motor 2
    } else if (command == 'b') {
      throttle1 = 1300;  // low speed backward for motor 1
      throttle2 = 1300;  // low speed backward for motor 2
    } else if (command == 'l') {
      // decrease throttle of motor 2 for left turn
      throttle2 = 1200;  // reduce speed of motor 2 for left turn
    } else if (command == 'r') {
      throttle1 = 1200;  // reduce speed of motor 1 for right turn
      // implement right turn
    } else if (command == 'd') {
      throttle1 = 1400;  // higher speed forward for motor 1
      throttle2 = 1400;  // higher speed forward for motor 2
    }

    // send the throttle signals to the ESCs
    esc1.writeMicroseconds(throttle1);
    esc2.writeMicroseconds(throttle2);
  }

  //  servo  for motor direction change

  if (Serial.available() > 0) {
    char direction = Serial.read(); // Read the input
    
    if (direction == 'u') {
      // If input is 'u' for "up", set the flag to rotate to 90 degrees
      shouldRotate = true;
      gradualTurn(90);
      shouldRotate = false;  // Reset the flag after rotating
    } else if (direction == 's') {
      // If input is 's' for "side", set the flag to rotate to -90 degrees
      shouldRotate = true;
      gradualTurn(-90);
      shouldRotate = false;  // Reset the flag after rotating
    }
  }
}

void gradualTurn(int targetAngle) {
  int currentAngle = pumpservo.read();
  int increment = (targetAngle - currentAngle > 0) ? 1 : -1;
  
  for (int angle = currentAngle; angle != targetAngle; angle += increment) {
    if (shouldRotate) {
      pumpservo.write(angle);
      delay(15);  // Adjust the delay to control the speed of rotation
    } else {
      break;  // Exit the loop if shouldRotate is false
    }
  }

  // pump ir sensor based

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
