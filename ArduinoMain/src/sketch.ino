#include "FastSPI_LED2.h"
#include "Config_Prototype.h"
#include "Effect/EffectFactory.h"
#include "Color.h"
#include <Wire.h>

#define SLAVE_ADDRESS 0x20

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
	config[0].color.Wheel(32);
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(receiveData);
    Wire.onRequest(sendData);
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

/**
 * Read data sent by the master
 * @param int byteCount number of byte received
 */
void receiveData(int byteCount)
{
	// strips 3 & 4
	byte value_readed = Wire.read();
	CRGB color;
	color.Wheel(value_readed);
	effect[3]->setColor(color);
	effect[4]->setColor(color);
}	// receiveData

/**
 * Send data when it's requested by the master
 */
void sendData(){
}	// sendData
