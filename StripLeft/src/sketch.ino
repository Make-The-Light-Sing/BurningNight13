#include <FastSPI_LED2.h>
#include <Segment.h>
#include <Color.h>
#include <Wire.h>

#include "Config.h"

TM1809Controller800Mhz<PIN_STRIP> LED;
SegmentCollection segments;

/**
 * Initialize
 */
void setup()
{
    Effect_Factory factory;
    LED.init();

    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(receiveData);
    Wire.onRequest(sendData);

    for(unsigned int i = 0; i < NB_SEGMENT; i++) {
        segments.addSegment(new Segment(seg_config[i], factory.createEffect(effect_config[i])));
    }
    segments.init();
}   // setup

/**
 * Main loop
 */
void loop()
{
    segments.preStep();
    LED.showRGB((unsigned char *) leds, NUM_LEDS);
    segments.postStep();
}   // loop

/**
 * i2c receiving data callback
 */
void receiveData(int byteCount)
{
}   // receiveData

/**
 * i2c sending data on request callback
 */
void sendData()
{
}   // sendData
