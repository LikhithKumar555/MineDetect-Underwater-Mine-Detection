#define ENA 2    // Motor A enable pin
#define IN1 3    // Motor A direction pin 1
#define IN2 4    // Motor A direction pin 2
#define ENB 5    // Motor B enable pin
#define IN3 6   // Motor B direction pin 1
#define IN4 7   // Motor B direction pin 2

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Motor A forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200); // Set speed (0-255)
  Serial.println("Motor A Forward");
  delay(1000);

  // Motor A backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200); // Set speed (0-255)
  Serial.println("Motor A Backward");
  delay(1000);

  // Motor A stop
  analogWrite(ENA, 0);
  Serial.println("Motor A Stop");
  delay(1000);

  // Motor B forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 200); // Set speed (0-255)
  Serial.println("Motor B Forward");
  delay(1000);

  // Motor B backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 200); // Set speed (0-255)
  Serial.println("Motor B Backward");
  delay(1000);

  // Motor B stop
  analogWrite(ENB, 0);
  Serial.println("Motor B Stop");
  delay(1000);
}
