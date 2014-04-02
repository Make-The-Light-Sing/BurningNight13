#include "FastSPI_LED2.h"
#include "Config_Prototype.h"
#include "Effect/EffectFactory.h"
#include "Color.h"
#include <Wire.h>

#define SLAVE_ADDRESS 0x20
//#define DEBUG

Effect *effect[NB_SEGMENT];
int dataReceived = 0;

/**
 *  Setup method
 *  Initialize arduino
 */
void setup()
{
    EffectFactory factory;

    LED.init();
    memset(leds, 0x00, NUM_LEDS * sizeof(CRGB));
    LED.showRGB((byte*) leds, NUM_LEDS);
    delay(20);

    for (int i; i < NB_SEGMENT; i++) {
        effect[i] = factory.createEffect(&config[i]);
    }
    config[0].color.Wheel(32);
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(receiveData);
    Wire.onRequest(sendData);
    #ifdef DEBUG
        Serial.begin(9600);
        Serial.println("Ready...");
    #endif
}

/**
 *  Main loop
 */
void loop()
{
    // Prepare leds
    for (int i; i < NB_SEGMENT; i++) {
        effect[i]->preStep();
    }
    // update ledstrip
    LED.showRGB((byte*) leds, NUM_LEDS);
    // Make some post traetment like reinitialisation before next step
    for (int i; i < NB_SEGMENT; i++) {
        effect[i]->postStep();
    }
}

#define CMD_SET_SEGMENT_COLOR 1

/**
 * Read data sent by the master
 *
 * Data received are composed like this :
 * - byte 1 : 0 (used by python library)
 * - byte 2 : number of bytes composing the message
 * - byte 3 : command
 * - byte 4 : index of segment to update
 * - byte 5 : Red color
 * - byte 6 : Green color
 * - byte 7 : Blue color
 *
 * List of commands :
 * - 1 : set color of a segment
 *
 * @param int byteCount number of byte received
 */
void receiveData(int byteCount)
{
    dataReceived = byteCount;
    byte cmd = Wire.read();     // 1st byte, unused
    byte length = Wire.read();  // 2nd byte, message length

    #ifdef DEBUG
        Serial.print("Received : ");
        Serial.print(byteCount);
        Serial.print(" / asserted : ");
        Serial.println(length);
    #endif

    // Check if message length = number of bytes received
    if (length != byteCount) {
        // Error in data, clear buffer and wait for new data
        while (Wire.available())
            Wire.read();
        return;
    }
    byte command = Wire.read();
    byte segment = Wire.read();
    if (segment >= NB_SEGMENT) segment = NB_SEGMENT -1;

    switch(command) {
        case CMD_SET_SEGMENT_COLOR:
            CRGB color;
            color.r = Wire.read();
            color.g = Wire.read();
            color.b = Wire.read();
            effect[segment]->setColor(color);
            break;
    }

    // clear all remaining data
    while (Wire.available())
        Wire.read();
}	// receiveData

/**
 * Send data when it's requested by the master
 */
void sendData()
{
    Wire.write(dataReceived);
    dataReceived = 0;
}	// sendData
