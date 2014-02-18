/*
 * PulseEffect.cpp
 *
 *  Created on: 18 févr. 2014
 *      Author: jeckel
 */

#include "PulseEffect.h"


/**
 * Pulse effect step
 */
void PulseEffect::_preStep()
{
	int delta = ((step_index > 64) ? (128 - step_index) : step_index) >> 3;
	for(int iLed = 0; iLed < config->length; iLed++)
	{
		config->leds[iLed].color(config->color.r >> delta, config->color.g >> delta, config->color.b >> delta);
	}
}
