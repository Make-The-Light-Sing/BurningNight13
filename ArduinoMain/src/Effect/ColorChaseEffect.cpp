/*
 * ColorChaseEffect.cpp
 *
 *  Created on: 18 févr. 2014
 *      Author: jeckel
 */

#include "ColorChaseEffect.h"


/**
 * Color chase effect stepper, light up the next pixel
 * @return void
 */
void ColorChaseEffect::_preStep()
{
	if (config->reverse) {
		config->leds[config->length - step_index - 1] = config->color;
	} else {
		config->leds[step_index] = config->color;
	}
}

/**
 * Color chase effect after step, fill dark all pixels
 * @return void
 */
void ColorChaseEffect::_postStep()
{
	memset(config->leds, 0x00, config->length * sizeof(CRGB));
}


