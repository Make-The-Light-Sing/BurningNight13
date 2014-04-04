/*
 * Types.h
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned char boolean;

/**
 * Define the effect configuration structure
 */
typedef struct T_SegmentConfig {
    CRGB*         leds;
    uint16_t      length;
};

/**
 * Define type for effect direction
 */
typedef enum E_Direction {
    UP   = 0,
    DOWN = 1
};

/**
 * Define the effect configuration structure
 */
typedef struct T_EffectConfig {
    CRGB        color;
    E_Direction direction;
};

/**
 * Simple declaration for cross includes
 */
class Segment;
class Effect_Abstract;


#endif /* TYPES_H_ */
