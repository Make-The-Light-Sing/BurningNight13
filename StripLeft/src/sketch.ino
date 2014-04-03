#include <Color.h>
#include <FastSPI_LED2.h>
#include <Segment.h>

#include "Config.h"

CRGB leds[NUM_LEDS];
TM1809Controller800Mhz<PIN_STRIP> LED;
SegmentCollection segments;

/**
 * Initialize
 */
void setup()
{
    T_Segment_Config config;
    LED.init();

    config = { leds, 90 };
    segments.addSegment(new Segment(config));

    config = { leds + 90, 45 };
    segments.addSegment(new Segment(config));

    config = { leds + 135, 45 };
    segments.addSegment(new Segment(config));
}   // setup

/**
 * Main loop
 */
void loop()
{
    segments.preStep();
    LED.showRGB((unsigned char *) leds, NUM_LEDS);
    segments.postStep();
}   // loop
