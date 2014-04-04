/*
 * Rainbow.h
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#ifndef RAINBOW_H_
#define RAINBOW_H_

#include "Generic.h"

class Effect_Rainbow: public Effect_Generic {
        /* methods */
    public:
        Effect_Rainbow(T_EffectConfig config);
        void init();
    protected:
        void _preStep();
};

#endif /* RAINBOW_H_ */
