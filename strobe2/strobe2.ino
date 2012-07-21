int pinLed = 13;
int pinPotA = 0;
int pinPotB = 1;

boolean ledState = false;
unsigned long nextTime;

void setup() {                
  pinMode(pinLed, OUTPUT);
  nextTime = millis();
}

void loop() {
  //read
  int potA = analogRead(pinPotA);
  int potB = analogRead(pinPotB);
  
  //led
  if (millis() >= nextTime) {
    ledState = !ledState;
    if (ledState) {
      digitalWrite(pinLed, HIGH);
      nextTime += potA;
    } else {
      digitalWrite(pinLed, LOW);
      nextTime += potB;
    }
  }
}
