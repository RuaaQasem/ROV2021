/*
 * GPIO_program.c
 *
 * Created: 4/10/2021 11:48:49 AM
 *  Author: Laptop Market
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/io.h>
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"



void MGPIO_voidSetPinDirection(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber, u8 Copy_u8Direction)
{
	//port number = 0 => portb
	//port number = 1 => portc
	//port number = 2 => portd
	//direction = 0 => input
	//direction = 1 => output
	//direction = 2 => input with pullup
	switch(Copy_u8PortNumber)
	{
		case GPIO_PORTB:	//portb
		{
			if (Copy_u8Direction == GPIO_INPUT)		//input
			{
				BIT_CLR (DDRB,Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == GPIO_OUTPUT)	// output
			{
				BIT_SET (DDRB,Copy_u8PinNumber);
			}
			else if(Copy_u8Direction == GPIO_INPUT_PULLUP)	//input pullup
			{
				BIT_CLR (DDRB,Copy_u8PinNumber);
				BIT_SET (PORTB,Copy_u8PinNumber);
			}
			break;
		}
		case GPIO_PORTC:	//portc
		{
			if (Copy_u8Direction == GPIO_INPUT)		//input
			{
				BIT_CLR (DDRC,Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == GPIO_OUTPUT)	// output
			{
				BIT_SET (DDRC,Copy_u8PinNumber);
			}
			else if(Copy_u8Direction == GPIO_INPUT_PULLUP)	//input pullup
			{
				BIT_CLR (DDRC,Copy_u8PinNumber);
				BIT_SET (PORTC,Copy_u8PinNumber);
			}
			break;
		}
		case GPIO_PORTD:	//portd
		{
			if (Copy_u8Direction == GPIO_INPUT)		//input
			{
				BIT_CLR (DDRD,Copy_u8PinNumber);
			}
			else if (Copy_u8Direction == GPIO_OUTPUT)	// output
			{
				BIT_SET (DDRD,Copy_u8PinNumber);
			}
			else if(Copy_u8Direction == GPIO_INPUT_PULLUP)	//input pullup
			{
				BIT_CLR (DDRD,Copy_u8PinNumber);
				BIT_SET (PORTD,Copy_u8PinNumber);
			}
			
			break;
		}
		default:
		{
			
			break;
		}
	}
}

void MGPIO_voidSetPortDirection(u8 Copy_u8PortNumber, u8 Copy_u8Direction)
{
	//port number = 0 => portb
	//port number = 1 => portc
	//port number = 2 => portd
	//direction = 0 => input
	//direction = 1 => output
	//direction = 2 => input with pullup
	switch(Copy_u8PortNumber)
	{
		case GPIO_PORTB:	//portb
		{
			if (Copy_u8Direction == GPIO_INPUT)		//input
			{
				DDRB=0x00;
			}
			else if (Copy_u8Direction == GPIO_OUTPUT)	// output
			{
				DDRB=0xFF;
			}
			else if(Copy_u8Direction == GPIO_INPUT_PULLUP)	//input pullup
			{
				DDRB=0x00;
				PORTB=0xFF;
			}
			break;
		}
		case GPIO_PORTC:	//portc
		{
			if (Copy_u8Direction == GPIO_INPUT)		//input
			{
				DDRC=0x00;
			}
			else if (Copy_u8Direction == GPIO_OUTPUT)	// output
			{
				DDRC=0xFF;
			}
			else if(Copy_u8Direction == GPIO_INPUT_PULLUP)	//input pullup
			{
				DDRC=0x00;
				PORTC=0xFF;
			}
			break;
		}
		case GPIO_PORTD:	//portd
		{
			if (Copy_u8Direction == GPIO_INPUT)		//input
			{
				DDRD=0x00;
			}
			else if (Copy_u8Direction == GPIO_OUTPUT)	// output
			{
				DDRD=0xFF;
			}
			else if(Copy_u8Direction == GPIO_INPUT_PULLUP)	//input pullup
			{
				DDRD=0x00;
				PORTD=0xFF;
			}
			
			break;
		}
		default:
		{
			
			break;
		}
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber, u8 Copy_u8Value)
{
	switch(Copy_u8PortNumber)
	{
		case GPIO_PORTB:	//portb
		{
			if (Copy_u8Value == GPIO_LOW)		//input
			{
				BIT_CLR (PORTB,Copy_u8PinNumber);
			}
			else if (Copy_u8Value == GPIO_HIGH)	// output
			{
				BIT_SET (PORTB,Copy_u8PinNumber);
			}
			break;
		}
		case GPIO_PORTC:	//portc
		{
			if (Copy_u8Value == GPIO_LOW)		//input
			{
				BIT_CLR (PORTC,Copy_u8PinNumber);
			}
			else if (Copy_u8Value == GPIO_HIGH)	// output
			{
				BIT_SET (PORTC,Copy_u8PinNumber);
			}
			break;
		}
		case GPIO_PORTD:	//portd
		{
			if (Copy_u8Value == GPIO_LOW)		//input
			{
				BIT_CLR (PORTD,Copy_u8PinNumber);
			}
			else if (Copy_u8Value == GPIO_HIGH)	// output
			{
				BIT_SET (PORTD,Copy_u8PinNumber);
			}
			break;
		}
		default:
		{
			
			break;
		}
	}
}
void MGPIO_voidSetPortValue(u8 Copy_u8PortNumber,u8 Copy_u8Value){
	switch(Copy_u8PortNumber)
	{
		case GPIO_PORTB:	//portb
		{
			PORTB = Copy_u8Value;
			break;
		}
		case GPIO_PORTC:	//portc
		{
			PORTC = Copy_u8Value;
			break;
		}
		case GPIO_PORTD:	//portd
		{
			PORTD = Copy_u8Value;
			break;
		}
		default:
		{
			
			break;
		}
	}
}
void MGPIO_voidSetPin(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber){
	switch(Copy_u8PortNumber)
	{
		case GPIO_PORTB:	//portb
		{
			BIT_SET (PORTB,Copy_u8PinNumber);
			break;
		}
		case GPIO_PORTC:	//portc
		{
			BIT_SET (PORTC,Copy_u8PinNumber);
			break;
		}
		case GPIO_PORTD:	//portd
		{
			BIT_SET (PORTD,Copy_u8PinNumber);
			break;
		}
		default:
		{
			
			break;
		}
	}
}
void MGPIO_voidClearPin(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber){
	case GPIO_PORTB:	//portb
	{
		BIT_CLR (PORTB,Copy_u8PinNumber);
		break;
	}
	case GPIO_PORTC:	//portc
	{
		BIT_CLR (PORTC,Copy_u8PinNumber);
		break;
	}
	case GPIO_PORTD:	//portd
	{
		BIT_CLR (PORTD,Copy_u8PinNumber);
		break;
	}
	default:
	{
		
		break;
	}
}
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8PortNumber,u8 Copy_u8PinNumber){
	u8 value;
	case GPIO_PORTB:	//portb
	{
		BIT_GET (PINB,Copy_u8PinNumber);
		break;
	}
	case GPIO_PORTC:	//portc
	{
		BIT_GET (PINC,Copy_u8PinNumber);
		break;
	}
	case GPIO_PORTD:	//portd
	{
		BIT_GET (PIND,Copy_u8PinNumber);
		break;
	}
	default:
	{
		
		break;
	}
}
return value;}