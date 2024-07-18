/*
 * INTERRUPT_CONFIG.h
 *
 * Created: 12/07/2023 12:50:16 م
 *  Author: Alaa Mohamed
 */ 


#ifndef INTERRUPT_CONFIG_H_
#define INTERRUPT_CONFIG_H_

#include <avr/interrupt.h>

#define MySREG *(volatile unsigned char*) 0x5F
#define MyGICR *(volatile unsigned char*) 0x5B
#define MyGIFR *(volatile unsigned char*) 0x5A
#define MyMCUCR *(volatile unsigned char*) 0x55
#define MyMCUCSR *(volatile unsigned char*) 0x54
#define MyISC00 0
#define MyISC01 1
#define MyISC10 2
#define MyISC11 3
#define MyISC2 6
#define MyINT0 6
#define MyINT1 7
#define MyINT2 5
#define MyINTF0 6
#define MyINTF1 7
#define MyINTF2 5

#endif /* INTERRUPT_CONFIG_H_ */