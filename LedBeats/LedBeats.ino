int numLeds = 4;
int leds[] = {8, 9, 10, 11};

int tempo = 60;
unsigned long interval = 60000000 / tempo;

void setup() {
  for (int i = 0; i < numLeds; ++i) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; ++i) {
    if ((micros() % (interval >> i)) < (interval >> (i + 1))) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }
}
