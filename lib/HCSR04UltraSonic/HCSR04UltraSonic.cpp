/*
 * HCSR04UltraSonic.cpp
 *
 *  Created on: 20 mars 2014
 *      Author: jeckel
 */

#include "HCSR04UltraSonic.h"

/**
 * Main constructor
 *
 * @param int tp Trigger pin number
 * @param int ep Echo pin number
 */
HCSR04UltraSonic::HCSR04UltraSonic(byte tp, byte ep, unsigned int timeout)
{
    pinMode(tp, OUTPUT);
    pinMode(ep, INPUT);
    _trigPin = tp;
    _echoPin = ep;
    _timeout = timeout;
}   // HCSR04UltraSonic

/**
 * Main destructor
 */
HCSR04UltraSonic::~HCSR04UltraSonic()
{
}   // ~HCSR04UltraSonic

/**
 * Get timing between pulse and echo
 *
 * @return long
 */
long HCSR04UltraSonic::timing()
{
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
    return pulseIn(_echoPin, HIGH, _timeout);
}   // timing

/**
 * Convert timing into centimeter
 *
 * @param  long  microsec Timing mesured with timing method
 * @return float
 */
float HCSR04UltraSonic::convert(long microsec)
{
    return microsec / 27.6233 / 2.0;  // CM
}   // convert


/**
 * Read distance, and exclude extreme measure if possible by making different measures
 * @return long
 */
int HCSR04UltraSonic::readDistance()
{
    long cm;
    for (int i = 0; i < 10; i++) {
        cm = convert(timing());
        if (cm < 4000) break;
    }
    return cm;
}   // readDistance()
