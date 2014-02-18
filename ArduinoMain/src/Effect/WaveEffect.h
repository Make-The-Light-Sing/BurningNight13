/*
 * WaveEffect.h
 *
 *  Created on: 18 févr. 2014
 *      Author: jeckel
 */

//=================================
// include guard
#ifndef WAVEEFFECT_H_
#define WAVEEFFECT_H_

//=================================
// forward declared dependencies

//=================================
// included dependencies
#include "Effect.h"

//=================================
// the actual class
class WaveEffect : public Effect {
	public:
		WaveEffect(T_Effect_Config *config) : Effect(config) { step_loop = 32; };
	protected:
		void _preStep();
};
#endif /* WAVEEFFECT_H_ */
