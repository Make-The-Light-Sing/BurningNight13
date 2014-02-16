#ifndef __COLOR_H
#define __COLOR_H

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
};

#endif
