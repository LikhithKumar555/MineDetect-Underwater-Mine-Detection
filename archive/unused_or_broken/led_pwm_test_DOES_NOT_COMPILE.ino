
const int ledPin = 13;  
const int ledPin2 = 11; 
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  analogWrite(ledpin2, 255);
}
