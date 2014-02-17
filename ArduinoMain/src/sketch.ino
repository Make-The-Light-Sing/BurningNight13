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
	PulseEffect      effect1 = PulseEffect(leds, 25, CBlue);
	WaveEffect       effect2 = WaveEffect(leds + 25, 100, CRed);
	ColorChaseEffect effect3 = ColorChaseEffect(leds + 125, 25, CGreen);
	while(true) {
		effect1.preStep();
		effect2.preStep();
		effect3.preStep();
		LED.showRGB((byte*)leds, NUM_LEDS);
		effect1.postStep();
		effect2.postStep();
		effect3.postStep();
	}
}
