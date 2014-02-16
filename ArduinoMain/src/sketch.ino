#include "FastSPI_LED2.h"
#include "config.h"
#include "Color.h"

CRGB leds[NUM_LEDS];
TM1809Controller800Mhz<PIN_STRIP> LED;

/**
 *  Setup method
 *  Initialize arduino
 */
void setup() {
	LED.init();
	memset(leds, 0x00, NUM_LEDS * sizeof(CRGB));
	LED.showRGB((byte*)leds, NUM_LEDS);
	delay(20);
}

/**
 *  Main loop
 */
void loop() {
	/*for(int i = 0; i < 3; i++) {
		for(int iLed = 0; iLed < NUM_LEDS; iLed++) {
			switch(i) {
			 	case 0: leds[iLed] = 0xff0000; break; // red
			 	case 1: leds[iLed] = 0x00ff00; break; // green
			 	case 2: leds[iLed] = 0x0000ff; break; // blue
			}
			LED.showRGB((byte*)leds, NUM_LEDS);
			memset(leds, 0x00, NUM_LEDS * sizeof(CRGB));
		}
	} */
	wave();
}


void wave()
{
    byte r, g, b, y;
    byte cycle = 8;
    CRGB color;
    color = 0xff0000;

    for(int j = 0; j < (cycle * 4); j++)
    {
        for(int iLed = 0; iLed < NUM_LEDS; iLed++)
        {
        	// y is evolving from 0 to (4 x Cycle)
            y = (iLed + j) & 0x1f;
            if (y >= (2 * cycle))
            {
                if (y >= (3 * cycle)) // y in 4th cycle
                {
                    leds[iLed] = (CRGB) {
                    	0xff >> (y - 24),
                    	0xff >> (y - 24),
                    	0xff >> (y - 24)
                    };
                }
                else				// y in 3rd cycle
                {
                    leds[iLed] = (CRGB) {
                    	0xff >> (24 - y),
                    	0xff >> (24 - y),
                    	0xff >> (24 - y)
                    };
                }
            } else {
                if (y >= cycle)		// y in 2nd cycle
                {
                    leds[iLed] = (CRGB) {
                    	color.b >> (y - 8),
                      	color.r >> (y - 8),
                       	color.g >> (y - 8),
                    };
                }
                else				// y in 1st cycle
                {
                    leds[iLed] = (CRGB) {
                    	color.b >> (8 - y),
                      	color.r >> (8 - y),
                       	color.g >> (8 - y),
                    };
                }
            }
        }
        //delay(100);
        LED.showRGB((byte*)leds, NUM_LEDS);
    }
}    // function wave
