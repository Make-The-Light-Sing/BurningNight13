#include "FastSPI_LED2.h"
#include "config.h"
#include "Color.h"
#include "Effect/Effect.h"

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
	CRGB Red;
	Red = 0xff0000;
	//ColorChaseEffect effect = ColorChaseEffect(leds, NUM_LEDS, Red);
	WaveEffect effect = WaveEffect(leds, NUM_LEDS, Red);
	while(true) {
		effect.step();
		LED.showRGB((byte*)leds, NUM_LEDS);
		effect.after_step();
	}
}
