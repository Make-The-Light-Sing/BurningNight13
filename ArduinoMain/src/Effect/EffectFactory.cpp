/*
 * EffectFactory.cpp
 *
 *  Created on: 18 févr. 2014
 *      Author: jeckel
 */
#include "EffectFactory.h"

/**
 * Effect factory from config struct
 * @return Effect* Pointer to the new builded effect object
 */
Effect* EffectFactory::createEffect(T_Effect_Config *config) {
	switch(config->effect) {
		case Color_Chase : {
			return new ColorChaseEffect(config);
			break;
		}
		case Wave : {
			return new WaveEffect(config);
			break;
		}
		case Pulse : {
			return new PulseEffect(config);
			break;
		}
		case Rainbow : {
			return new RainbowEffect(config);
			break;
		}
	}
}
