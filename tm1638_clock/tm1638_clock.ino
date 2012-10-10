/* Clock for TM1638 module
 * Kieren Davies
 *
 * To synchronise the clock, use the following shell command.
 * echo $(($(date +%s) - $(date -d "today 00:00:00" +%s))) > /dev/ttyACM0
 */

#include <TM1638.h>

TM1638 module(8, 9, 7);

long offset = 0;
byte intensity = 0;
long lastpress = 0;

void setup() {
  Serial.begin(9600);
  module.setupDisplay(true, intensity);
  module.clearDisplay();
  //module.setDisplayToString("  -  -  ");
}

void loop() {
  long time = millis();
  if (Serial.available() > 1)
    offset = Serial.parseInt()*1000l - time;
  time += offset;
  module.setDisplayDigit((time / 1000) % 10, 7, false);
  module.setDisplayDigit((time / 10000) % 6, 6, false);
  module.setDisplayDigit((time / 60000) % 10, 4, false);
  module.setDisplayDigit((time / 600000) % 6, 3, false);
  module.setDisplayDigit((time / 3600000) % 10, 1, false);
  module.setDisplayDigit((time / 36000000) % 10, 0, false);
  
  if (module.getButtons() && time > lastpress + 200) {
    intensity++;
    intensity %= 8;
    module.setupDisplay(true, intensity);
    lastpress = time;
  }
}

