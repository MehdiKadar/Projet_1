#include <Arduino.h>
#include "LedRGB.h"


#define PIN_RGB_RED    11
#define PIN_RGB_GREEN  10
#define PIN_RGB_BLUE    9

LedRGB led(PIN_RGB_RED,PIN_RGB_GREEN,PIN_RGB_BLUE);

void setup() {
  Serial.begin(9600);
  while (!Serial) {
  }
  led.init();
  
}

void loop() {
 
}
