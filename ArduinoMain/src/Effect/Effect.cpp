#include "Effect.h"

/**
 * Start of step
 */
void Effect::preStep()
{
	_preStep();
}


/**
 * End of step
 */
void Effect::postStep() {
	_postStep();
	step_index ++;
	if (step_index >= step_loop) {
		step_index = 0;
		_endLoop();
	}
}

/**
 * Color chase effect stepper, light up the next pixel
 * @return void
 */
void ColorChaseEffect::_preStep()
{
	config->leds[step_index] = config->color; // red
}

/**
 * Color chase effect after step, fill dark all pixels
 * @return void
 */
void ColorChaseEffect::_postStep() {
	memset(config->leds, 0x00, config->length * sizeof(CRGB));
}

/**
 * Wave effect stepper
 * @return void
 */
void WaveEffect::_preStep() {
	byte y;
	for(int iLed = 0; iLed < config->length; iLed++)
	{
		// y is evolving from 0 to 31
		y = (iLed + step_index) & 0x1f;
		if (y >= 16)
		{
			if (y >= 24) // y in 4th cycle
			{
				config->leds[iLed].color(0xff >> (y - 24), 0xff >> (y - 24), 0xff >> (y - 24));
			}
			else				// y in 3rd cycle
			{
				config->leds[iLed].color(0xff >> (24 - y), 0xff >> (24 - y), 0xff >> (24 - y));
			}
		} else {
			if (y >= 8)		// y in 2nd cycle
			{
				config->leds[iLed].color(config->color.r >> (y - 8), config->color.g >> (y - 8), config->color.b >> (y - 8));
			}
			else				// y in 1st cycle
			{
				config->leds[iLed].color(config->color.r >> (8 - y), config->color.g >> (8 - y), config->color.b >> (8 - y));
			}
		}
	}
}


void PulseEffect::_preStep()
{
	int delta = ((step_index > 64) ? (128 - step_index) : step_index) >> 3;
	for(int iLed = 0; iLed < config->length; iLed++)
	{
		config->leds[iLed].color(config->color.r >> delta, config->color.g >> delta, config->color.b >> delta);
	}
}

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
	}
}
