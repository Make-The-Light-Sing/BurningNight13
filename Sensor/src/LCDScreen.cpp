/*
 * LCDScreen.cpp
 *
 *  Created on: 20 mars 2014
 *      Author: jeckel
 */

#include "LCDScreen.h"

/**
 * Main constructor
 *
 * @param uint8_t rs
 * @param uint8_t enable
 * @param uint8_t d4
 * @param uint8_t d5
 * @param uint8_t d6
 * @param uint8_t d7
 */
LCDScreen::LCDScreen(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7, uint8_t btn) :
        LiquidCrystal(rs, enable, d4, d5, d6, d7)
{
    btn_pin = btn;
}


/**
 * Read the buttons
 * @return int
 */
int LCDScreen::readButton()
{
    int adc_key_in = analogRead(btn_pin);
    // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
    // we add approx 50 to those values and check to see if we are close
    if (adc_key_in > 1000) return LCD_BTN_NONE; // We make this the 1st option for speed reasons since it will be the most likely result
    // For V1.1 us this threshold
    if (adc_key_in < 50) return LCD_BTN_RIGHT;
    if (adc_key_in < 250) return LCD_BTN_UP;
    if (adc_key_in < 450) return LCD_BTN_DOWN;
    if (adc_key_in < 650) return LCD_BTN_LEFT;
    if (adc_key_in < 850) return LCD_BTN_SELECT;
    return LCD_BTN_NONE;  // when all others fail, return this...
}   // read_LCD_buttons()

/**
 * Main destructor
 */
LCDScreen::~LCDScreen()
{
    // TODO Auto-generated destructor stub
}

