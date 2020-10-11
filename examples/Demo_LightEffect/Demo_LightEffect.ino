/*  Demo_LightEffect.ino
 *  -----------------------------------------------------------  
 *  Example to show the different possibilities of the 
 *  library LightEffect with a 10 LED sign and a UNO board.
 *  In this example, LEDs are all connected by their anodes
 *  to digital output of the board or microcontroller. 
 *  First LED of the sign on digital output 4 and number of LED 
 *  = 10. 
 *  -----------------------------------------------------------
 *  Christian Bezanger - October 3 - 2020
 *  Released into the public domain
 */
 
#include <LightEffect.h>

// Instanciation - Level HIGH to light up the LED
LightEffect sign_10LED(4,10, HIGH);

void setup() {
}

void loop() {
  sign_10LED.onAll();
  delay(1000);
  sign_10LED.offAll();
  delay(1000);
  sign_10LED.onLeft();
  delay(1000);
  sign_10LED.offLeft();
  delay(1000);
  sign_10LED.onRight();
  delay(1000);
  sign_10LED.offRight();
  delay(1000);
  sign_10LED.blinkAll(3);
  delay(1000);
  sign_10LED.offAll();
  delay(1000);
  sign_10LED.movingFlashLeft();
  delay(1000);
  sign_10LED.movingFlashRight();
  delay(1000);
  sign_10LED.roundTrip();
  delay(1000);
  sign_10LED.shiftStopLeft();
  delay(1000);
  sign_10LED.offAll();
  delay(1000);
  sign_10LED.shiftStopRight();
  delay(1000);
  sign_10LED.offAll();
  delay(1000);
  sign_10LED.randomLightOn();
  delay(1000);
  sign_10LED.randomLightOff();
  delay(3000);
}
