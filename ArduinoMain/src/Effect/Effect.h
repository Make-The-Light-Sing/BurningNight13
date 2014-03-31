#ifndef __EFFECT_EFFECT_H
#define __EFFECT_EFFECT_H

#include "../Color.h"

/**
 * Define different type of effects
 */
#define EFFECT_COLOR_CHASE 1
#define EFFECT_WAVE        2
#define EFFECT_PULSE       3
#define EFFECT_RAINBOW     4
#define EFFECT_FIRE        5

/**
 * Define the type of effect enum list
 */
typedef enum E_Effect {
	Color_Chase = EFFECT_COLOR_CHASE,
	Wave        = EFFECT_WAVE,
	Pulse       = EFFECT_PULSE,
	Rainbow     = EFFECT_RAINBOW,
	Fire        = EFFECT_FIRE
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
		Effect() {};
		Effect(T_Effect_Config *config) : config(config), step_loop(config->length) {};
		void preStep();
		void postStep();
		void setColor(CRGB color) { config->color = color; };
	protected :
		virtual void _preStep() { config->leds[step_index] = CWhite; };
		virtual void _postStep() { memset(config->leds, 0x00, config->length * sizeof(CRGB)); };
		virtual void _endLoop() {};

		T_Effect_Config *config;
		uint16_t         step_loop    = 0;
		uint16_t         step_index   = 0;
};

#endif
