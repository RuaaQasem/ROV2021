 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"
#include <avr/interrupt.h>
 
void MUART_voidUartIntialization ( u8 TransmissionState , u8 Mode , u8 DataSize , u8 Parity, u8 StopBit) {
	   // baud rate
	// FOSC is System oscillator clock frequency
	// UBRR Contents of the UBRRnH and UBRRnL registers
	u16 UBRR;
	UBRR0L = 0;
	UBRR = (u16)( (u32)(FOSC) / (16 * (u32)BAUD_RATE) ) - 1 ;
	//Put the upper part of the baud number here (bits 8 to 11)
	UBRR0H = (u8) (UBRR >> 8);
	//Put the remaining part of the baud number here
	UBRR0L = UBRR & 0xFF;
	///////////////////////////////////////////////////////////////////////////////////////////
	switch (TransmissionState)
	{
		case HALF_dUPLEX_TRANSMISSION :
		UCSR0B |= (TransmissionState<<TXEN0);
		case HALF_dUPLEX_RECIEVING :
		UCSR0B |= (TransmissionState<<TXEN0);	
		case FULL_dUPLEX :
		UCSR0B |= (TransmissionState<<TXEN0);			
		
	}
	*/
	//////////////////////////////////////////////////////////////////////////////////////////////////
	switch (Mode)
	{
		case ASYNCHRONOUS_MODE :
		UCSR0C |= Mode <<UMSEL00;
		case SYNCHRONOUS_MODE :
		UCSR0C |= Mode <<UMSEL00;	
	}


//////////////////////////////////////////////////////////////////////////////////////////////////	  
	switch (DataSize)
	{
	case UART_5BIT :
	UCSR0C |= DataSize <<UCSZ00;
	case UART_6BIT :
	UCSR0C |= DataSize <<UCSZ00;
	case UART_7BIT :
	UCSR0C |= DataSize <<UCSZ00;
	case UART_8BIT :
	UCSR0C |= DataSize <<UCSZ00;		
	}

	////////////////////////////////////////////////////////////////////////////////////////////////
	switch (Parity)
	{
		case NO :
		UCSR0C |= Parity <<UPM00;
		case EVEN :
		UCSR0C |= Parity <<UPM00;
		case ODD :
		UCSR0C |= Parity <<UPM00;
		
	}
	////////////////////////////////////////////////////////////////////////////////////////////////
	if (StopBit==2)  {SET_BIT(UCSR0C,USBS0);}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MUART_voidTransmitChar (char Transmitted_Data)
{ 
	while (GET_BIT(UCSR0A,UDRE0)==0);
	UDR0 = Transmitted_Data;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
char MUART_charReceiveChar (){

while (GET_BIT(UCSR0A,RXC0)  ==0 );
	return UDR0 ;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MUART_voidTransmitString (char* Transmitted_Data){	
//int l =strlen(Transmitted_Data);
	while(*Transmitted_Data != '\0')
	{
		MUART_voidTransmitChar (*Transmitted_Data);
		Transmitted_Data++;
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MUART_voidSetCallBack(u8 InterruptType, void *Ptr )
{
	if (Ptr == NULL)
	return;
	if(InterruptType == UART_RX_INTERRUPT)
	{
		ReceiveHandle = (void (*)(char))Ptr;
	}
	else if(InterruptType == UART_TX_INTERRUPT)
	{
		TransmitHandle = (void (*)(void))Ptr;
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MUART_voidEnableRXInterrupt(void){
	sei();
	SET_BIT(UCSR0B,RXCIE0);
}
void MUART_voidDisableRXInterrupt(void){
   cli();
   CLR_BIT(UCSR0B,RXCIE0);	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MUART_voidEnableTXInterrupt(void){
	sei();
	SET_BIT(UCSR0B,TXCIE0);
}
void MUART_voidDisableTXInterrupt(void){
   cli();
   CLR_BIT(UCSR0B,TXCIE0);	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//UDRIE0
void MUART_voidEnableDataEmptyInterrupt(void){
	sei();
	SET_BIT(UCSR0B,UDRIE0);
}
void MUART_voidDisableDataEmptyInterrupt(void){
	cli();
	CLR_BIT(UCSR0B,UDRIE0);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MUART_voidReadString(char*Location, u32 Len,u32 Timeout){
void MUART_voidEnableRXInterrupt(void);
for(int i=0;i<=Len ; i++)	
{
MUART_voidSetCallBack(UART_RX_INTERRUPT , Location );
	Location++;
	if ( i == Timeout){
		return;
	}
}
}
//	SET_BIT(UCSR0A, UDRE0); TRANS
//CLR_BIT(UCSR0A, UDRE0);
	/*
	for(int i=0 ;i<=l;i++)
	{
		MUART_voidTransmitChar (Transmitted_Data);
	}
}
*/


ISR(USART_RX_vect)
{
	if(ReceiveHandle != NULL)
		ReceiveHandle(UDR0);
};

ISR (USART_TX_vect)
{
	if(TransmitHandle != NULL)
		TransmitHandle();
	SET_BIT(UCSR0A,6);
};

