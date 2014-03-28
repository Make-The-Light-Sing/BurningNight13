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
    HCSR04UltraSonic(int tp, int ep);
    long timing();
    float convert(long microsec);
    virtual ~HCSR04UltraSonic();
    int readDistance();
private:
    int _trigPin;
    int _echoPin;
};

#endif /* HCSR04ULTRASONIC_H_ */
