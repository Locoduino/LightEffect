/*  Blinking_lights.ino
 *  ----------------------------------------------
 *  This example reproduces a sign with lights
 *  blinking together. In this example, LEDs are 
 *  all connected by their anodes. First LED on 
 *  output 4 and number of LED = 10.
 *  ----------------------------------------------
 *  Christian Bezanger - October 3 - 2020
 *  Released into the public domain.
 */

#include <LightEffect.h>

// Instanciation - Level HIGH to light up the LED
LightEffect sign_10Lights(4, 10, HIGH);
 
void setup() {
}

void loop() {
  sign_10Lights.onAll();
  delay(500);
  sign_10Lights.offAll();
  delay(500);
}
