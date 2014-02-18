#ifndef __CONFIG_H
#define __CONFIG_H

#include "Effect/Effect.h"

#define NUM_LEDS    150
#define PIN_STRIP   6

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
T_Effect_Config config[3] = {
	{ Wave,        leds,      50, CRed,     false },
	{ Color_Chase, leds + 50, 25, CMagenta, false },
	{ Pulse,       leds + 75, 75, CGreen,   false }
};

#endif
