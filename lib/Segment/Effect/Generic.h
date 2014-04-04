/*
 * Generic.h
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#ifndef GENERIC_H_
#define GENERIC_H_

#include <Color.h>
#include "../Types.h"
#include "../Segment.h"

class Segment;

class Effect_Generic {
        /* properties */
    protected :
        T_EffectConfig  config;
        Segment*        segment;
        uint16_t        step_index = 0;
        uint16_t        step_loop    = 0;

        /* methods */
    public:
        Effect_Generic();
        Effect_Generic(T_EffectConfig config);
        virtual ~Effect_Generic();
        void setSegment(Segment* s);
        void preStep();
        void postStep();
        void setColor(CRGB color);
    protected :
        virtual void _preStep() {};
        virtual void _postStep() {};
        virtual void _endLoop() {};
};

class Effect_Factory {
        /* methods */
    public:
        Effect_Generic* createEffect(T_EffectConfig config);
};

#endif /* GENERIC_H_ */
