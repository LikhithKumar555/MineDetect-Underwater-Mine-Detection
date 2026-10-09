const int trigPin = 2;   // Trigger pin of the ultrasonic sensor
const int echoPin = 3;  // Echo pin of the ultrasonic sensor
const int ledPin = 13;   // LED pin

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  float duration, distance;
  
  
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Set the trigger pin high for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo pin, and calculate the duration in microseconds
  duration = pulseIn(echoPin, HIGH);

  
  // Calculate the distance in centimeters
  distance = (duration / 2) / 29.1;
  
  // Print the distance to the Serial monitor
  
  
  // Turn on the LED if the distance is less than 20 cm, otherwise turn it off
  if (distance > 30 ) {
    digitalWrite(ledPin, HIGH);
    float frequency=distance ;
    Serial.println(" ulrasonic: ");
    Serial.print(frequency);  // Print the calculated frequency
    Serial.println(" Hz");    // Print the unit (Hz)
    Serial.println("obstacle ");

  } else {
    digitalWrite(ledPin, LOW);
    float frequency=distance;
    Serial.println("ulrasonic:");
    Serial.print(frequency);  // Print the calculated frequency
    Serial.println(" Hz");
  }

    Serial.print("");
    Serial.print(distance); // Print the distance value to the serial monitor.
    Serial.println(" cm");
  
  delay(500); // Delay for 1 second before the next reading
}


