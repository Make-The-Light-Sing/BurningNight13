#ifndef __COLOR_H
#define __COLOR_H

#include "Arduino.h"

/**
 * Color structure
 */
typedef struct CRGB {
	byte b;
	byte r;
	byte g;
	// Inline operator to set all colors with an RGB word
	inline uint32_t operator= (uint32_t c) {
		r = (c >> 16) & 0xff;
		g = (c >> 8) & 0xff;
		b = c & 0xff;
		return c;
	}
	void color(byte n_r, byte n_g, byte n_b) {
		r = n_r;
		g = n_g;
		b = n_b;
	}
};

const CRGB CBlack   = {0x00, 0x00, 0x00};
const CRGB CWhite   = {0xff, 0xff, 0xff};
const CRGB CRed     = {0x00, 0xff, 0x00};
const CRGB CBlue    = {0xff, 0x00, 0x00};
const CRGB CGreen   = {0x00, 0x00, 0xff};
const CRGB CYellow  = {0x00, 0xff, 0xff};
const CRGB CCyan    = {0xff, 0x00, 0xff};
const CRGB CMagenta = {0xff, 0xff, 0x00};


#endif
