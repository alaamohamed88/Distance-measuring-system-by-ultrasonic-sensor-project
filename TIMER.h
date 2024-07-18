/*
 * TIMER.h
 *
 * Created: 04/08/2023 03:44:52 م
 *  Author: Alaa Mohamed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#define MyTCNT0 *(volatile unsigned char*) 0x52
#define MyOCR0 *(volatile unsigned char*) 0x5C
#define MyTCCR0 *(volatile unsigned char*) 0x53
#define MyTIFR *(volatile unsigned char*) 0x58
#define MyTIMSK *(volatile unsigned char*) 0x59
#define MyTCNT2 *(volatile unsigned char*) 0x44
#define MyOCR2 *(volatile unsigned char*) 0x43
#define MyTCCR2 *(volatile unsigned char*) 0x45
#define MyASSR *(volatile unsigned char*) 0x42
#define MyTCNT1H *(volatile unsigned char*) 0x4D
#define MyTCNT1L *(volatile unsigned char*) 0x4C
#define MyTCCR1A *(volatile unsigned char*) 0x4F
#define MyTCCR1B *(volatile unsigned char*) 0x4E
#define MyOCR1AH *(volatile unsigned char*) 0x4B
#define MyOCR1AL *(volatile unsigned char*) 0x4A
#define MyOCR1BH *(volatile unsigned char*) 0x49
#define MyOCR1BL *(volatile unsigned char*) 0x48
#define MyICR1 *(volatile unsigned short*) 0x46
#define MyCS00 0
#define MyCS01 1
#define MyCS02 2
#define MyWGM00 6
#define MyWGM01 3
#define MyTOV0 0
#define MyOCF0 1
#define MyTOIE0 0
#define MyOCIE0 1
#define MyCOM00 4
#define MyCOM01 5
#define MyFOC0 7
#define MyCS20 0
#define MyCS21 1
#define MyCS22 2
#define MyWGM20 6
#define MyWGM21 3
#define MyCOM20 4
#define MyCOM21 5
#define MyFOC2 7
#define MyTOIE2 6
#define MyOCIE2 7
#define MyTOV2 6
#define MyOCF2 7
#define MyAS2 3
#define MyTOIE1 2
#define MyOCIE1A 4
#define MyOCIE1B 3
#define MyTICIE1 5
#define MyTOV1 2
#define MyOCF1A 4
#define MyOCF1B 3
#define MyICF1 5
#define MyCS10 0
#define MyCS11 1
#define MyCS12 2
#define MyWGM10 0
#define MyWGM11 1
#define MyWGM12 3
#define MyWGM13 4
#define MyFOC1A 3
#define MyFOC1B 2
#define MyCOM1A0 6
#define MyCOM1A1 7
#define MyCOM1B0 4
#define MyCOM1B1 5
#define MyICES1 6
#define MyICNC1 7

void TIMER0_OVERFLOWInitializeInterrupt();
void TIMER0_PHASECORRECTClearUpcount();
void TIMER0_PHASECORRECTClearDowncount();
void TIMER0_FASTPWMNonInverting();
void TIMER0_FASTPWMInverting();
void TIMER0_CTCInitializeInterrupt();
void TIMER0_CTCGenerateWave();
void TIMER2_OVERFLOWInitializeInterrupt();

#endif /* TIMER_H_ */