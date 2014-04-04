/*
 * Abstract.cpp
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#include "Abstract.h"

/**
 * Empty constructor
 */
Effect_Abstract::Effect_Abstract()
{
    /* remove warnings */
    segment = (Segment*) malloc(0);
}

/**
 * Main constructor
 */
Effect_Abstract::Effect_Abstract(T_EffectConfig config)
    : config(config)
{
    /* remove warnings */
    segment = (Segment*) malloc(0);
};

/**
 * Destructor
 */
Effect_Abstract::~Effect_Abstract()
{
}

/**
 * Define segment on which the effect should apply
 */
void Effect_Abstract::setSegment(Segment* s)
{
    segment = s;
    step_loop = segment->config.length;
}

/**
 * Start of step
 */
void Effect_Abstract::preStep()
{
    _preStep();
}


/**
 * End of step
 */
void Effect_Abstract::postStep() {
    _postStep();
    step_index ++;
    if (step_index >= step_loop) {
        step_index = 0;
        _endLoop();
    }
}

/**
 * Redefine color
 */
void Effect_Abstract::setColor(CRGB color)
{
    config.color = color;
}

/**
 * Overridable pre-step actions
 */
void Effect_Abstract::_preStep()
{
    if (config.direction == DOWN) {
        segment->config.leds[segment->config.length - step_index - 1] = config.color;
    } else {
        segment->config.leds[step_index] = config.color;
    }
    //segment->config.leds[step_index] = config.color;
}

/**
 * Overridable post-step actions
 */
void Effect_Abstract::_postStep()
{
    memset(segment->config.leds, 0x00, segment->config.length * sizeof(CRGB));
}

