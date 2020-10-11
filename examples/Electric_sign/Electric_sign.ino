/*  Electric_sign.ino
 *  ------------------------------------------------------  
 *  Example to create an electric sign HOTEL (5 letters)
 *  and an electric sign PARK (4 letters) with the library
 *  LightEffect and a UNO board. In this example, LEDs are
 *  all connected by their anodes to digital output of the 
 *  board or microcontroller. First LED of HOTEL on
 *  digital output 4 and number of LED = 5. First LED of
 *  PARK on digital output 9 and number of LED = 4.
 *  ------------------------------------------------------
 *  In this example, the sign HOTEL is a real light 
 *  animation while the sign PARK is only blinking (from 1
 *  to 3 times).
 *  ------------------------------------------------------
 *  Christian Bezanger - October 3 - 2020
 *  Released into the public domain
 */
 
#include <LightEffect.h>

// Instanciation - Level HIGH to light up the LED
LightEffect sign_HOTEL(4,5, HIGH);
LightEffect sign_PARK(9,4, HIGH);

void setup() {
}

void loop() {
  sign_HOTEL.shiftStopLeft();
  sign_PARK.blinkAll(1);
  sign_HOTEL.blinkAll(3);
  sign_PARK.blinkAll(2);
  sign_HOTEL.offRight();
  sign_PARK.blinkAll(3);
}
