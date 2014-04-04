/*
 * Fire.cpp
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#include "Fire.h"

Effect_Fire::Effect_Fire(T_EffectConfig config)
    : Effect_Generic(config)
{
    // remove warning
    fire = (unsigned char *) malloc(0);
}

void Effect_Fire::init()
{
    fire = (unsigned char *) calloc(segment->config.length, sizeof(unsigned char));
    //memset(fire, 0, segment->config.length);
}

/**
 * Step for fire effect
 */
void Effect_Fire::_preStep()
{
    fire[0] = random(255);
    for(int y = (segment->config.length - 1); y > 0; y--)
    {
        fire[y] = ((fire[y - 1] + fire[(y - 2) % segment->config.length]) * (segment->config.length / 2)) / (segment->config.length * 1.045);
    }
    for(int iLed=0; iLed < segment->config.length; iLed++)
    {
        if (config.direction == DOWN) {
            segment->config.leds[segment->config.length - iLed - 1].fireColor(fire[iLed]);
        } else {
            segment->config.leds[iLed].fireColor(fire[iLed]);
        }
    }
}
