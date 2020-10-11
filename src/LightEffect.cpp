/* LightEffect.cpp
   -------------------------------------------------
   Librarie version 1.0.0  to create light animation
   for shops - All LEDs must be connected by anode
   (or by cathode, no mixing possible) to the board 
   or microcontroller digital outputs.
   Created by Christian Bezanger. October 3. 2020
   Modified October 3. 2020
*/

#include "Arduino.h"
#include "LightEffect.h"

LightEffect::LightEffect(int led1, int nbrLed, int valON)
{
	_led1 = led1;
	_nbrLed = nbrLed;
	_valON = valON;
	if (_valON == HIGH) {_valOFF = LOW;}
	if (_valON == LOW) {_valOFF = HIGH;}

	// OUTPUT for all the LEDs
	for (byte i = 0; i <= (_nbrLed - 1) ; i++)      // Minus 1 because we start from zero
    {
		pinMode ((i + _led1), OUTPUT) ;
	}
    // Turn off the LEDs to begin
	for (byte i = 0 ; i <= (_nbrLed - 1) ; i++) 
	{
		digitalWrite ((i + _led1), _valOFF) ; 
	}
}

void LightEffect::onAll()
{
	for (byte i = _led1 ; i <= (_led1 + _nbrLed - 1) ; i++)
	{
		digitalWrite (i, _valON);
	}
}

void LightEffect::onLeft()
{
	for (byte i = _led1 ; i <= (_led1 + _nbrLed -1) ; i++) 
  {
    digitalWrite (i, _valON) ;
    delay (100);
  }
}

void LightEffect::onRight()
{
	for (byte i = (_led1 + _nbrLed - 1) ; i >= _led1 ; i--) 
  {
    digitalWrite (i, _valON) ;
    delay (100);
  }
}

void LightEffect::offAll()
{
	for (byte j = _led1 ; j <= (_led1 + _nbrLed - 1) ; j++)
	{
		digitalWrite (j, _valOFF);
	}
}

void LightEffect::offLeft()
{
	for (byte i = _led1 ; i <= (_led1 + _nbrLed -1) ; i++) 
  {
    digitalWrite (i, _valOFF) ;
    delay (100);
  }
}

void LightEffect::offRight()
{
	for (byte i = (_led1 + _nbrLed - 1) ; i >= _led1 ; i--) 
  {
    digitalWrite (i, _valOFF) ;
    delay (100);
  }
}

void LightEffect::blinkAll(int nbrBlink)
{
	_nbrBlink = nbrBlink;
	for (byte j = 1 ; j <= _nbrBlink ; j++) 
  {
    for (byte k = 0 ; k <= (_nbrLed - 1) ; k++) 
    {
      digitalWrite ((k + _led1) , _valOFF) ;
    }
    delay (300) ;
    for (byte l = 0 ; l <= (_nbrLed - 1) ; l++) 
    {
      digitalWrite ((l + _led1), _valON) ;
    }
    delay (500) ;
  }
}

void LightEffect::movingFlashLeft()
{
	for (byte m = _led1 ; m <= (_led1 + _nbrLed - 1) ; m++)
	{
		digitalWrite (m, _valON);
		delay(100);
		digitalWrite (m, _valOFF);
	}
	delay(300);
}	

void LightEffect::movingFlashRight()
{
	for (byte m = (_led1 + _nbrLed - 1) ; m >= (_led1) ; m--)
	{
		digitalWrite (m, _valON);
		delay(100);
		digitalWrite (m, _valOFF);
	}
	delay(300);
}

void LightEffect::roundTrip()
{
	for (int j = _led1 + 1 ; j <= _led1 + _nbrLed - 2 ; j++)
	  {
		digitalWrite (j, _valON); 
		// false PWM freq = 20 kHz Rcycl = 1/50
		for (int k = 1 ; k <= 1800 ; k++)
		{
		  digitalWrite (j - 1, _valON);
		  digitalWrite (j + 1, _valON);
		  delayMicroseconds(1);
		  digitalWrite (j - 1, _valOFF);
		  digitalWrite (j + 1, _valOFF);
		  delayMicroseconds(49);
		}
		digitalWrite (j, _valOFF);
	  }
    for (int j = _led1 + _nbrLed - 2 ; j >= _led1 + 1 ; j--)
	  {
		digitalWrite (j, _valON);
		// false PWM freq = 20 kHz Rcycl = 1/50
		for (int k = 1 ; k <= 1800 ; k++)
		{
		  digitalWrite (j - 1, _valON);
		  digitalWrite (j + 1, _valON);
		  delayMicroseconds(1);
		  digitalWrite (j - 1, _valOFF);
		  digitalWrite (j + 1, _valOFF);
		  delayMicroseconds(49);
		}
		digitalWrite (j, _valOFF);
	  }
}

