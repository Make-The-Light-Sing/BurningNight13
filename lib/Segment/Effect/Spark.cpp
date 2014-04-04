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
    segment->config.leds[random(segment->config.length)] = config.color;
}
