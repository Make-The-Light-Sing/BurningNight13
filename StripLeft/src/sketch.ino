#include <FastSPI_LED2.h>
#include <Segment.h>

#include "Config.h"

TM1809Controller800Mhz<PIN_STRIP> LED;
SegmentCollection segments;

/**
 * Initialize
 */
void setup()
{
    LED.init();

    for(unsigned int i = 0; i < NB_SEGMENT; i++) {
        segments.addSegment(new Segment(seg_config[i]));
    }
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
