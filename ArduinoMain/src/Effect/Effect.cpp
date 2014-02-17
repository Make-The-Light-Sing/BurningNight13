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
	leds[step_index] = color; // red
}

/**
 * Color chase effect after step, fill dark all pixels
 * @return void
 */
void ColorChaseEffect::_postStep() {
	memset(leds, 0x00, strip_length * sizeof(CRGB));
}

/**
 * Wave effect stepper
 * @return void
 */
void WaveEffect::_preStep() {
	byte y;
	for(int iLed = 0; iLed < strip_length; iLed++)
	{
		// y is evolving from 0 to 31
		y = (iLed + step_index) & 0x1f;
		if (y >= 16)
		{
			if (y >= 24) // y in 4th cycle
			{
				leds[iLed].color(0xff >> (y - 24), 0xff >> (y - 24), 0xff >> (y - 24));
			}
			else				// y in 3rd cycle
			{
				leds[iLed].color(0xff >> (24 - y), 0xff >> (24 - y), 0xff >> (24 - y));
			}
		} else {
			if (y >= 8)		// y in 2nd cycle
			{
				leds[iLed].color(color.r >> (y - 8), color.g >> (y - 8), color.b >> (y - 8));
			}
			else				// y in 1st cycle
			{
				leds[iLed].color(color.r >> (8 - y), color.g >> (8 - y), color.b >> (8 - y));
			}
		}
	}
}

void PulseEffect::_preStep()
{
	int delta = ((step_index > 64) ? (128 - step_index) : step_index) >> 3;
	for(int iLed = 0; iLed < strip_length; iLed++)
	{
		leds[iLed].color(color.r >> delta, color.g >> delta, color.b >> delta);
	}
}
