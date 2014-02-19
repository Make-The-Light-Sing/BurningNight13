/*
 * FireEffect.cpp
 *
 *  Created on: 18 févr. 2014
 *      Author: jeckel
 */

#include "FireEffect.h"

/**
 * Constructor
 */
FireEffect::FireEffect(T_Effect_Config *config)
		: Effect(config)
{
	fire = (byte *) malloc(config->length);
	memset(fire, 0, config->length);
};

/**
 * Step for fire effect
 */
void FireEffect::_preStep()
{
    //byte fire[FOOT_NB_STRIP][FOOT_STRIP_LENGTH];
    //memset(fire, 0, NUM_LEDS);

	fire[0] = random(255);
	for(int y = (config->length - 1); y > 0; y--)
	{
		fire[y] = ((fire[y - 1] + fire[(y - 2) % config->length]) * (config->length / 2)) / (config->length * 1.045);
	}
	for(int iLed=0; iLed < config->length; iLed++)
	{
		if (config->reverse) {
			config->leds[config->length - iLed - 1].fireColor(fire[iLed]);
		} else {
			config->leds[iLed].fireColor(fire[iLed]);
		}
	}
}
