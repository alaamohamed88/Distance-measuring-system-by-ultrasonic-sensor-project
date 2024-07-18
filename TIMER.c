/*
 * TIMER.c
 *
 * Created: 04/08/2023 03:45:12 م
 *  Author: Alaa Mohamed
 */ 

#include "TIMER.h"
#include "MACROS.h"
#include "DIO_Driver.h"
#include "INTERRUPT_CONFIG.h"
#define PRESCALAR_TIMER0 1024
#define PRESCALAR_TIMER1 1024
#define PRESCALAR_TIMER2 128

void TIMER0_OVERFLOWInitializeInterrupt()
{
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00); 
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	} 	
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Enable Interrupt*/
	SET_BIT(MySREG,7);
	SET_BIT(MyTIMSK,MyTOIE0);
}

void TIMER0_PHASECORRECTClearUpcount()
{
	/*Select phase correct PWM mode*/
	SET_BIT(MyTCCR0,MyWGM00);
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00);
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Load a value in OCR0 Register*/
	MyOCR0 = 64;
	/* Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting*/
	SET_BIT(MyTCCR0,MyCOM01);
}

void TIMER0_PHASECORRECTClearDowncount()
{
	/*Select phase correct PWM mode*/
	SET_BIT(MyTCCR0,MyWGM00);
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00);
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Load a value in OCR0 Register*/
	MyOCR0 = 64;
	/* Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting*/
	SET_BIT(MyTCCR0,MyCOM00);
	SET_BIT(MyTCCR0,MyCOM01);
}
void TIMER0_FASTPWMNonInverting()
{
	/*Setting OC0 pin as output pin*/
	SET_BIT(MyDDRB,3);
	/*Selecting fast PWM mode*/
	SET_BIT(MyTCCR0,MyWGM00);
	SET_BIT(MyTCCR0,MyWGM01);
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00);
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Load a value in OCR register*/
	MyOCR0 = 64;
	/*Clear OC0 on compare match (Non-inverting mode)*/
	SET_BIT(MyTCCR0,MyCOM01);
}
void TIMER0_FASTPWMInverting()
{
	/*Setting OC0 pin as output pin*/
	SET_BIT(MyDDRB,3);
	/*Selecting fast PWM mode*/
	SET_BIT(MyTCCR0,MyWGM00);
	SET_BIT(MyTCCR0,MyWGM01);
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00);
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Load a value in OCR register*/
	MyOCR0 = 64;
	/*Set OC0 on compare match (Inverting mode)*/
	SET_BIT(MyTCCR0,MyCOM00);
	SET_BIT(MyTCCR0,MyCOM01);
}
void TIMER0_CTCInitializeInterrupt()
{
	/*Selecting CTC mode*/
	SET_BIT(MyTCCR0,MyWGM01);
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00);
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Load a value into OCR0 register*/
	MyOCR0 = 80;
	/*Enable Interrupt*/
	SET_BIT(MySREG,7);
	SET_BIT(MyTIMSK,MyOCIE0);
}
void TIMER0_CTCGenerateWave()
{
	/*Setting OC0 pin as output pin*/
	SET_BIT(MyDDRB,3);
	/*Selecting CTC mode*/
	SET_BIT(MyTCCR0,MyWGM01);
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER0 == 1)
	{
		SET_BIT(MyTCCR0,MyCS00);
	}
	else if (PRESCALAR_TIMER0 == 8)
	{
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if (PRESCALAR_TIMER0 == 64)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS01);
	}
	else if(PRESCALAR_TIMER0 == 256)
	{
		SET_BIT(MyTCCR0,MyCS02);
	}
	else if (PRESCALAR_TIMER0 == 1024)
	{
		SET_BIT(MyTCCR0,MyCS00);
		SET_BIT(MyTCCR0,MyCS02);
	}
	/*Load a value into OCR0 register*/
	MyOCR0 = 38;
	/*Toggle OC0 on Compare Match*/
	SET_BIT(MyTCCR0,MyCOM00);
}

void TIMER2_OVERFLOWInitializeInterrupt()
{
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER2 == 1)
	{
		SET_BIT(MyTCCR2,MyCS20);
	}
	else if (PRESCALAR_TIMER2 == 8)
	{
		SET_BIT(MyTCCR2,MyCS21);
	}
	else if (PRESCALAR_TIMER2 == 32)
	{
		SET_BIT(MyTCCR2,MyCS20);
		SET_BIT(MyTCCR2,MyCS21);
	}
	else if (PRESCALAR_TIMER2 == 64)
	{
		SET_BIT(MyTCCR2,MyCS22);
	}
	else if(PRESCALAR_TIMER2 == 128)
	{
		SET_BIT(MyTCCR2,MyCS20);
		SET_BIT(MyTCCR2,MyCS22);
	}
	else if(PRESCALAR_TIMER2 == 256)
	{
		SET_BIT(MyTCCR2,MyCS21);
		SET_BIT(MyTCCR2,MyCS22);
	}
	else if (PRESCALAR_TIMER2 == 1024)
	{
		SET_BIT(MyTCCR2,MyCS20);
		SET_BIT(MyTCCR2,MyCS21);
		SET_BIT(MyTCCR2,MyCS22);
	}
	/*Select external clock for Timer/Counter2*/
	SET_BIT(MyASSR,MyAS2);
	/*Enable Interrupt*/
	SET_BIT(MySREG,7);
	SET_BIT(MyTIMSK,MyTOIE2);
}

void TIMER1_OVERFLOWInitializeInterrupt()
{
	/*Configuring timer clock*/
	if (PRESCALAR_TIMER1 == 1)
	{
		SET_BIT(MyTCCR1B,MyCS10);
	}
	else if (PRESCALAR_TIMER1 == 8)
	{
		SET_BIT(MyTCCR1B,MyCS11);
	}
	else if (PRESCALAR_TIMER1 == 64)
	{
		SET_BIT(MyTCCR1B,MyCS10);
		SET_BIT(MyTCCR1B,MyCS11);
	}
	else if(PRESCALAR_TIMER1 == 256)
	{
		SET_BIT(MyTCCR1B,MyCS12);
	}
	else if (PRESCALAR_TIMER1 == 1024)
	{
		SET_BIT(MyTCCR1B,MyCS10);
		SET_BIT(MyTCCR1B,MyCS12);
	}
	/*Enable Interrupt*/
	SET_BIT(MySREG,7);
	SET_BIT(MyTIMSK,MyTOIE1);
}
