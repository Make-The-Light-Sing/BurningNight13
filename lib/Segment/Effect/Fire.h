/*
 * Fire.h
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#ifndef FIRE_H_
#define FIRE_H_

#include "Generic.h"

class Effect_Fire: public Effect_Generic {
        /* properties */
    private:
        unsigned char *fire;

        /* methods */
    public:
        Effect_Fire(T_EffectConfig config);
        void init();
    protected:
        void _preStep();
};

#endif /* FIRE_H_ */
