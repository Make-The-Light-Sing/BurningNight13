/*
 * ColorChase.h
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#ifndef COLORCHASE_H_
#define COLORCHASE_H_

#include "Generic.h"

class Effect_ColorChase: public Effect_Generic {
    public:
        Effect_ColorChase(T_EffectConfig config);
    protected :
        void _preStep();
        void _postStep();
};

#endif /* COLORCHASE_H_ */
