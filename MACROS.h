/*
 * MACROS.h
 *
 * Created: 10/02/2023 12:50:34 ص
 *  Author: Alaa Mohamed
 */ 


#ifndef MACROS_H_
#define MACROS_H_

#define REG_SIZE 8
#define SET_BIT(Register,Bit)				  Register |= (1 << Bit)
#define CLEAR_BIT(Register,Bit)				  Register &= (~(1 << Bit))
#define TOGGLE_BIT(Register,Bit)			  Register ^= (1 << Bit)
#define READ_BIT(Register,Bit)				  ((Register & (1 << Bit)) >> Bit)
#define ROTATE_RIGHT(Register,Number)         Register = (Register << (REG_SIZE-Number)) | (Register >> (Number))
#define ROTATE_LEFT(Register,Number)		  Register = (Register >> (REG_SIZE-Number)) | (Register << (Number))

#endif /* MACROS_H_ */