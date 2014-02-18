/*
 * EffectFactory.h
 *
 *  Created on: 18 févr. 2014
 *      Author: jeckel
 */

//=================================
// include guard
#ifndef EFFECTFACTORY_H_
#define EFFECTFACTORY_H_

//=================================
// included dependencies
#include "PulseEffect.h"
#include "WaveEffect.h"
#include "ColorChaseEffect.h"
#include "RainbowEffect.h"

//=================================
// the actual class
class EffectFactory {
public:
	Effect* createEffect(T_Effect_Config *config);
};

#endif /* EFFECTFACTORY_H_ */

