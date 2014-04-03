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
}   // preStep

/**
 * End of step
 */
void Segment::postStep()
{
    _postStep();
    step_index ++;
    if (step_index >= step_loop) {
        step_index = 0;
        _endLoop();
    }
}   // postStep

/**
 * Default pre-step
 */
void Segment::_preStep()
{
    config.leds[step_index] = CWhite;
};

/**
 * Default post-step
 */
void Segment::_postStep()
{
    memset(config.leds, 0x00, config.length * sizeof(CRGB));
};

/**
 * Default constructor
 */
SegmentCollection::SegmentCollection()
{
    collection = (Segment**) malloc(0);
}   // SegmentCollection

/**
 * Add new segment to collection
 *
 * @param Segment*
 */
void SegmentCollection::addSegment(Segment *seg)
{
    size++;
    collection = (Segment**) realloc(collection, size * sizeof(Segment*));
    collection[size-1] = seg;
}   // addSegment

/**
 * Do pre-action on each segments
 */
void SegmentCollection::preStep()
{
    for (unsigned int i; i < size; i++) {
        collection[i]->preStep();
    }
}   // preStep

/**
 * Do post-action on each segments
 */
void SegmentCollection::postStep()
{
    for (unsigned int i; i < size; i++) {
        collection[i]->postStep();
    }
}   // postStep
