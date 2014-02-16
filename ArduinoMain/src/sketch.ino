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
            y = (iLed + j) & 0x1f;
            if (y >= (2 * cycle))
            {
                if (y >= (3 * cycle))
                {
                    r = 255 * ((4 * cycle) - y) / cycle;
                    g = 255 * ((4 * cycle) - y) / cycle;
                    b = 255 * ((4 * cycle) - y) / cycle;
                }
                else
                {
                    r = 255 * (y - (2 * cycle)) / cycle;
                    g = 255 * (y - (2 * cycle)) / cycle;
                    b = 255 * (y - (2 * cycle)) / cycle;
                }
            } else {
                if (y >= cycle)
                {
                    r = color.r * ((2 * cycle) - y) / cycle;
                    g = color.g * ((2 * cycle) - y) / cycle;
                    b = color.b * ((2 * cycle) - y) / cycle;
                }
                else
                {
                    r = color.r * y / cycle;
                    g = color.g * y / cycle;
                    b = color.b * y / cycle;
                }
            }
            leds[iLed] = (CRGB) {b, r, g};
        }
        LED.showRGB((byte*)leds, NUM_LEDS);
    }
}    // function wave
