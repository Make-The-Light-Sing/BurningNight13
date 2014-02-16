#include "config.h"
#include "FastSPI_LED2.h"

struct CRGB { byte g; byte r; byte b; };
struct CRGB leds[NUM_LEDS];
TM1809Controller800Mhz<6> LED;

/**
 *  Setup method
 *  Initialize arduino
 */
void setup() {
	LED.init();
	memset(leds, 255, NUM_LEDS * sizeof(struct CRGB));
	LED.showRGB((byte*)leds, NUM_LEDS);
	delay(20);
}

/**
 *  Main loop
 */
void loop() {
	for(int i = 0; i < 3; i++) {
		for(int iLed = 0; iLed < NUM_LEDS; iLed++) {
			memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));
			switch(i) {
			 	case 0: leds[iLed].r = 128; break;
			 	case 1: leds[iLed].g = 128; break;
			 	case 2: leds[iLed].b = 128; break;
			 }
			LED.showRGB((byte*)leds, NUM_LEDS);;
		}
	}
}
