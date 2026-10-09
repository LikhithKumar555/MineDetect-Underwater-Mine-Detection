int pirSensorPin = A1;  // PIR sensor output connected to Analog pin A0
int ledPin = 3;       // Built-in LED on pin 13
int sensorValue;       // Variable to store the sensor value
float frequency;       // Variable to store the calculated frequency value

void setup() {
  Serial.begin(9600);   // Initialize serial communication
  pinMode(pirSensorPin, INPUT);  // Set PIR sensor pin as input
  pinMode(ledPin, OUTPUT);       // Set LED pin as output
}

void loop() {
  int pirSensorValue = digitalRead(pirSensorPin);  // Read the PIR sensor value

  if (pirSensorValue == HIGH) {
    Serial.println("Motion detected!");  // Print message to serial monitor
    digitalWrite(ledPin, HIGH);          // Turn on the LED

    // Measure the voltage value
    sensorValue = analogRead(A0);  // Read the voltage value from analog pin A0
    float voltage = ((sensorValue)+500) * (5.0 / 1023.0);  // Convert the sensor value to voltage (5V reference, 444 steps for 1V)
    frequency = voltage * 200;  // Calculate the frequency based on the linear relationship

    Serial.print(frequency);  // Print the calculated frequency
    Serial.println(" Hz");    // Print the unit (Hz)

    delay(1500);                         // Delay to see the LED status
  }
  else {
    Serial.println("No motion detected.");  // Print message to serial monitor
    digitalWrite(ledPin, LOW);          // Turn off the LED

    // Measure the voltage value
    sensorValue = analogRead(A0);  // Read the voltage value from analog pin A0
    float voltage = (sensorValue) * (5.0 / 1023.0);  // Convert the sensor value to voltage (5V reference, 10-bit ADC)

    frequency = voltage * 200;  // Calculate the frequency based on the linear relationship

    Serial.print(frequency);  // Print the calculated frequency
    Serial.println(" Hz");    // Print the unit (Hz)

    delay(100);  // Delay between motion detection checks
  }
}
