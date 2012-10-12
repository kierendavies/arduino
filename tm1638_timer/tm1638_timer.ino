/*
Timer for TM1638 module
Kieren Davies
*/

#define buttonPressed(buttons, x) ((buttons) >> (x) & 1 == 1)

#include <TM1638.h>

TM1638 module(8, 9, 7);
int buzzerPin = 12;

int intensity = 0;
int lastpress = 0;

boolean running = false;
long time = 0;
long startTime = 10000;
long endTime = 0;
long nextPressTime = 0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  //Serial.begin(9600);
  module.setupDisplay(true, intensity);
  module.clearDisplay();
  module.setLEDs(0x00FF);
}

void loop() {
  time = millis();
  if (running) {
    long remainingTime = endTime - millis();
    if (remainingTime > 0) {
      displayTime(remainingTime + 1000);
    } else {
      running = false;
      displayTime(0);
      module.setLEDs(0x00FF);
      alarm();
      endTime = 0;
    }
  } else {
    displayTime(endTime);
    byte buttons = module.getButtons();
    if (buttons == 0) {
      nextPressTime = time;
    } else if (time < nextPressTime) {
      return;
    } else if (buttonPressed(buttons, 0)) {
      intensity++;
      intensity %= 8;
      module.setupDisplay(true, intensity);
    } else if (buttonPressed(buttons, 1)) {
      endTime += 3600000;
    } else if (buttonPressed(buttons, 2)) {
      endTime -= 3600000;
    } else if (buttonPressed(buttons, 3)) {
      endTime += 60000;
    } else if (buttonPressed(buttons, 4)) {
      endTime -= 60000;
    } else if (buttonPressed(buttons, 5)) {
      endTime += 1000;
    } else if (buttonPressed(buttons, 6)) {
      endTime -= 1000;
    } else if (buttonPressed(buttons, 7)) {
      running = true;
      module.setLEDs(0xFF00);
      endTime += time;
    }
    if (endTime < 0) endTime = 0;
    if (buttons != 0) nextPressTime = time + 200;
  }
}

void displayTime(long time) {  // in milliseconds
  module.setDisplayDigit((time / 1000) % 10, 7, false);
  module.setDisplayDigit((time / 10000) % 6, 6, false);
  module.setDisplayDigit((time / 60000) % 10, 4, false);
  module.setDisplayDigit((time / 600000) % 6, 3, false);
  module.setDisplayDigit((time / 3600000) % 10, 1, false);
  module.setDisplayDigit((time / 36000000) % 10, 0, false);
}

void alarm() {
  digitalWrite(buzzerPin, HIGH);
  delay(20);
  digitalWrite(buzzerPin, LOW);
}
