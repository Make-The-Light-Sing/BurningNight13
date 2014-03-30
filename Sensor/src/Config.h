#ifndef __CONFIG_H
#define __CONFIG_H

#define PIN_TRIG_1     A3
#define PIN_ECHO_1     2
#define PIN_TRIG_2     3
#define PIN_ECHO_2     11
#define PIN_TRIG_3     12
#define PIN_ECHO_3     13

#define PIN_LCD_RS     8
#define PIN_LCD_ENABLE 9
#define PIN_LCD_D4     4
#define PIN_LCD_D5     5
#define PIN_LCD_D6     6
#define PIN_LCD_D7     7
#define PIN_LCD_BTN    0    // AnalogPin

#define LCD_NB_ROWS    2
#define LCD_NB_COLS    16

#define SLAVE_ADDRESS 0x10

#define TRIGGER_TIMEOUT       20000
#define DELAY_BETWEEN_SENSOR  40
#define DELAY_BETWEEN_READING 0

#endif
