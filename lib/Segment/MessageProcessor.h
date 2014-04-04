/*
 * MessageProcessor.h
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#ifndef MESSAGEPROCESSOR_H_
#define MESSAGEPROCESSOR_H_

#include "Segment.h"

#define CMD_SET_SEGMENT_COLOR 1


class SegmentCollection;

class MessageProcessor {
        /* properties */
    protected:
        SegmentCollection* segments;

        /* methods */
    public:
        MessageProcessor(SegmentCollection* segments) : segments(segments) {};
        void processMessage(byte* message);
};

#endif /* MESSAGEPROCESSOR_H_ */
