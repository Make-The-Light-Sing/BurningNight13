/*
 * LCDScreen.h
 *
 *  Created on: 20 mars 2014
 *      Author: jeckel
 */

#ifndef LCDSCREEN_H_
#define LCDSCREEN_H_

#include <stddef.h>
#if defined(ARDUINO) && ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include <LiquidCrystal.h>

#define LCD_BTN_RIGHT  0
#define LCD_BTN_UP     1
#define LCD_BTN_DOWN   2
#define LCD_BTN_LEFT   3
#define LCD_BTN_SELECT 4
#define LCD_BTN_NONE   5

class LCDScreen: public LiquidCrystal
{
public:
    LCDScreen(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7, uint8_t btn);
    int readButton();
    virtual ~LCDScreen();
protected:
    uint8_t btn_pin;
};

#endif /* LCDSCREEN_H_ */
