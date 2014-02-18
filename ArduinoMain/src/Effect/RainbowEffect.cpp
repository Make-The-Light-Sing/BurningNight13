/*
 * RainbowEffect.cpp
 *
 *  Created on: 18 févr. 2014
 *      Author: jeckel
 */

#include "RainbowEffect.h"

void RainbowEffect::_preStep()
{
	for(int iLed = 0; iLed < config->length; iLed++)
	{
		// tricky math! we use each pixel as a fraction of the full 384-color
		// wheel (thats the i / strip.numPixels() part)
		// Then add in j which makes the colors go around per pixel
		// the % 384 is to make the wheel cycle around
		config->leds[iLed].Wheel(((iLed * 384 / config->length) + step_index) % 384);
	}
}
