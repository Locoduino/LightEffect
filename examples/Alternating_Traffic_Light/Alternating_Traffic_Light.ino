/* Alternating_Traffic_Light.ino
 * ------------------------------------------------
 * Simulate two alternating traffic of a working 
 * zone. Orange LEDs on outputs 4 and 7 (will be 
 * blinking by soft), orange LEDs on outputs 5 and 
 * 8, red LEDs on outputs 6 and 9. 
 * In this example, all LEDs are connected by 
 * cathode. Alternating traffic light sequence is 
 * too long to permit other light effect.
 * ------------------------------------------------
 * Christian Bezanger - October 3 - 2020
 */

#include <LightEffect.h>

// Instanciation - Level HIGH to light up the LED
LightEffect Alternating_Light(4, 6, LOW);

void setup() {
}

void loop() {
Alternating_Light.alternatingTrafficLight();
}
