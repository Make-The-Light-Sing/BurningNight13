#ifndef __EFFECT_EFFECT_H
#define __EFFECT_EFFECT_H

#include "../Color.h"

class Effect
{
	public :
		Effect(CRGB *leds, uint16_t length) : leds(leds), strip_length(length), step_loop(length) { };
		virtual void step() {};
		virtual void after_step() {};
		void loop();
	protected :
		uint16_t step_loop    = 0;
		uint16_t step_index   = 0;
		uint16_t strip_length = 0;
		CRGB     *leds;
};


class ColorChaseEffect : public Effect {
	public :
		ColorChaseEffect(CRGB *leds, uint16_t length, CRGB color) : Effect(leds, length), color(color) {};
		void step();
		void after_step();
	private:
		CRGB color;
};


class WaveEffect : public Effect {
	public:
		WaveEffect(CRGB *leds, uint16_t length, CRGB color) : Effect(leds, length), color(color) { step_loop = 32; }
		void step();
	private :
		CRGB color;
};


class PulseEffect : public Effect {
	public:
		PulseEffect(CRGB *leds, uint16_t length, CRGB color) : Effect(leds, length), color(color) { step_loop = 128; }
		void step();
	private:
		CRGB color;
};

#endif
