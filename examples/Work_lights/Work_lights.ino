/*  Work_lights.ino
 *  ----------------------------------------------
 *  This example reproduces moving flashing lights
 *  to prevent dangerous areas as work zone or
 *  merging lanes. First LED on output 4 and number
 *  of LED = 10. All LEDs are connected by their
 *  anodes to digital outputs.
 *  ----------------------------------------------
 *  Christian Bezanger - October 3 - 2020
 *  Released into the public domain.
 */

#include <LightEffect.h>

// Instanciation - Level HIGH to light up the LED
LightEffect workLights(4, 10, HIGH);
 
void setup() {
}

void loop() {
  workLights.movingFlashRight();
}
