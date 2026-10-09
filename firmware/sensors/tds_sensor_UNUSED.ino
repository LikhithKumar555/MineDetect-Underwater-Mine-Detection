const int sensorPin = A1; // Analog pin connected to the sensor
const float VREF = 5.0;   // Reference voltage of the ADC
const float TDS_FACTOR = 0.5; // TDS factor for your sensor

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (VREF / 1024.0); // Convert ADC value to voltage
  float tdsValue = voltage * TDS_FACTOR; // Calculate TDS value
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print("V, TDS Value: ");
  Serial.print(tdsValue);
  Serial.println(" ppm");
  delay(1000); // Delay for stability
}
