/*
 * RainbowEffect.h
 *
 *  Created on: 18 févr. 2014
 *      Author: jeckel
 */

//=================================
// include guard
#ifndef RAINBOWEFFECT_H_
#define RAINBOWEFFECT_H_

//=================================
// included dependencies
#include "Effect.h"

//=================================
// the actual class
class RainbowEffect : public Effect {
public:
	RainbowEffect(T_Effect_Config *config) : Effect(config) { step_loop = 384; };
protected:
	void _preStep();
};

#endif /* RAINBOWEFFECT_H_ */
