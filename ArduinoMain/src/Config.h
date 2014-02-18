#ifndef __CONFIG_H
#define __CONFIG_H

#include "Effect/Effect.h"

#define NUM_LEDS    150
#define PIN_STRIP   6
#define NB_SEGMENT  4

CRGB leds[NUM_LEDS];
TM1809Controller800Mhz<PIN_STRIP> LED;

/**
 * Effect configuration table
 * - type of effect
 * - leds strip start pointer
 * - length of strip used
 * - color
 * - reverse or not
 */
T_Effect_Config config[NB_SEGMENT] = {
	{ Rainbow,     leds,       50, CRed,     false },
	{ Color_Chase, leds + 50,  25, CMagenta, false },
	{ Pulse,       leds + 75,  25, CGreen,   false },
	{ Wave,        leds + 100, 50, CBlue,    false }
};

#endif
