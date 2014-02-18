#include "FastSPI_LED2.h"
#include "Config.h"
#include "Effect/Effect.h"
#include "Color.h"

Effect *effect[NB_SEGMENT];

/**
 *  Setup method
 *  Initialize arduino
 */
void setup() {
	EffectFactory factory;

	LED.init();
	memset(leds, 0x00, NUM_LEDS * sizeof(CRGB));
	LED.showRGB((byte*)leds, NUM_LEDS);
	delay(20);

	for(int i; i < NB_SEGMENT; i++) {
		effect[i] = factory.createEffect(&config[i]);
	}
}

/**
 *  Main loop
 */
void loop()
{
	// Prepare leds
	for(int i; i < NB_SEGMENT; i++) {
		effect[i]->preStep();
	}
	// update ledstrip
	LED.showRGB((byte*)leds, NUM_LEDS);
	// Make some post traetment like reinitialisation before next step
	for(int i; i < NB_SEGMENT; i++) {
		effect[i]->postStep();
	}
}
