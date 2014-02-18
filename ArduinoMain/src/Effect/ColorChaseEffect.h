/*
 * ColorChaseEffect.h
 *
 *  Created on: 18 févr. 2014
 *      Author: jeckel
 */

//=================================
// include guard
#ifndef COLORCHASEEFFECT_H_
#define COLORCHASEEFFECT_H_

//=================================
// included dependencies
#include "Effect.h"

//=================================
// the actual class
class ColorChaseEffect : public Effect {
	public :
		ColorChaseEffect(T_Effect_Config *config) : Effect(config) {};
	protected:
		void _preStep();
		void _postStep();
};

#endif /* COLORCHASEEFFECT_H_ */
