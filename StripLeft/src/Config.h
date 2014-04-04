#ifndef __CONFIG_H
#define __CONFIG_H

#include <Color.h>

#define SLAVE_ADDRESS 0x20
#define NUM_LEDS      180
#define PIN_STRIP     6

#define NB_SEGMENT  6

CRGB leds[NUM_LEDS];

T_SegmentConfig seg_config[NB_SEGMENT] = {
        { leds,       45},
        { leds + 45,  45},
        { leds + 90,  45},
        { leds + 135, 45},
        { leds,       180},
        { leds,       180}
    };

T_EffectConfig effect_config[NB_SEGMENT] = {
        { CRed,   DOWN, Pulse },
        { CRed,   UP,   Fire },
        { CBlue,  UP,   Wave },
        { CBlue,  DOWN, Rainbow},
        { CGreen, DOWN, Spark },
        { CWhite, UP,   Spark }
};

#endif
