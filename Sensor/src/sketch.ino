#include <HCSR04UltraSonic.h>

#include "Config.h"
#include "LCDScreen.h"

/**
 * Instanciate ultrasonic sensor
 * @var Ultrasonic
 */
HCSR04UltraSonic HCSR04(PIN_TRIG, PIN_ECHO);

/**
 * Instanciate LCD screen
 * @var LiquidCrystal
 */
LCDScreen lcd(PIN_LCD_RS, PIN_LCD_ENABLE, PIN_LCD_D4, PIN_LCD_D5, PIN_LCD_D6, PIN_LCD_D7, PIN_LCD_BTN);

/**
 * Is an LCD key pressed or not
 * @var boolean
 */
bool keyDown = false;

/**
 * Initialize Arduino
 * @return void
 */
void setup()
{
    lcd.begin(LCD_NB_ROWS, LCD_NB_COLS);
    lcd.clear();
    lcd.setCursor(0, 0);	// col, row
    lcd.print("System started...");
    lcd.setCursor(0, 1);
    lcd.print("Welcom !");
}	// setup()

void loop()
{
    int lcd_key = lcd.readButton();
    long cm = readDistance();

    if (lcd_key == LCD_BTN_NONE) keyDown = false;
    if (lcd_key != LCD_BTN_NONE && !keyDown) {
        keyDown = true;
        lcd.clear();
        switch (lcd_key) // depending on which button was pushed, we perform an action
        {
            case LCD_BTN_RIGHT:
                lcd.print("RIGHT ");
                break;
            case LCD_BTN_LEFT:
                lcd.print("LEFT  ");
                break;
            case LCD_BTN_UP:
                lcd.print("UP    ");
                break;
            case LCD_BTN_DOWN:
                lcd.print("DOWN  ");
                break;
            case LCD_BTN_SELECT:
                lcd.print("SELECT");
                break;
        }
    }
    // if no key pressed display the distance
    if (! keyDown) {
        lcd.clear();
        lcd.print(cm);
        lcd.print(" cm.");
        delay(50);
    }
}   // loop()

/**
 * Read distance, and exclude extreme measure if possible by making different measures
 * @return long
 */
int readDistance()
{
    long cm;
    for (int i = 0; i < 10; i++) {
        cm = HCSR04.convert(HCSR04.timing());
        if (cm < 4000) break;
    }
    return cm;
}   // readDistance()
