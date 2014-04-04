/*
 * Pulse.cpp
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#include "Pulse.h"

/**
 * Init pulse effect with fixed loop size
 */
void Effect_Pulse::init()
{
    step_loop = 128;
}   // init

/**
 * Pulse effect step
 */
void Effect_Pulse::_preStep()
{
    unsigned char delta = ((step_index > 64) ? (128 - step_index) : step_index) >> 3;
    for(unsigned int iLed = 0; iLed < segment->config.length; iLed++)
    {
        segment->config.leds[iLed].color(config.color.r >> delta, config.color.g >> delta, config.color.b >> delta);
    }
}
