#include <Servo.h>

Servo esc1;  
Servo esc2;  

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
}

void loop() {
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
}
