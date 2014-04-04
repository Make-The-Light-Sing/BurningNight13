/*
 * MessageProcessor.cpp
 *
 *  Created on: 4 avr. 2014
 *      Author: jeckel
 */

#include "MessageProcessor.h"


void MessageProcessor::processMessage(byte* message)
{
    switch(message[0]) {
        case CMD_SET_SEGMENT_COLOR:
            unsigned int index = message[1];
            CRGB color;
            color.r = message[2];
            color.g = message[3];
            color.b = message[4];
            segments->setSegmentColor(index, color);
            break;
    }
}   // processMessage
