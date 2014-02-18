#include "FastSPI_LED2.h"
#include "Config.h"
#include "Effect/Effect.h"
#include "Color.h"


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
	PulseEffect      effect1 = PulseEffect(&config[2]);
	WaveEffect       effect2 = WaveEffect(&config[0]);
	ColorChaseEffect effect3 = ColorChaseEffect(&config[1]);
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
