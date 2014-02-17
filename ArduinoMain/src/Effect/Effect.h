#ifndef __EFFECT_EFFECT_H
#define __EFFECT_EFFECT_H

#include "../Color.h"

#define EFFECT_COLOR_CHASE 1
#define EFFECT_WAVE        2
#define EFFECT_PULSE       3

class Effect
{
	public :
		Effect(CRGB *leds, uint16_t length) : leds(leds), strip_length(length), step_loop(length) {};
		void preStep();
		void postStep();
	protected :
		virtual void _preStep() {};
		virtual void _postStep() {};
		virtual void _endLoop() {};

		uint16_t step_loop    = 0;
		uint16_t step_index   = 0;
		uint16_t strip_length = 0;
		CRGB     *leds;
};


class ColorChaseEffect : public Effect {
	public :
		ColorChaseEffect(CRGB *leds, uint16_t length, CRGB color) : Effect(leds, length), color(color) {};
	protected:
		void _preStep();
		void _postStep();
	private:
		CRGB color;
};


class WaveEffect : public Effect {
	public:
		WaveEffect(CRGB *leds, uint16_t length, CRGB color) : Effect(leds, length), color(color) { step_loop = 32; }
	protected:
		void _preStep();
	private:
		CRGB color;
};


class PulseEffect : public Effect {
	public:
		PulseEffect(CRGB *leds, uint16_t length, CRGB color) : Effect(leds, length), color(color) { step_loop = 128; }
	protected:
		void _preStep();
	private:
		CRGB color;
};

#endif
