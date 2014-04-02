#include "FastSPI_LED2.h"
#include "Config_Prototype.h"
#include "Effect/EffectFactory.h"
#include "Color.h"
#include <Wire.h>

#define SLAVE_ADDRESS 0x20
//#define DEBUG

#define CMD_SET_SEGMENT_COLOR 1

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
 *
 * Data received are composed like this :
 * - byte 1 : 0 (used by python library)
 * - byte 2 : number of bytes composing the message
 * - byte 3-n : command
 *
 * List of commands :
 * - 1 : set color of a segment
 *
 * @param int byteCount number of byte received
 */
void receiveData(int byteCount)
{
    byte *message;
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

    message = (byte *) malloc(byteCount - 2);
    byte i = 0;
    while (Wire.available()) {
        message[i] = Wire.read();
        i++;
    }
    processMessage(message);
    free(message);
}   // receiveData

/**
 * Send data when it's requested by the master
 */
void sendData()
{
    Wire.write(dataReceived);
    dataReceived = 0;
}   // sendData

/**
 * Process recieved messages
 *
 * @param byte* message
 */
void processMessage(byte* message)
{
    switch(message[0]) {
        case CMD_SET_SEGMENT_COLOR:
            setSegmentColor(message + 1);
            break;
    }
}   // processMessage

/**
 * Redefine segment's color
 *
 * @param byte* message
 */
void setSegmentColor(byte* message)
{
    CRGB color;
    color.r = message[1];
    color.g = message[2];
    color.b = message[3];
    effect[message[0]]->setColor(color);
}

// */
