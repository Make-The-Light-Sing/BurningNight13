/*
 * HCSR04UltraSonic.h
 *
 *  Created on: 20 mars 2014
 *      Author: jeckel
 */

#ifndef HCSR04ULTRASONIC_H_
#define HCSR04ULTRASONIC_H_

#include <stddef.h>
#if defined(ARDUINO) && ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

class HCSR04UltraSonic
{
public:
    HCSR04UltraSonic(byte tp, byte ep, unsigned int timeout = 50000);
    long timing();
    float convert(long microsec);
    virtual ~HCSR04UltraSonic();
    int readDistance();
private:
    byte _trigPin;
    byte _echoPin;
    unsigned int _timeout;
};

#endif /* HCSR04ULTRASONIC_H_ */
