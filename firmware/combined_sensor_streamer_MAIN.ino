#include <SoftwareSerial.h>

SoftwareSerial BTSerial(8, 9);  // RX, TX pins on Arduino
#define ANALOG_PIN A0
#define ANALOG_PIN A1
#define ANALOG_PIN A2
#define ANALOG_PIN A3
#define ANALOG_PIN A4
#define ANALOG_PIN A5
const int pirSensorPin3 = 6;
const int trigPin1 = 3;
const int echoPin1 = 2;
const int trigPin2 = 4;

const int echoPin2 = 5;
const int microsensorPin4 = A1;
const int microsensorPin5 = A2;
const int microsensorPin6 = A3;
const int microsensorPin7 = A4;
const int microsensorPin8 = A5;
const int turbidityPin = A0;
const int irSensorPin = 7;
float frequency;
const int ledPin = 13;
const int ledPin2 = 11;
const int threshold = 300;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);  // HC-05 default baud rate

  pinMode(irSensorPin, INPUT);
  pinMode(pirSensorPin3, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  randomSeed(analogRead(0));
}

void loop() {
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, HIGH);
  int sensorState = digitalRead(irSensorPin);

  if (sensorState == 1) {



    delay(100);

    int pirSensorValue = digitalRead(pirSensorPin3
    );

    if (pirSensorValue == HIGH) {

      float voltage = (pirSensorValue + 10000) * (5.0 / 1023.0);
      frequency = voltage * 200;

      Serial.print(frequency);
      BTSerial.print(frequency);
      Serial.print(',');
      BTSerial.print(',');

      delay(100);

    } else {

      float voltage = (pirSensorValue+523) * (5.0 / 1023.0);
      frequency = voltage * 200;
      Serial.print(frequency);
      BTSerial.print(frequency);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    // Check if motion is detected by 1 ULTRASONIC sensor
    float duration1, distance1;
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);
    duration1 = pulseIn(echoPin1, HIGH);
    distance1 = (duration1 / 2) / 29.1;
    if (distance1 < 30) {

      float frequency1 = distance1 +516;
      Serial.print(frequency1);
      BTSerial.print(frequency1);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    } else {

      float frequency1 = distance1+516 ;
      Serial.print(frequency1);
      BTSerial.print(frequency1);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    // Check if motion is detected by 2 ULTRASONIC sensor
    float duration2, distance2;
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = (duration2 / 2) / 29.1;
    if (distance2 < 30) {

      float frequency2 = distance2 + 10000;
      Serial.print(frequency2);
      BTSerial.print(frequency2);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    } else {

      float frequency2 = distance2 +320;
      Serial.print(frequency2);
      BTSerial.print(frequency2);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }


    // Check if motion is detected by 4 MICROPHONE sensor
    int sensorValue4 = analogRead(microsensorPin4);
    if (sensorValue4 > threshold) {


      float voltage4 = (sensorValue4 + 10000) * (5.0 / 1023.0);
      float frequency4 = voltage4 * 200;
      Serial.print(frequency4);
      BTSerial.print(frequency4);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    } else {


      float voltage4 = (sensorValue4 +300) * (5.0 / 1023.0);
      float frequency4 = voltage4 * 200;
      Serial.print(frequency4);
      BTSerial.print(frequency4);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    // Check if motion is detected by 5 MICROPHONE sensor
    int sensorValue5 = analogRead(microsensorPin5);
    if (sensorValue5 > threshold) {

      float voltage5 = (sensorValue5 + 10000) * (5.0 / 1023.0);
      float frequency5 = voltage5 * 200;
      Serial.print(frequency5);
      BTSerial.print(frequency5);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    } else {

      float voltage5 = (sensorValue5+500) * (5.0 / 1023.0);
      float frequency5 = voltage5 * 200;
      Serial.print(frequency5);
      BTSerial.print(frequency5);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    // Check if motion is detected by 6 MICROPHONE sensor
    int sensorValue6 = analogRead(microsensorPin6);
    if (sensorValue6 < threshold) {


      float voltage6 = (sensorValue6 + 10000) * (5.0 / 1023.0);
      float frequency6 = voltage6 * 200;
      Serial.print(frequency6);
      BTSerial.print(frequency6);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    } else {


      float voltage6 = (sensorValue6 - 500) * (5.0 / 1023.0);
      float frequency6 = voltage6 * 200;
      Serial.print(frequency6);
      BTSerial.print(frequency6);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    // Check if motion is detected by 7 MICROPHONE sensor
    int sensorValue7 = analogRead(microsensorPin7);
    if (sensorValue7 < threshold) {


      float voltage7 = (sensorValue7 + 10000) * (5.0 / 1023.0);
      float frequency7 = voltage7 * 200;
      Serial.print(frequency7);
      BTSerial.print(frequency7);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    } else {


      float voltage7 = (sensorValue7 - 500) * (5.0 / 1023.0);
      float frequency7 = voltage7 * 200;
      Serial.print(frequency7);
      BTSerial.print(frequency7);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    // Check if motion is detected by 8 MICROPHONE sensor
    int sensorValue8 = analogRead(microsensorPin8);
    if (sensorValue8 < threshold) {


      float voltage8 = (sensorValue8 + 10000) * (5.0 / 1023.0);
      float frequency8 = voltage8 * 200;
      Serial.print(frequency8);
      BTSerial.print(frequency8);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    } else {


      float voltage8 = (sensorValue8 - 500) * (5.0 / 1023.0);
      float frequency8 = voltage8 * 200;
      Serial.print(frequency8);
      BTSerial.print(frequency8);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    float randomNumber = random(1, 20);  // Generate a random number between 1 and 20


    Serial.print(randomNumber);
    BTSerial.print(randomNumber);
    Serial.print('\n');
    BTSerial.print('\n');





    delay(100);
  } else {

    delay(100);

    // Check if motion is detected by PIR sensor
    int pirSensorValue = digitalRead(pirSensorPin3);
    if (pirSensorValue == HIGH) {

      float voltage = (pirSensorValue + 10000) * (5.0 / 1023.0);
      frequency = voltage * 200 + 1000;
      Serial.print(frequency);
      BTSerial.print(frequency);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);

      delay(100);
    } else {

      float voltage = (pirSensorValue - 500) * (5.0 / 1023.0);
      frequency = voltage * 200 + 1000;
      Serial.print(frequency);
      BTSerial.print(frequency);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    // Check if motion is detected by 1 ULTRASONIC sensor
    float duration1, distance1;
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(2);
    digitalWrite(trigPin1, LOW);
    duration1 = pulseIn(echoPin1, HIGH);
    distance1 = (duration1 / 2) / 29.1;
    if (distance1 <= 20 ) {

      float frequency1 = distance1 +516;

      Serial.print(frequency1);

      BTSerial.print(frequency1);
      Serial.print(',');
      BTSerial.print(',');


      delay(100);
    } else {

      float frequency1 = distance1 +516;
      Serial.print(frequency1);

      BTSerial.print(frequency1);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    // Check if motion is detected by 2 ULTRASONIC sensor
    float duration2, distance2;
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(2);
    digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
    distance2 = (duration2 / 2) / 29.1;
    if (distance2 <= 20 || distance2 > 300) {

      float frequency2 = distance2 + 10000;
      Serial.print(frequency2);

      BTSerial.print(frequency2);
      Serial.print(',');
      BTSerial.print(',');

      delay(100);
    } else {

      float frequency2 = distance2 - 400 + 689;
      Serial.print(frequency2);

      BTSerial.print(frequency2);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }


    // Check if motion is detected by 4 MICROPHONE sensor
    int sensorValue4 = analogRead(microsensorPin4);
    if (sensorValue4 > threshold) {

      float voltage4 = (sensorValue4 + 10000) * (5.0 / 1023.0);
      float frequency4 = voltage4 * 200;
      Serial.print(frequency4);

      BTSerial.print(frequency4);
      Serial.print(',');
      BTSerial.print(',');

      delay(100);
    } else {

      float voltage4 = (sensorValue4+500 ) * (5.0 / 1023.0);
      float frequency4 = voltage4 * 200;
      Serial.print(frequency4);

      BTSerial.print(frequency4);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    // Check if motion is detected by 5 MICROPHONE sensor
    int sensorValue5 = analogRead(microsensorPin5);
    if (sensorValue5 > threshold) {

      float voltage5 = (sensorValue5 + 10000) * (5.0 / 1023.0);
      float frequency5 = voltage5 * 200;
      Serial.print(frequency5);

      BTSerial.print(frequency5);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    } else {

      float voltage5 = (sensorValue5+500 ) * (5.0 / 1023.0);
      float frequency5 = voltage5 * 200;
      Serial.print(frequency5);

      BTSerial.print(frequency5);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    // Check if motion is detected by 6 MICROPHONE sensor
    int sensorValue6 = analogRead(microsensorPin6);
    if (sensorValue6 < threshold) {

      float voltage6 = (sensorValue6 + 10000) * (5.0 / 1023.0);
      float frequency6 = voltage6 * 200;
      Serial.print(frequency6);

      BTSerial.print(frequency6);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    } else {

      float voltage7 = (sensorValue6 ) * (5.0 / 1023.0);
      float frequency6 = voltage7 * 200;
      Serial.print(frequency6);

      BTSerial.print(frequency6);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    // Check if motion is detected by 7 MICROPHONE sensor
    int sensorValue7 = analogRead(microsensorPin7);
    if (sensorValue7 < threshold) {

      float voltage7 = (sensorValue7 + 10000) * (5.0 / 1023.0);
      float frequency7 = voltage7 * 200;
      Serial.print(frequency7);

      BTSerial.print(frequency7);
      Serial.print(',');
      BTSerial.print(',');


      delay(100);
    } else {


      float voltage7 = (sensorValue7 ) * (5.0 / 1023.0);
      float frequency7 = voltage7 * 200;
      Serial.print(frequency7);

      BTSerial.print(frequency7);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    // Check if motion is detected by 8 MICROPHONE sensor
    int sensorValue8 = analogRead(microsensorPin8);
    if (sensorValue8 < threshold) {

      float voltage8 = (sensorValue8 + 10000) * (5.0 / 1023.0);
      float frequency8 = voltage8 * 200;
      Serial.print(frequency8);

      BTSerial.print(frequency8);
      Serial.print(',');
      BTSerial.print(',');

      delay(100);
    } else {

      float voltage8 = (sensorValue8 - 500) * (5.0 / 1023.0);
      float frequency8 = voltage8 * 200;
      Serial.print(frequency8);

      BTSerial.print(frequency8);
      Serial.print(',');
      BTSerial.print(',');
      delay(100);
    }

    int turbidityValue = analogRead(turbidityPin);

    float turbidity = map(turbidityValue, 0, 750, 100, 0);
    delay(100);
    if (turbidity < 20) {


      Serial.print(turbidity);

      BTSerial.print(turbidity);

      Serial.print('\n');
      BTSerial.print('\n');
      delay(100);


    } else {

      Serial.print(turbidity);

      BTSerial.print(turbidity);

      Serial.print('\n');
      BTSerial.print('\n');

      delay(100);
    }
    delay(100);
  }
}
