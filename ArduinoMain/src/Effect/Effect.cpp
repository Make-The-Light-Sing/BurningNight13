#include "Effect.h"

/**
 * Color chase effect stepper, light up the next pixel
 * @return void
 */
void ColorChaseEffect::step()
{
	leds[step_index] = color; // red
	step_index ++;
	if (step_index >= strip_length) {
		step_index = 0;
	}
}

/**
 * Color chase effect after step, fill dark all pixels
 * @return void
 */
void ColorChaseEffect::after_step() {
	memset(leds, 0x00, strip_length * sizeof(CRGB));
}

/**
 * Wave effect stepper
 * @return void
 */
void WaveEffect::step() {
	byte y;
	byte cycle = 8;
	for(int iLed = 0; iLed < strip_length; iLed++)
	{
		// y is evolving from 0 to (4 x Cycle)
		y = (iLed + step_index) & 0x1f;
		if (y >= (2 * cycle))
		{
			if (y >= (3 * cycle)) // y in 4th cycle
			{
				leds[iLed] = (CRGB) {
					0xff >> (y - 24),
					0xff >> (y - 24),
					0xff >> (y - 24)
				};
			}
			else				// y in 3rd cycle
			{
				leds[iLed] = (CRGB) {
					0xff >> (24 - y),
					0xff >> (24 - y),
					0xff >> (24 - y)
				};
			}
		} else {
			if (y >= cycle)		// y in 2nd cycle
			{
				leds[iLed] = (CRGB) {
					color.b >> (y - 8),
					color.r >> (y - 8),
					color.g >> (y - 8),
				};
			}
			else				// y in 1st cycle
			{
				leds[iLed] = (CRGB) {
					color.b >> (8 - y),
					color.r >> (8 - y),
					color.g >> (8 - y),
				};
			}
		}
	}
	step_index ++;
	if (step_index >= 32) {
		step_index = 0;
	}
}
