#ifndef __EFFECT_EFFECT_H
#define __EFFECT_EFFECT_H

#include "../Color.h"

/**
 * Define different type of effects
 */
#define EFFECT_COLOR_CHASE 1
#define EFFECT_WAVE        2
#define EFFECT_PULSE       3

/**
 * Define the type of effect enum list
 */
typedef enum E_Effect {
	Color_Chase = EFFECT_COLOR_CHASE,
	Wave        = EFFECT_WAVE,
	Pulse       = EFFECT_PULSE
};

/**
 * Define the effect configuration structure
 */
typedef struct T_Effect_Config {
	E_Effect     effect;
	CRGB*        leds;
	uint16_t     length;
	CRGB         color;
	boolean      reverse;		// if true, effect direction is reversed
};


class Effect
{
	public :
		Effect(CRGB *leds, uint16_t length) : leds(leds), strip_length(length), step_loop(length) {};
		Effect(T_Effect_Config *config) : config(config), leds(config->leds), strip_length(config->length), step_loop(config->length) {};
		void preStep();
		void postStep();
	protected :
		virtual void _preStep() {};
		virtual void _postStep() {};
		virtual void _endLoop() {};

		T_Effect_Config *config;
		uint16_t         step_loop    = 0;
		uint16_t         step_index   = 0;
		uint16_t         strip_length = 0;
		CRGB            *leds;
};


class ColorChaseEffect : public Effect {
	public :
		ColorChaseEffect(CRGB *leds, uint16_t length, CRGB color) : Effect(leds, length), color(color) {};
		ColorChaseEffect(T_Effect_Config *config) : Effect(config), color(config->color) {};
	protected:
		void _preStep();
		void _postStep();
	private:
		CRGB color;
};


class WaveEffect : public Effect {
	public:
		WaveEffect(CRGB *leds, uint16_t length, CRGB color) : Effect(leds, length), color(color) { step_loop = 32; }
		WaveEffect(T_Effect_Config *config) : Effect(config), color(config->color) { step_loop = 32; };
	protected:
		void _preStep();
	private:
		CRGB color;
};


class PulseEffect : public Effect {
	public:
		PulseEffect(CRGB *leds, uint16_t length, CRGB color) : Effect(leds, length), color(color) { step_loop = 128; }
		PulseEffect(T_Effect_Config *config) : Effect(config), color(config->color) { step_loop = 128; };
	protected:
		void _preStep();
	private:
		CRGB color;
};

#endif
