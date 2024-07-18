/*
 * LCD.h
 *
 * Created: 12/07/2023 12:48:15 م
 *  Author: Alaa Mohamed
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "DIO_Driver.h"
#include "LCD_CONFIGURATION.h"

#define CLEAR_SCREEN 0x01
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define DISPLAY_ON_CURSOR_ON 0X0E
#define DISPLAY_ON_CURSOR_OFF 0X0C
#define DISPLAY_ON_CURSOR_BLINKING 0X0F
#define SHIFT_CURSOR_LEFT 0X04
#define SHIFT_DISPLAY_RIGHT 0X05
#define SHIFT_DISPLAY_LEFT 0X07
#define SHIFT_ENTIRE_DISPLAY_RIGHT 0X1C
#define SHIFT_ENTIRE_DISPLAY_LEFT 0X18

#if defined EIGHT_BIT_MODE
#define LCD_DATA_PINS_PORT 'B'
#define OTHER_PINS_PORT 'A'
#define RS 0
#define RW 1
#define ENABLE 2
#define EIGHT_BIT_COMMAND 0X38

#elif defined FOUR_BIT_MODE
#define LCD_DATA_PINS_PORT 'A'
#define OTHER_PINS_PORT 'A'
#define RS 1
#define RW 2
#define ENABLE 3
#define DB7 7
#define DB6 6
#define DB5 5
#define DB4 4
#define FOUR_BIT_COMMAND 0X28

#endif

void LCD_Initialize();
void LCD_EnablePulse();
void LCD_SendCommand(char command);
void LCD_SendCharacter(char character);
void LCD_SendString(char *string);
void LCD_MoveCursor(char row, char column);

#endif /* LCD_H_ */