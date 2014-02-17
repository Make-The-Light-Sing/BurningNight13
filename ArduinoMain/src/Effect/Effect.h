#ifndef __EFFECT_EFFECT_H
#define __EFFECT_EFFECT_H

#include "../Color.h"

class Effect
{
	public :
		Effect(CRGB *leds, uint16_t length) : leds(leds), strip_length(length) { };
		virtual void step() {};
		virtual void after_step() {};
	protected :
		uint16_t step_index   = 0;
		uint16_t strip_length = 0;
		CRGB *leds;
};


class ColorChaseEffect : public Effect {
	public :
		ColorChaseEffect(CRGB *leds, uint16_t length, CRGB color) : Effect(leds, length), color(color) { };
		void step();
		void after_step();
	private:
		CRGB color;
};


class WaveEffect : public Effect {
	public:
		WaveEffect(CRGB *leds, uint16_t length, CRGB color) : Effect(leds, length), color(color) {}
		void step();
	private :
		CRGB color;
};


#endif
