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
        virtual void _preStep() { config.leds[step_index] = CWhite; };
        virtual void _postStep() { memset(config.leds, 0x00, config.length * sizeof(CRGB)); };
        virtual void _endLoop() {};
};

class SegmentCollection {
    protected:
        unsigned int size = 0;
        Segment** collection;

    public:
        SegmentCollection() { collection = (Segment**) malloc(0); };
        void addSegment(Segment *seg) {
            size++;
            collection = (Segment**) realloc(collection, size * sizeof(Segment*));
            collection[size-1] = seg;
        };
        void preStep() {
            for (unsigned int i; i < size; i++) {
                collection[i]->preStep();
            }
        };
        void postStep() {
            for (unsigned int i; i < size; i++) {
                collection[i]->postStep();
            }
        };
        virtual ~SegmentCollection() {};
};

#endif /* SEGMENT_H_ */
