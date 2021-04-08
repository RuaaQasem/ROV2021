/*
 * UART_interface.h
 *
 * Created: 2/8/2021 10:43:51 PM
 *  Author: Laptop Market
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_



/*Data Length*/
#define UART_5BIT						0
#define UART_6BIT						1
#define UART_7BIT						2
#define UART_8BIT						3

// interrupt enable
#define UART_RX_INTERRUPT				0
#define UART_TX_INTERRUPT				1
#define UART_DATA_REG_EMPTY_INTERRUPT	2

//UART modes
#define  ASYNCHRONOUS_MODE  0
#define  SYNCHRONOUS_MODE   1

/*Transmission state*/
#define HALF_dUPLEX_TRANSMISSION  		1
#define HALF_dUPLEX_RECIEVING			2
#define FULL_dUPLEX						3

/*Parity Bit*/
#define NO			0
#define ODD			1
#define EVEN	    2



void MUART_voidUartIntialization (u8 state , u8 mode, u8 DataSize, u8 parity, u8 StopBit);
void MUART_voidTransmitChar (char Transmitted_Data);
char MUART_charReceiveChar (void);
void MUART_voidTransmitString (char* Transmitted_Data);
void MUART_voidSetCallBack(u8 InterruptType, void *Handle);


/*Enable and disable Receive completed Interrupt*/
void MUART_voidEnableRXInterrupt(void);
void MUART_voidDisableRXInterrupt(void);

/*Enable and disable Transmit completed Interrupt*/
void MUART_voidEnableTXInterrupt(void);
void MUART_voidDisableTXInterrupt(void);

/*Enable and disable Data Register Empty Interrupt*/
void MUART_voidEnableDataEmptyInterrupt(void);
void MUART_voidDisableDataEmptyInterrupt(void);

/*reads a string with length Len from the u art*/
void MUART_voidReadString(char*Location, u32 Len,u32 Timeout);



#endif /* UART_INTERFACE_H_ */