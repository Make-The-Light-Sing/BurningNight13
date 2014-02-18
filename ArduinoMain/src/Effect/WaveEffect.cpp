/*
 * WaveEffect.cpp
 *
 *  Created on: 18 févr. 2014
 *      Author: jeckel
 */
#include "WaveEffect.h"

/**
 * Wave effect stepper
 * @return void
 */
void WaveEffect::_preStep() {
	byte y;
	for(int iLed = 0; iLed < config->length; iLed++)
	{
		// y is evolving from 0 to 31
		if (config->reverse) {
			y = (iLed + step_index) & 0x1f;
		} else {
			y = (iLed - step_index) & 0x1f;
		}
		if (y >= 16)
		{
			if (y >= 24) // y in 4th cycle
			{
				config->leds[iLed].color(0xff >> (y - 24), 0xff >> (y - 24), 0xff >> (y - 24));
			}
			else				// y in 3rd cycle
			{
				config->leds[iLed].color(0xff >> (24 - y), 0xff >> (24 - y), 0xff >> (24 - y));
			}
		} else {
			if (y >= 8)		// y in 2nd cycle
			{
				config->leds[iLed].color(config->color.r >> (y - 8), config->color.g >> (y - 8), config->color.b >> (y - 8));
			}
			else				// y in 1st cycle
			{
				config->leds[iLed].color(config->color.r >> (8 - y), config->color.g >> (8 - y), config->color.b >> (8 - y));
			}
		}
	}
}
