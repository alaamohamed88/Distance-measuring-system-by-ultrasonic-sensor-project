/*
 * DIO_Driver.c
 *
 * Created: 13/02/2023 05:47:25 م
 *  Author: Alaa Mohamed
 */ 


#include "DIO_Driver.h"

void DIO_setPinDirection(unsigned char PortName, unsigned char PinNumber, unsigned char PinDirection)
{
	switch(PortName)
	{
		case 'A':
		{
			if(PinDirection==OUTPUT) //set pin as output pin
			{
				SET_BIT(MyDDRA,PinNumber);
			}
			else			 //set pin as input pin
			{
				CLEAR_BIT(MyDDRA,PinNumber);
			}
			break;
		}
		case 'B':
		{
			if(PinDirection==OUTPUT) //set pin as output pin
			{
				SET_BIT(MyDDRB,PinNumber);
			}
			else			 //set pin as input pin
			{
				CLEAR_BIT(MyDDRB,PinNumber);
			}
			break;
		}
		case 'C':
		{
			if(PinDirection==OUTPUT) //set pin as output pin
			{
				SET_BIT(MyDDRC,PinNumber);
			}
			else			 //set pin as input pin
			{
				CLEAR_BIT(MyDDRC,PinNumber);
			}
			break;
		}
		case 'D':
		{
			if(PinDirection==OUTPUT) //set pin as output pin
			{
				SET_BIT(MyDDRD,PinNumber);
			}
			else			 //set pin as input pin
			{
				CLEAR_BIT(MyDDRD,PinNumber);
			}
			break;
		}
		default:
		break;
	}
}
void DIO_writePin(unsigned char PortName, unsigned char PinNumber, unsigned char PinOutput)
{
	switch(PortName)
	{
		case 'A':
		{
			if(PinOutput==1)
			{
				SET_BIT(MyPORTA,PinNumber);
			}
			else
			{
				CLEAR_BIT(MyPORTA,PinNumber);
			}
			break;
		}
		case 'B':
		{
			if(PinOutput==1)
			{
				SET_BIT(MyPORTB,PinNumber);
			}
			else
			{
				CLEAR_BIT(MyPORTB,PinNumber);
			}
			break;
		}
		case 'C':
		{
			if(PinOutput==1)
			{
				SET_BIT(MyPORTC,PinNumber);
			}
			else
			{
				CLEAR_BIT(MyPORTC,PinNumber);
			}
			break;
		}
		case 'D':
		{
			if(PinOutput==1)
			{
				SET_BIT(MyPORTD,PinNumber);
			}
			else
			{
				CLEAR_BIT(MyPORTD,PinNumber);
			}
			break;
		}
		default:
		break;
	}
}
unsigned char DIO_readPin(unsigned char PortName, unsigned char PinNumber)
{
	unsigned char PinStatus = 0;
	switch(PortName)
	{
		case 'A':
		{
			PinStatus = READ_BIT(MyPINA,PinNumber);
			break;
		}
		case 'B':
		{
			PinStatus = READ_BIT(MyPINB,PinNumber);
			break;
		}
		case 'C':
		{
			PinStatus = READ_BIT(MyPINC,PinNumber);
			break;
		}
		case 'D':
		{
			PinStatus = READ_BIT(MyPIND,PinNumber);
			break;
		}
		default:
		break;
	}
	return PinStatus;
}
void DIO_TogglePin(unsigned char PortName, unsigned char PinNumber)
{
	switch(PortName)
	{
		case 'A':
		{
			TOGGLE_BIT(MyPORTA,PinNumber);
			break;
		}
		case 'B':
		{
			TOGGLE_BIT(MyPORTB,PinNumber);
			break;
		}
		case 'C':
		{
			TOGGLE_BIT(MyPORTC,PinNumber);
			break;
		}
		case 'D':
		{
			TOGGLE_BIT(MyPORTD,PinNumber);
			break;
		}
		default:
		break;
	}
}
void DIO_setPortDirection(unsigned char PortName, unsigned char PortDirection)
{
	switch(PortName)
	{
		case 'A':
		{
			MyDDRA = PortDirection;
			break;
		}
		case 'B':
		{
			MyDDRB = PortDirection;
			break;
		}
		case 'C':
		{
			MyDDRC = PortDirection;
			break;
		}
		case 'D':
		{
			MyDDRD = PortDirection;
			break;
		}
		default:
		break;
	}
}
void DIO_writePort(unsigned char PortName,unsigned char PortOutput)
{
	switch(PortName)
	{
		case 'A':
		{
			MyPORTA = PortOutput;
			break;
		}
		case 'B':
		{
			MyPORTB = PortOutput;
			break;
		}
		case 'C':
		{
			MyPORTC = PortOutput;
			break;
		}
		case 'D':
		{
			MyPORTD = PortOutput;
			break;
		}
		default:
		break;
	}
}
unsigned char DIO_readPort(unsigned char PortName)
{
	unsigned char PortStatus = 0;
	switch (PortName)
	{
		case 'A':
		{
			PortStatus = MyPINA;
			break;
		}
		case 'B':
		{
			PortStatus = MyPINB;
			break;
		}
		case 'C':
		{
			PortStatus = MyPINC;
			break;
		}
		case 'D':
		{
			PortStatus = MyPIND;
			break;
		}
		default:
		break;
	}
	return PortStatus;
}
unsigned char DIO_TogglePort(unsigned char PortName)
{
	switch(PortName)
	{
		case 'A':
		{
			MyPORTA = ~(MyPORTA);
			break;
		}
		case 'B':
		{
			MyPORTB = ~(MyPORTB);
			break;
		}
		case 'C':
		{
			MyPORTC = ~(MyPORTC);
			break;
		}
		case 'D':
		{
			MyPORTD = ~(MyPORTD);
			break;
		}
		default:
		break;
	}
}

