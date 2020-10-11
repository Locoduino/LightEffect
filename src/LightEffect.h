/* LightEffect.h
   -------------------------------------------------
   Librarie version 1.0.0  to create light animation
   for shops - All LEDs must be connected by anode 
   (or by cathode, no mixing possible) to yhe board
   or microcontroller digital outputs.
   Created by Christian Bezanger. October 3. 2020
   Modified October 3. 2020
*/

#ifndef LightEffect_h
#define LightEffect_h

#include "Arduino.h"

class LightEffect
{
	public:
	LightEffect(int led1, int nbrLed, int valON);
	void onAll();
	void onLeft();
	void onRight();
	void offAll();
	void offLeft();
	void offRight();
	void blinkAll(int nbrBlink);
	void movingFlashLeft();
	void movingFlashRight();
	void roundTrip();
	void shiftStopLeft();
	void shiftStopRight();
	void randomLightOn();
	void randomLightOff();
	void trafficLight();
	void alternatingTrafficLight();
	private:
	int _led1;
	int _nbrLed;
	int _nbrBlink;
	int _valON;
	int _valOFF;
	int greenTL1;
	int orangeTL1;
	int redTL1;
	int greenTL2;
	int orangeTL2;
	int redTL2;
};

#endif
