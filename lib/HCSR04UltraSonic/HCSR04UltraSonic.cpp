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
HCSR04UltraSonic::HCSR04UltraSonic(int tp, int ep)
{
    pinMode(tp, OUTPUT);
    pinMode(ep, INPUT);
    _trigPin = tp;
    _echoPin = ep;
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
    return pulseIn(_echoPin, HIGH);
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