void DIO_setInternalPullup(unsigned char PortName,unsigned char PinNumber,unsigned char PullUp_Option)
{
	switch (PortName)
	{
		case 'A':
		{
			if(PullUp_Option==1)
			{
				SET_BIT(MyPORTA,PinNumber);
			}
			else
			{
				CLEAR_BIT(MyPORTA,PinNumber);
			}
			break;
		}
		case 'B':
		{
			if(PullUp_Option==1)
			{
				SET_BIT(MyPORTB,PinNumber);
			}
			else
			{
				CLEAR_BIT(MyPORTB,PinNumber);
			}
			break;
		}
		case 'C':
		{
			if(PullUp_Option==1)
			{
				SET_BIT(MyPORTC,PinNumber);
			}
			else
			{
				CLEAR_BIT(MyPORTC,PinNumber);
			}
			break;
		}
		case 'D':
		{
			if(PullUp_Option==1)
			{
				SET_BIT(MyPORTD,PinNumber);
			}
			else
			{
				CLEAR_BIT(MyPORTD,PinNumber);
			}
			break;
		}
		default:
		break;
	}
}

void DIO_writeLowNibble(unsigned char PortName,unsigned char LowNibbleOutput)
{
	DIO_writePin(PortName,0,READ_BIT(LowNibbleOutput,0));
	DIO_writePin(PortName,1,READ_BIT(LowNibbleOutput,1));
	DIO_writePin(PortName,2,READ_BIT(LowNibbleOutput,2));
	DIO_writePin(PortName,3,READ_BIT(LowNibbleOutput,3));
}

void DIO_writeHighNibble(unsigned char PortName,unsigned char HighNibbleOutput)
{
	DIO_writePin(PortName,4,READ_BIT(HighNibbleOutput,0));
	DIO_writePin(PortName,5,READ_BIT(HighNibbleOutput,1));
	DIO_writePin(PortName,6,READ_BIT(HighNibbleOutput,2));
	DIO_writePin(PortName,7,READ_BIT(HighNibbleOutput,3));
}