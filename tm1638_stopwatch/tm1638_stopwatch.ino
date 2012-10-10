#include <TM1638.h>

TM1638 module(8, 9, 7);

boolean running = false;
boolean lap = false;

long starttime = 0;
long stoptime = 0;
long current = 0;
long laptime = 0;

void setup() {
  module.setupDisplay(true, 0);
}

void loop() {
  //get buttons
  long time = millis();
  byte buttons = module.getButtons();
  if (buttons & 0b01000000) {
    if (running) {  //stop
      running = false;
      stoptime = time;
    } else {  //start
      running = true;
      if (starttime == 0) starttime = time;
      else starttime = time - starttime + stoptime;
    }
  }/* else if (buttons & 0b10000000) {
    if (running) {  //lap
      
    } else {  //reset
      start = 0;
    }
  }*/
  
  //display lap
}

