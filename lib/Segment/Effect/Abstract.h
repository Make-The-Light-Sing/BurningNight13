/*
 * Abstract.h
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#ifndef ABSTRACT_H_
#define ABSTRACT_H_

#include <Color.h>
#include "../Segment.h"

/**
 * Define type for effect direction
 */
typedef enum E_Direction {
    UP   = 0,
    DOWN = 1
};

/**
 * Define the effect configuration structure
 */
typedef struct T_EffectConfig {
    CRGB        color;
    E_Direction direction;
};

/**
 * Simple declaration for cross includes
 */
class Segment;

class Effect_Abstract {
        /* properties */
    protected :
        T_EffectConfig  config;
        Segment*        segment;
        uint16_t        step_index = 0;
        uint16_t        step_loop    = 0;

        /* methods */
    public:
        Effect_Abstract();
        Effect_Abstract(T_EffectConfig config);
        virtual ~Effect_Abstract();
        void setSegment(Segment* s);
        void preStep();
        void postStep();
        void setColor(CRGB color);
    protected :
        virtual void _preStep();
        virtual void _postStep();
        virtual void _endLoop() {};

};

#endif /* ABSTRACT_H_ */
