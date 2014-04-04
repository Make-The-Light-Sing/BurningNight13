/*
 * Rainbow.cpp
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#include "Rainbow.h"

/**
 * Constructor
 */
Effect_Rainbow::Effect_Rainbow(T_EffectConfig config)
    : Effect_Generic(config)
{
}

/**
 * Init effect with fixed loop size
 */
void Effect_Rainbow::init()
{
    step_loop = 384;
}   // init

/**
 * Rainbow step
 */
void Effect_Rainbow::_preStep()
{
    for(int iLed = 0; iLed < segment->config.length; iLed++)
    {
        // tricky math! we use each pixel as a fraction of the full 384-color
        // wheel (thats the i / strip.numPixels() part)
        // Then add in j which makes the colors go around per pixel
        // the % 384 is to make the wheel cycle around
        if (config.direction == DOWN) {
            segment->config.leds[iLed].Wheel(((iLed * 384 / segment->config.length) + step_index) % 384);
        } else {
            segment->config.leds[segment->config.length - iLed - 1].Wheel(((iLed * 384 / segment->config.length) + step_index) % 384);
        }
    }
}
