/*
 * Wave.h
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#ifndef WAVE_H_
#define WAVE_H_

#include "Generic.h"

class Effect_Wave: public Effect_Generic {
        /* methods */
    public:
        Effect_Wave(T_EffectConfig config);
        void init();
    protected:
        void _preStep();
};

#endif /* WAVE_H_ */
