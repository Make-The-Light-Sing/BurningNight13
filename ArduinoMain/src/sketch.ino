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

/**
 * Read data sent by the master
 * @param int byteCount number of byte received
 */
void receiveData(int byteCount)
{
    dataReceived = byteCount;
    byte cmd = Wire.read();     // Unused
    byte length = Wire.read();

    #ifdef DEBUG
        Serial.print("Received : ");
        Serial.print(byteCount);
        Serial.print(" / asserted : ");
        Serial.println(length);
    #endif

    if (length != byteCount) {
        // Error in data, clear buffer and wait for new data
        while (Wire.available())
            Wire.read();
        return;
    }

    byte red = Wire.read();
    byte green = Wire.read();
    byte blue = Wire.read();
    CRGB color = { red, green, blue };
    // test updating strips 3 & 4
    effect[3]->setColor(color);
    effect[4]->setColor(color);

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
