#include "rgbled_lib.h"

int val = -1;
RGBLed l(9, 10, 11);

void setup() {
}

void loop() {
  val++;
  if(val == 0) {
    l.set(255, 0, 0);
  } else if(val == 1) {
    l.set(0, 255, 0);
  } else if(val ==2) {
    l.set(0, 0, 255);
  } else {
    val = -1;
  }
  delay(500);
}
