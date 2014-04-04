#ifndef __CONFIG_H
#define __CONFIG_H

#include <Color.h>

#define SLAVE_ADDRESS 0x20
#define NUM_LEDS      180
#define PIN_STRIP     6

#define NB_SEGMENT  4

CRGB leds[NUM_LEDS];

T_Segment_Config seg_config[NB_SEGMENT] = {
        { leds,       90},
        { leds + 10,  90},
        { leds + 90,  45},
        { leds + 100, 80}
    };

#endif
