#include <HCSR04UltraSonic.h>

#include "Config.h"
#include "LCDScreen.h"
#include <Wire.h>

/**
 * Instanciate ultrasonic sensors
 * @var Ultrasonic
 */
HCSR04UltraSonic HS1(PIN_TRIG_1, PIN_ECHO_1);
HCSR04UltraSonic HS2(PIN_TRIG_2, PIN_ECHO_2);
HCSR04UltraSonic HS3(PIN_TRIG_3, PIN_ECHO_3);

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
 * Distance read by each sensor
 * @var long
 */
long dist1, dist2, dist3 = 0;

/**
 * Identify wich sensor the master want to get data
 * @var byte
 */
byte sensor_to_read = 0;


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
    lcd.print("Welcome !");
    Wire.begin(SLAVE_ADDRESS);
    Wire.onReceive(receiveData);
    Wire.onRequest(sendData);
}	// setup()

void loop()
{
    int lcd_key = lcd.readButton();
    dist1 = HS1.readDistance();
    delay(10);
    dist2 = HS2.readDistance();
    delay(10);
    dist3 = HS3.readDistance();
    delay(10);

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
        lcd.setCursor(0, 0);
        lcd.print("1: ");
        lcd.print(dist1);
        lcd.print("cm 2: ");
        lcd.print(dist2);
        lcd.print("cm");
        lcd.setCursor(0, 1);
        lcd.print("3: ");
        lcd.print(dist3);
        lcd.print("cm");
        //delay(50);
    }
}   // loop()

/**
 * Read data sent by the master
 * @param int byteCount number of byte received
 */
void receiveData(int byteCount){
	sensor_to_read = Wire.read();
}	// receiveData

/**
 * Send data when it's requested by the master
 */
void sendData(){
	switch(sensor_to_read) {
	case 1 :
		Wire.write(constrain(dist1, 0, 255));
		break;
	case 2 :
		Wire.write(constrain(dist2, 0, 255));
		break;
	case 3 :
		Wire.write(constrain(dist3, 0, 255));
		break;
	default :
		Wire.write(255);
	}
	sensor_to_read = 0;
}	// sendData
