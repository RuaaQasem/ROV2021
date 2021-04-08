/*
 * I2C Driver.c
 *
 * Created: 4/6/2021 12:53:27 PM
 * Author : Laptop Market
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
//#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"
//#include <avr/interrupt.h>

void  MI2C_voidAvrIntialization(void)
{      
		TWAR = I2C_ADRESS<<1;
		TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	    while (!(GET_BIT(TWCR,TWINT)));	 
}

u8  MI2C_voidAvrState(void)
{
	u8 State ;
	while(1)
	{
	State= (TWSR & 0xF8);
	if (State==0x60)
		return READ; 
	else if (State==0xA8) 
		return WRITE;
	}
}

u8  MI2C_voidAvrSlaveWrite(char Data)
{   u8 State= (TWSR & 0xF8);
	TWDR = Data;
	TWCR = (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
    while (!(GET_BIT(TWCR,TWINT)));

	if (State == 0xB8)
	{
		return WRITE_DONE;
	}
	else if (State==0xA0)
	{
		SET_BIT(TWCR,TWINT);
		return WRITE_STOP_CONDITION ;
	}
	else 
		return WRITE_ERROR;
}

char  MI2C_u8AvrSlaveRead(void)
{ 
	u8 State= (TWSR & 0xF8);
	char Data ;
	TWCR |= (1<<TWINT)|(1<<TWEN)|(1<<TWEA); 
	while (!(GET_BIT(TWCR,TWINT)));
	//SET_BIT(TWCR,TWEA);
	Data =	TWDR ;
	//TWCR |= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	if (State==0x80|State==0x88) 
		return Data ;
	else if (State==0xA0)
	{
		SET_BIT (TWCR,TWINT);
		return READ_STOP_CONDITION ;	
	}
	else
		return READ_ERROR;
}