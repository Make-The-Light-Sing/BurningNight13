#include "FastSPI_LED2.h"
#include "config.h"

typedef struct CRGB { byte g; byte r; byte b; };
CRGB leds[NUM_LEDS];
TM1809Controller800Mhz<6> LED;

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
	for(int i = 0; i < 3; i++) {
		for(int iLed = 0; iLed < NUM_LEDS; iLed++) {
			switch(i) {
			 	case 0: leds[iLed].r = 0xff; break;
			 	case 1: leds[iLed].g = 0xff; break;
			 	case 2: leds[iLed].b = 0xff; break;
			}
			LED.showRGB((byte*)leds, NUM_LEDS);
			memset(leds, 0x00, NUM_LEDS * sizeof(CRGB));
//			leds[iLed] = {0x00, 0x00, 0x00}; ==> Not faster
		}
	}
}
