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
	PulseEffect      effect1 = PulseEffect(leds, 50, CBlue);
	WaveEffect       effect2 = WaveEffect(leds + 50, 100, CRed);
	while(true) {
		effect1.step();
		effect2.step();
		LED.showRGB((byte*)leds, NUM_LEDS);
		effect1.after_step();
		effect2.after_step();
	}
}
