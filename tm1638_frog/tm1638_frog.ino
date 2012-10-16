/*
Frog game for TM1638 module
Kieren Davies

Get all the red "frogs" to the right and all the green "frogs" to the left.
Frogs can only move in one direction, and they can either move one unit into an
empty space or hop two units over one frog into an empty space.

Left button to reset.  Other buttons to move corresponding frogs.
*/

#include <TM1638.h>
TM1638 module(8, 9, 7);

byte EMPTY = 0;
byte RED = TM1638_COLOR_RED;
byte GREEN = TM1638_COLOR_GREEN;

byte frogs[7];

void setup() {
  //module.setDisplayToString("Froggy");
  reset();
}

void loop() {
  //display
  for (byte i = 0; i < 7; i++) {
    module.setLED(frogs[i], i+1);
  }
  //controls
  byte buttons = module.getButtons();
  if (buttons & 1) {
    reset();
  }
  for (byte i = 0; i < 7; i++) {
    //if (buttons >> (i+1) & 1) {
    if (buttons & (2 << i)) {
      if (frogs[i] == RED) {
        //red goes right
        if (i < 6 && frogs[i+1] == EMPTY) {
          frogs[i+1] = RED;
          frogs[i] = EMPTY;
        } else if (i < 5 && frogs[i+2] == EMPTY) {
          frogs[i+2] = RED;
          frogs[i] = EMPTY;
        }
      } else {
        //green goes left
        if (i > 0 && frogs[i-1] == EMPTY) {
          frogs[i-1] = GREEN;
          frogs[i] = EMPTY;
        } else if (i > 1 && frogs[i-2] == EMPTY) {
          frogs[i-2] = GREEN;
          frogs[i] = EMPTY;
        }
      }
    }
  }
}

void reset() {
  frogs[0] = RED;
  frogs[1] = RED;
  frogs[2] = RED;
  frogs[3] = EMPTY;
  frogs[4] = GREEN;
  frogs[5] = GREEN;
  frogs[6] = GREEN;
}
