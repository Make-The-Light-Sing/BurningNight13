#include <LiquidCrystal.h>
#include <Ultrasonic.h>

#define PIN_TRIG       3
#define PIN_ECHO       2

#define PIN_LCD_RS     8
#define PIN_LCD_ENABLE 9
#define PIN_LCD_D4     4
#define PIN_LCD_D5     5
#define PIN_LCD_D6     6
#define PIN_LCD_D7     7

#define LCD_NB_ROWS    2
#define LCD_NB_COLS    16

#define LCD_BTN_RIGHT  0
#define LCD_BTN_UP     1
#define LCD_BTN_DOWN   2
#define LCD_BTN_LEFT   3
#define LCD_BTN_SELECT 4
#define LCD_BTN_NONE   5

/**
 * Instanciate ultrasonic sensor
 * @var Ultrasonic
 */
Ultrasonic HCSR04(PIN_TRIG, PIN_ECHO);

/**
 * Instanciate LCD screen
 * @var LiquidCrystal
 */
LiquidCrystal lcd(PIN_LCD_RS, PIN_LCD_ENABLE, PIN_LCD_D4, PIN_LCD_D5, PIN_LCD_D6, PIN_LCD_D7);

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
    int  lcd_key = read_LCD_buttons();  // read the buttons
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
 * Read the buttons
 * @return int
 */
int read_LCD_buttons()
{
    int adc_key_in = analogRead(0);      // read the value from the sensor
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
}	// read_LCD_buttons()

/**
 * Read distance, and exclude extreme measure if possible by making different measures
 * @return long
 */
int readDistance()
{
    long cm;
    for (int i = 0; i < 10; i++) {
        cm = HCSR04.convert(HCSR04.timing(), 1);
        if (cm < 4000) break;
    }
    return cm;
}   // readDistance()
