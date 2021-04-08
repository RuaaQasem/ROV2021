/*
 * main.c
 *
 * Created: 4/8/2021 3:16:45 PM
 *  Author: Laptop Market
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_interface.h"
#include "UART_interface.h"
#include <avr/io.h>
int main (void)
{
	MI2C_voidAvrIntialization();
	MUART_voidUartIntialization(FULL_dUPLEX,ASYNCHRONOUS_MODE,UART_8BIT,0,1);
	DDRB = 0xFF;
//	u8  MI2C_voidAvrSlaveWrite(char Data);
//	char  MI2C_u8AvrSlaveRead(void);
	u8 V = 1;
	while(1)
	{
		u8 I2CState = MI2C_voidAvrState();
		if(I2CState == READ)
		while(1){
			u8 D = MI2C_u8AvrSlaveRead();
			if(D == READ_ERROR || D == READ_STOP_CONDITION)
				break;
			PORTB = D;
		}
	}
}