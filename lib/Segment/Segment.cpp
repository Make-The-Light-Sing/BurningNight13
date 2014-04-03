/*
 * Segment.cpp
 *
 *  Created on: 3 avr. 2014
 *      Author: jeckel
 */

#include "Segment.h"


/**
 * Start of step
 */
void Segment::preStep()
{
    _preStep();
}


/**
 * End of step
 */
void Segment::postStep() {
    _postStep();
    step_index ++;
    if (step_index >= step_loop) {
        step_index = 0;
        _endLoop();
    }
}
