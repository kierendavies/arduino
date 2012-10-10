#include <TM1638.h>

TM1638 module(8, 9, 7);

byte chase[20][8] = {
  { 1, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 1, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 1 },
  { 0, 0, 0, 0, 0, 0, 0, 2 },
  { 0, 0, 0, 0, 0, 0, 0, 4 },
  { 0, 0, 0, 0, 0, 0, 0, 8 },
  { 0, 0, 0, 0, 0, 0, 8, 0 },
  { 0, 0, 0, 0, 0, 8, 0, 0 },
  { 0, 0, 0, 0, 8, 0, 0, 0 },
  { 0, 0, 0, 8, 0, 0, 0, 0 },
  { 0, 0, 8, 0, 0, 0, 0, 0 },
  { 0, 8, 0, 0, 0, 0, 0, 0 },
  { 8, 0, 0, 0, 0, 0, 0, 0 },
  {16, 0, 0, 0, 0, 0, 0, 0 },
  {32, 0, 0, 0, 0, 0, 0, 0 }};
int i = 0;

void setup() {
  module.setupDisplay(true, 0);
  module.setDisplayToString(" HELLO");
  byte exclamation[] = {
    2  };
  module.setDisplayDigit(0, 6, true, exclamation);
  delay(1000);
  
//  module.setDisplayToString("  420  C", 0b00010000);
//  byte deg[] = { 0b01100011 };
//  module.setDisplayDigit(0, 6, false, deg);
}

void loop() {
  module.setDisplayToDecNumber(millis(), 8);
//  module.setLEDs((millis() >> 6) & 0xFF);

//  module.setDisplay(chase[i]);
//  i = (i + 1) % 20;
//  delay(50);

//  module.setDisplayToString("UN      ");
//  delay(234);
//  module.setDisplayToString("UNCE    ");
//  delay(234);
//  module.setDisplayToString("    UN  ");
//  delay(234);
//  module.setDisplayToString("    UNCE");
//  delay(234);
}

