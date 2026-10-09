

int sensorPin = A0; //A0 FOR ARDUINO/ 36 FOR ESP

void setup()
{ 
  Serial.begin(9600);
  
}
void loop() {
  int turbidityValue = analogRead(turbidityPin);
  Serial.println(turbidityValue);
  int turbidity = map(turbidityValue, 0, 750, 100, 0);
  delay(100);
  
  
  delay(100);
  if (turbidity < 20) {
    
    Serial.print("Turbidity Sensor Value: ");
    Serial.print(turbidity);  
      
    

  }
  if ((turbidity > 20)  {
    
    Serial.print("Turbidity Sensor Value: ");
    Serial.print(turbidity);     
    Serial.println("obstacle ");

  }
}