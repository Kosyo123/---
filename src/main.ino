int pirPin = 2;
int lampPin = 8;

unsigned long lastMotionTime = 0;     
const unsigned long holdTime = 5000;  
void setup() {
  pinMode(pirPin, INPUT);
  pinMode(lampPin, OUTPUT);
  digitalWrite(lampPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);

  if (motion == HIGH) {
    
    digitalWrite(lampPin, HIGH);
    lastMotionTime = millis();
    Serial.println("Dvijenie!");
  }

  
  if (millis() - lastMotionTime >= holdTime) {
    digitalWrite(lampPin, LOW);
  }
}

