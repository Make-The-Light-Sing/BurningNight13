/*
 * Segment.h
 *
 *  Created on: 3 avr. 2014
 *      Author: jeckel
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include <Color.h>

/**
 * Define the effect configuration structure
 */
typedef struct T_Segment_Config {
    CRGB*         leds;
    uint16_t      length;
};

class Segment {
    protected:
        T_Segment_Config config;
        uint16_t         step_loop    = 0;
        uint16_t         step_index   = 0;

    public:
        Segment() {};
        Segment(T_Segment_Config config) : config(config), step_loop(config.length) {};
        void preStep();
        void postStep();
        virtual ~Segment() {};
    protected:
        virtual void _preStep();
        virtual void _postStep();
        virtual void _endLoop() {};
};

class SegmentCollection {
    protected:
        unsigned int size = 0;
        Segment** collection;

    public:
        SegmentCollection();
        void addSegment(Segment *seg);
        void preStep();
        void postStep();
        virtual ~SegmentCollection() {};
};

#endif /* SEGMENT_H_ */
