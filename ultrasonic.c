/*
 * ultrasonic.c
 *
 * Created: 08/08/2023 06:25:33 م
 *  Author: Alaa Mohamed
 */ 


#define  F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "TIMER.h"

int main(void)
{
    unsigned short a,b,width,distance;
	LCD_Initialize();
	DIO_setPinDirection('D',7,OUTPUT);
	while(1)
    {
       MyTCCR1A = 0; /*timer/counter1 in overflow mode, no OC1A or OC1B connected, no forced output compare*/
	   SET_BIT(MyTIFR,MyICF1); /*Clear ICF flag*/
	   DIO_writePin('D',7,1);
	   _delay_us(50);
	   DIO_writePin('D',7,0);
	   MyTCCR1B = 0xC1; /*timer/counter1 in overflow mode, rising edge detecting,noise canceler, and no prescalar*/
	   while(READ_BIT(MyTIFR,MyICF1)==0);
	   a = MyICR1;
	   SET_BIT(MyTIFR,MyICF1); /*Clear ICF flag*/
	   MyTCCR1B = 0x81; /*timer/counter1 in overflow mode, falling edge detecting,noise canceler, and no prescalar*/
	   while(READ_BIT(MyTIFR,MyICF1)==0);
	   b = MyICR1;
	   SET_BIT(MyTIFR,MyICF1); /*Clear ICF flag*/
	   MyTCCR1B = 0;  /*Turnoff timer/counter1*/
	   width = b-a;
	   distance = ((34600*width)/(2*F_CPU));
	   if (distance < 80)
	   {
		   LCD_SendCommand(CLEAR_SCREEN);
		   LCD_SendCommand(RETURN_HOME);
		   LCD_SendString("Distance=");
		   LCD_SendCharacter((distance/10)+48);
		   LCD_SendCharacter((distance%10)+48);
		   LCD_SendString("cm");
		   _delay_ms(500);
	   }
	   else
	   {
		   LCD_SendCommand(CLEAR_SCREEN);
		   LCD_SendCommand(RETURN_HOME);
		   LCD_SendString("No object");
		   _delay_ms(500);
	   }		   
    }
}