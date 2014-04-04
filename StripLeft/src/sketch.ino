#include <FastSPI_LED2.h>
#include <Segment.h>
#include <Color.h>
#include <Wire.h>

#include "Config.h"

TM1809Controller800Mhz<PIN_STRIP> LED;
SegmentCollection segments;

unsigned char dataReceived = 0;

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
    byte *message;
    dataReceived = byteCount;
    byte cmd = Wire.read();     // 1st byte, unused
    byte length = Wire.read();  // 2nd byte, message length

    // Check if message length = number of bytes received
    if (length != byteCount) {
        // Error in data, clear buffer and wait for new data
        while (Wire.available())
            Wire.read();
        return;
    }

    message = (byte *) malloc(byteCount - 2);
    byte i = 0;
    while (Wire.available()) {
        message[i] = Wire.read();
        i++;
    }
    segments.processMessage(message);
    free(message);
}   // receiveData

/**
 * i2c sending data on request callback
 */
void sendData()
{
    Wire.write(dataReceived);
    dataReceived = 0;
}   // sendData
