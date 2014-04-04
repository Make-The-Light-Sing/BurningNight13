/*
 * Spark.cpp
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#include "Spark.h"

/**
 * Constructor
 */
Effect_Spark::Effect_Spark(T_EffectConfig config)
    : Effect_Generic(config)
{
}

/**
 * Step for spark effect
 */
void Effect_Spark::_preStep()
{
    position = random(segment->config.length);
    last_color = segment->config.leds[position];
    segment->config.leds[position] = config.color;
}   // _preStep

void Effect_Spark::_postStep()
{
    segment->config.leds[position] = last_color;
}   // _postStep
