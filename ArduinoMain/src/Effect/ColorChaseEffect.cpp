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
	config->leds[step_index] = config->color; // red
}

/**
 * Color chase effect after step, fill dark all pixels
 * @return void
 */
void ColorChaseEffect::_postStep() {
	memset(config->leds, 0x00, config->length * sizeof(CRGB));
}


