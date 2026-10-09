int sensorPin = A0;    // Analog input pin for the microphone sensor
int threshold = 300;   // Threshold value for sound detection
int sensorValue;       // Variable to store the sensor value
int ledPin = 13;       // Digital pin connected to the LED
float frequency;            

void setup() {
  Serial.begin(9600);  // Start the serial communication
  pinMode(ledPin, OUTPUT); // Set the LED pin as an output
}

void loop() {
  sensorValue = analogRead(sensorPin); // Read the sensor value

  if (sensorValue < threshold) {
    Serial.println("Sound detected!"); // Print a message when sound is detected
    Serial.println(sensorValue); 
    digitalWrite(ledPin, HIGH);         // Turn on the LED
    float voltage = (sensorValue+10000) * (5.0 / 1023.0);  // Convert the sensor value to voltage (5V reference, 1024 steps for 1V)
    frequency = voltage * 200;  // Calculate the frequency based on the linear relationship

    Serial.print("microphone : ");
    Serial.print(frequency);  // Print the calculated frequency
    Serial.println(" Hz");    // Print the unit (Hz)
    Serial.println("obstacle ");
    delay(5000);
    

  } else {
    Serial.println("No sound");        // Print a message when no sound is detected
    Serial.println(sensorValue); 
    digitalWrite(ledPin, LOW);          // Turn off the LED
    float voltage = (sensorValue-500) * (5.0 / 1023.0);  // Convert the sensor value to voltage (5V reference, 1024 steps for 1V)
    frequency = voltage * 200;  // Calculate the frequency based on the linear relationship

    Serial.print("microphone : ");
    Serial.print(frequency);  // Print the calculated frequency
    Serial.println(" Hz");    // Print the unit (Hz)
    

  }

  delay(100); // Delay for stability
}
