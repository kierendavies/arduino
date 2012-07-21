void setup() {
  pinMode(2, INPUT_PULLUP);
  while (!Serial);  // wait for serial
  Serial.begin(9600);
}

void loop() {
  Serial.print(digitalRead(2));
}
