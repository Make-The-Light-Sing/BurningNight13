/*
 * Segment.h
 *
 *  Created on: 3 avr. 2014
 *      Author: jeckel
 */

#ifndef SEGMENT_H_
#define SEGMENT_H_

#include <Color.h>
#include "Effect/Abstract.h"

/**
 * Define the effect configuration structure
 */
typedef struct T_SegmentConfig {
    CRGB*         leds;
    uint16_t      length;
};

typedef unsigned char boolean;

class Effect_Abstract;

class Segment {
        /* properties */
    public:
        T_SegmentConfig config;
    protected:
        uint16_t         step_loop    = 0;
        uint16_t         step_index   = 0;
        Effect_Abstract* effect;
        boolean          has_effect = false;

        /* methods */
    public:
        Segment() { /* remove warnings */ effect = (Effect_Abstract*) malloc(0); };
        Segment(T_SegmentConfig config) : config(config), step_loop(config.length) { /* remove warnings */ effect = (Effect_Abstract*) malloc(0); };
        Segment(T_SegmentConfig config, Effect_Abstract* effect);
        void setEffect(Effect_Abstract* eff);
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
        Segment* getSegment(unsigned int i);
        void preStep();
        void postStep();
        virtual ~SegmentCollection() {};
};

#endif /* SEGMENT_H_ */
