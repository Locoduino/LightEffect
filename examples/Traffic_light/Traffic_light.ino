/* Traffic_light.ino
 * ------------------------------------------------
 * Simulate two traffic lights of a crossing. Green
 * LEDs on outputs 4 and 7, orange LEDs on outputs 
 * 5 and 8, red LEDs on outputs 6 and 9. In this 
 * example, all LEDs are connected by anode.
 * Traffic Light sequence is too long to permit
 * other light effect.
 * ------------------------------------------------
 * Christian Bezanger - October 3 - 2020
 * Released in the public domain
 */

#include <LightEffect.h>

// Instanciation - Level HIGH to light up the LED
LightEffect Traffic_Light(4, 6, HIGH);

void setup() {
}

void loop() {
Traffic_Light.trafficLight();
}
