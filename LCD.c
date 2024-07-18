/*
 * LCD.c
 *
 * Created: 12/07/2023 12:48:44 م
 *  Author: Alaa Mohamed
 */ 


#define  F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"

void LCD_Initialize()
{
	_delay_ms(200);
	#if defined EIGHT_BIT_MODE
	DIO_setPortDirection(LCD_DATA_PINS_PORT,0xff);
	DIO_setPinDirection(OTHER_PINS_PORT,RS,OUTPUT);
	DIO_setPinDirection(OTHER_PINS_PORT,RW,OUTPUT);
	DIO_setPinDirection(OTHER_PINS_PORT,ENABLE,OUTPUT);
	DIO_writePin(OTHER_PINS_PORT,RW,0);
	LCD_SendCommand(EIGHT_BIT_COMMAND);
	_delay_ms(1);
	LCD_SendCommand(DISPLAY_ON_CURSOR_OFF);
	_delay_ms(1);
	LCD_SendCommand(CLEAR_SCREEN);
	_delay_ms(10);
	LCD_SendCommand(ENTRY_MODE);
	_delay_ms(1);
	
	#elif defined FOUR_BIT_MODE
	DIO_setPinDirection(LCD_DATA_PINS_PORT,DB4,OUTPUT);
	DIO_setPinDirection(LCD_DATA_PINS_PORT,DB5,OUTPUT);
	DIO_setPinDirection(LCD_DATA_PINS_PORT,DB6,OUTPUT);
	DIO_setPinDirection(LCD_DATA_PINS_PORT,DB7,OUTPUT);
	DIO_setPinDirection(OTHER_PINS_PORT,RS,OUTPUT);
	DIO_setPinDirection(OTHER_PINS_PORT,RW,OUTPUT);
	DIO_setPinDirection(OTHER_PINS_PORT,ENABLE,OUTPUT);
	DIO_writePin(OTHER_PINS_PORT,RW,0);
	LCD_SendCommand(RETURN_HOME);
	_delay_ms(10);
	LCD_SendCommand(FOUR_BIT_COMMAND);
	_delay_ms(1);
	LCD_SendCommand(DISPLAY_ON_CURSOR_OFF);
	_delay_ms(1);
	LCD_SendCommand(CLEAR_SCREEN);
	_delay_ms(10);
	LCD_SendCommand(ENTRY_MODE);
	_delay_ms(1);
	#endif
}

void LCD_EnablePulse()
{
	DIO_writePin(OTHER_PINS_PORT,ENABLE,1);
	_delay_ms(2);
	DIO_writePin(OTHER_PINS_PORT,ENABLE,0);
	_delay_ms(2);
}

void LCD_SendCommand(char command)
{
	#if defined EIGHT_BIT_MODE
	DIO_writePort(LCD_DATA_PINS_PORT,command);
	DIO_writePin(OTHER_PINS_PORT,RS,0);
	LCD_EnablePulse();
	
	#elif defined FOUR_BIT_MODE
	DIO_writeHighNibble(LCD_DATA_PINS_PORT,command>>4);
	DIO_writePin(OTHER_PINS_PORT,RS,0);
	LCD_EnablePulse();
	DIO_writeHighNibble(LCD_DATA_PINS_PORT,command);
	DIO_writePin(OTHER_PINS_PORT,RS,0);
	LCD_EnablePulse();
	#endif
	_delay_ms(1);
}

void LCD_SendCharacter(char character)
{
	#if defined EIGHT_BIT_MODE
	DIO_writePort(LCD_DATA_PINS_PORT,character);
	DIO_writePin(OTHER_PINS_PORT,RS,1);
	LCD_EnablePulse();
	#elif defined FOUR_BIT_MODE
	DIO_writeHighNibble(LCD_DATA_PINS_PORT,character>>4);
	DIO_writePin(OTHER_PINS_PORT,RS,1);
	LCD_EnablePulse();
	DIO_writeHighNibble(LCD_DATA_PINS_PORT,character);
	DIO_writePin(OTHER_PINS_PORT,RS,1);
	LCD_EnablePulse();
	#endif
	_delay_ms(1);
}

void LCD_SendString(char *string)
{
	while ((*string) != 0)
	{
		LCD_SendCharacter(*string);
		string++;
	}
	_delay_ms(1);
}


void LCD_MoveCursor(char row, char column)
{
	char cursor;
	if(row>2||row<1||column>16||column<1)
	{
		cursor = 0x80;
	}
	else if (row == 1)
	{
		cursor = 0x80 + (column-1);
	}
	else if (row == 2)
	{
		cursor = 0xC0 + (column-1);
	}
	LCD_SendCommand(cursor);
	_delay_ms(1);
}