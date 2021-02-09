/*
 * Mainp.c
 *
 * Created: 2/9/2021 10:21:26 PM
 *  Author: Laptop Market
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"

#define F_CPU	1000000UL
#include <util/delay.h>

static char arr[11];

int main (void)
{
	DDRB = 1;
	PORTB = 0;
	MUART_voidUartIntialization(Full_duplex,Asynchronous_mode,UART_8BIT,Null,1);
    void MUART_voidReadString(arr, 12,15);
   
}