#include <Color.h>
#include <FastSPI_LED2.h>

#include "Config.h"

CRGB leds[NUM_LEDS];
TM1809Controller800Mhz<PIN_STRIP> LED;

/**
 * Initialize
 */
void setup()
{
    LED.init();
}   // setup

/**
 * Main loop
 */
void loop()
{
    for(int i = 0; i < 3; i++) {
        for(int iLed = 0; iLed < NUM_LEDS; iLed++) {
            memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
            switch(i) {
                case 0: leds[iLed].r = 128; break;
                case 1: leds[iLed].g = 128; break;
                case 2: leds[iLed].b = 128; break;
            }
            LED.showRGB((unsigned char *)leds, NUM_LEDS);
        }
    }
}   // loop
