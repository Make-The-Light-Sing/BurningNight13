/*
 * FireEffect.h
 *
 *  Created on: 18 févr. 2014
 *      Author: jeckel
 */

//=================================
// include guard
#ifndef FIREEFFECT_H_
#define FIREEFFECT_H_

//=================================
// included dependencies
#include "Effect.h"

//=================================
// the actual class
class FireEffect : public Effect {
public:
	FireEffect(T_Effect_Config *config);
protected:
	void _preStep();
private:
	byte *fire;
};

#endif /* FIREEFFECT_H_ */