void LightEffect::shiftStopLeft()
{
	for (byte n = 0 ; n <= (_nbrLed - 1) ; n++)
  {
    for (byte i = _led1 ; i <= ((_led1 + _nbrLed - 1)-n) ; i++)
    {
      digitalWrite (i, _valON) ;  
      delay (100) ;              
      digitalWrite (i, _valOFF) ; 
    }
    digitalWrite ( ((_led1 + _nbrLed - 1) - n) , _valON ) ; // last LED lit
  }
}

void LightEffect::shiftStopRight()
{
	for (byte n = 0 ; n <= (_nbrLed - 1) ; n++)
  {
    for (byte i = (_led1 + _nbrLed - 1) ; i >= (_led1 + n) ; i--)
    {
      digitalWrite (i, _valON) ;  
      delay (100) ;  
      digitalWrite (i, _valOFF) ;  
    }
    digitalWrite ((_led1 + n) , _valON ) ; // last LED lit
  }
}

void LightEffect::randomLightOn()
{
	randomSeed(analogRead(A5));	// A5 must not be used as digital output
	int somme = 0;
	int tableDone[_nbrLed];
	for (int k = 0 ; k <= (_nbrLed - 1) ; k++)
	{
		digitalWrite ((k + _led1), _valOFF);
	}
	for (int i = 0 ; i <= _nbrLed - 1 ; i++)
	{
		tableDone [i] = 0;
	}
	do
	{
		int index = random (0, _nbrLed);	// index between 0 and _NbrLed - 1
		digitalWrite(index + _led1, _valON);
		tableDone[index] = 1;
		somme = 0;
		delay(150);
		for (int j = 0 ; j <= _nbrLed - 1 ; j++)
		{
		  somme = somme + tableDone[j];
		}
	} while (somme < _nbrLed);
}

void LightEffect::randomLightOff()
{
	randomSeed(analogRead(A5));	// A5 must not be used as digital output
	int somme = 0;
	int tableDone[_nbrLed];
	for (int k = 0 ; k <= (_nbrLed - 1) ; k++)
	{
		digitalWrite ((k + _led1), _valON);
	}
	for (int i = 0 ; i <= _nbrLed - 1 ; i++)
	{
		tableDone [i] = 0;
	}
	do
	{
		int index = random (0, _nbrLed);	// index between 0 and _NbrLed - 1
		digitalWrite(index + _led1, _valOFF);
		tableDone[index] = 1;
		somme = 0;
		delay(150);
		for (int j = 0 ; j <= _nbrLed - 1 ; j++)
		{
		  somme = somme + tableDone[j];
		}
	} while (somme < _nbrLed);
}

void LightEffect::trafficLight()
{
	int greenTL1 = _led1;
	int orangeTL1 = _led1 + 1;
	int redTL1 = _led1 + 2;
	int greenTL2 = _led1 + 3;
	int orangeTL2 = _led1 + 4;
	int redTL2 = _led1 + 5;
	digitalWrite (greenTL1, _valON);
	digitalWrite (redTL2, _valON);
	delay(10000);
	digitalWrite (greenTL1, _valOFF);
	digitalWrite (orangeTL1, _valON);
	delay(3000);
	digitalWrite (orangeTL1, _valOFF);
	digitalWrite (redTL1, _valON);
	delay(2000);
	digitalWrite (redTL2, _valOFF);
	digitalWrite (greenTL2, _valON);
	delay(10000);
	digitalWrite (greenTL2, _valOFF);
	digitalWrite (orangeTL2, _valON);
	delay(3000);
	digitalWrite (orangeTL2, _valOFF);
	digitalWrite (redTL2, _valON);
	delay(2000);
	digitalWrite (redTL1, _valOFF);
}

void LightEffect::alternatingTrafficLight()
{
	int greenTL1 = _led1;	// blinking orange in fact
	int orangeTL1 = _led1 + 1;
	int redTL1 = _led1 + 2;
	int greenTL2 = _led1 + 3;	// blinking orange in fact
	int orangeTL2 = _led1 + 4;
	int redTL2 = _led1 + 5;
	digitalWrite (greenTL1, _valON);
	digitalWrite (redTL2, _valON);
	delay(500);
	for (int i = 1 ; i <= 5; i++)
	{
		digitalWrite (greenTL1, _valOFF);
		delay(1000);
		digitalWrite (greenTL1, _valON);
		delay(1000);
	}
	digitalWrite (greenTL1, _valOFF);
	digitalWrite (orangeTL1, _valON);
	delay(3000);
	digitalWrite (orangeTL1, _valOFF);
	digitalWrite (redTL1, _valON);
	delay(8000);
	digitalWrite (redTL2, _valOFF);
	digitalWrite (greenTL2, _valON);
	delay(500);
	for (int i = 1 ; i <= 5; i++)
	{
		digitalWrite (greenTL2, _valOFF);
		delay(1000);
		digitalWrite (greenTL2, _valON);
		delay(1000);
	}
	digitalWrite (greenTL2, _valOFF);
	digitalWrite (orangeTL2, _valON);
	delay(3000);
	digitalWrite (orangeTL2, _valOFF);
	digitalWrite (redTL2, _valON);
	delay(8000);
	digitalWrite (redTL1, _valOFF);
}

	
