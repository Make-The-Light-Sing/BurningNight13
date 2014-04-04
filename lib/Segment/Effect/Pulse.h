/*
 * Pulse.h
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#ifndef PULSE_H_
#define PULSE_H_

#include "Generic.h"

class Effect_Pulse : public Effect_Generic {
    public:
        Effect_Pulse(T_EffectConfig config) : Effect_Generic(config) {};
    protected:
        void _preStep();
};

#endif /* PULSE_H_ */
