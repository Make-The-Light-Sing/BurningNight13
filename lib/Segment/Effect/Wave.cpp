/*
 * Wave.cpp
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#include "Wave.h"

Effect_Wave::Effect_Wave(T_EffectConfig config)
    : Effect_Generic(config)
{
}

void Effect_Wave::init()
{
    step_loop = 32;
}

/**
 * Wave effect stepper
 * @return void
 */
void Effect_Wave::_preStep() {
    unsigned char y;
    for(unsigned int iLed = 0; iLed < segment->config.length; iLed++)
    {
        // y is evolving from 0 to 31
        if (config.direction == DOWN) {
            y = (iLed + step_index) & 0x1f;
        } else {
            y = (iLed - step_index) & 0x1f;
        }
        if (y >= 16)
        {
            if (y >= 24) // y in 4th cycle
            {
                segment->config.leds[iLed].color(0xff >> (y - 24), 0xff >> (y - 24), 0xff >> (y - 24));
            }
            else                // y in 3rd cycle
            {
                segment->config.leds[iLed].color(0xff >> (24 - y), 0xff >> (24 - y), 0xff >> (24 - y));
            }
        } else {
            if (y >= 8)     // y in 2nd cycle
            {
                segment->config.leds[iLed].color(config.color.r >> (y - 8), config.color.g >> (y - 8), config.color.b >> (y - 8));
            }
            else                // y in 1st cycle
            {
                segment->config.leds[iLed].color(config.color.r >> (8 - y), config.color.g >> (8 - y), config.color.b >> (8 - y));
            }
        }
    }
}
