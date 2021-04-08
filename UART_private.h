/*
 * UART_private.h
 *
 * Created: 2/8/2021 10:45:00 PM
 *  Author: Laptop Market
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_


#define UDRE0				5
#define UMSEL0				6
#define UMSEL1				7
void (*ReceiveHandle)(char) = NULL;
void (*TransmitHandle)(void) = NULL;




#endif /* UART_PRIVATE_H_ */