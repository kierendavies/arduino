int pinLed = 13;
int pinButtonA = 4;
int pinButtonB = 3;
int pinButtonC = 5;
int pinPotA = 0;
int pinPotB = 1;

unsigned int delayAmount = 50;
boolean ledState = false;
unsigned long time;
unsigned long nextTime;
int stateA;
int lastStateA = HIGH;
int stateB;
int lastStateB = HIGH;

/*int flip(int state) {
  if (state == LOW)
    return HIGH;
  return LOW;
}*/

void setup() {                
  pinMode(pinLed, OUTPUT);
  pinMode(pinButtonA, INPUT_PULLUP);
  pinMode(pinButtonB, INPUT_PULLUP);
  nextTime = millis();
}

void loop() {
  //read
  int stateA = digitalRead(pinButtonA);
  int stateB = digitalRead(pinButtonB);
  int potA = analogRead(pinPotA);
  int potB = analogRead(pinPotB);
  
  //buttons
  if (stateA == LOW) {
    Serial.print("a = ");
    Serial.println(potA);
  }
  if (stateB == LOW) {
    Serial.print("b = ");
    Serial.println(potB);
  }
  lastStateA = stateA;
  lastStateB = stateB;
  
  //led
  time = millis();
  if (time >= nextTime) {
    ledState = !ledState;
    if (ledState) {
      analogWrite(pinLed, map(potB, 0, 1024, 255, 0));
    } else {
      analogWrite(pinLed, 0);
    }
    nextTime += potA;
  }
}
