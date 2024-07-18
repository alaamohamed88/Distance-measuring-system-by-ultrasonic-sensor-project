/*
 * DIO_Driver.h
 *
 * Created: 13/02/2023 05:41:02 م
 *  Author: Alaa Mohamed
 */ 


#ifndef DIO_DRIVER_H_
#define DIO_DRIVER_H_

#include "MACROS.h"

#define MyDDRA *(volatile unsigned char*) 0x3A
#define MyDDRB *(volatile unsigned char*) 0x37
#define MyDDRC *(volatile unsigned char*) 0x34
#define MyDDRD *(volatile unsigned char*) 0x31
#define MyPORTA *(volatile unsigned char*) 0x3B
#define MyPORTB *(volatile unsigned char*) 0x38
#define MyPORTC *(volatile unsigned char*) 0x35
#define MyPORTD *(volatile unsigned char*) 0x32
#define MyPINA *(volatile unsigned char*) 0x39
#define MyPINB *(volatile unsigned char*) 0x36
#define MyPINC *(volatile unsigned char*) 0x33
#define MyPIND *(volatile unsigned char*) 0x30
#define OUTPUT 1
#define INPUT 0

void DIO_setPinDirection(unsigned char PortName, unsigned char PinNumber, unsigned char Direction);
void DIO_writePin(unsigned char PortName, unsigned char PinNumber, unsigned char Output);
unsigned char DIO_readPin(unsigned char PortName, unsigned char PinNumber);
void DIO_TogglePin(unsigned char PortName, unsigned char PinNumber);
void DIO_setPortDirection(unsigned char PortName, unsigned char Direction);
void DIO_writePort(unsigned char PortName,unsigned char Output);
unsigned char DIO_readPort(unsigned char PortName);
unsigned char DIO_TogglePort(unsigned char PortName);
void DIO_setInternalPullup(unsigned char PortName,unsigned char PinNumber,unsigned char PullUp_Option);
void DIO_writeLowNibble(unsigned char PortName,unsigned char LowNibbleOutput);
void DIO_writeHighNibble(unsigned char PortName,unsigned char HighNibbleOutput);

#endif /* DIO_DRIVER_H_ */