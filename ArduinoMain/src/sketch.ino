#include "FastSPI_LED2.h"
#include "Config.h"
#include "Color.h"
#include "Effect/Effect.h"

CRGB leds[NUM_LEDS];
TM1809Controller800Mhz<PIN_STRIP> LED;



T_Effect_Config config[3] = {
		{ Wave, leds, 50, CRed },
		{ Color_Chase, leds + 50, 25, CMagenta },
		{ Pulse, leds + 75, 75, CGreen }
};

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
