/*
 * PulseEffect.h
 *
 *  Created on: 18 févr. 2014
 *      Author: jeckel
 */

//=================================
// include guard
#ifndef PULSEEFFECT_H_
#define PULSEEFFECT_H_

//=================================
// included dependencies
#include "Effect.h"

//=================================
// the actual class
class PulseEffect : public Effect {
	public:
		PulseEffect(T_Effect_Config *config) : Effect(config) { step_loop = 128; };
	protected:
		void _preStep();
};

#endif /* PULSEEFFECT_H_ */
