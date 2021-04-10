/*
 * ESC_interface.h
 *
 * Created: 4/10/2021 11:58:50 AM
 *  Author: Laptop Market
 */ 


#ifndef ESC_INTERFACE_H_
#define ESC_INTERFACE_H_
#include "TIMER_interface.h"
#define  MODE_ESC              FAST_PWM_MODE
#define  MODE_OPTION_ESC       NON_INVERTING
#define  PRESCALER_ESC         NO_PRESCALAR
void HESC_voidInit(esc * ptr_esc , bool Delay );
void HESC_voidSetMotorSpeed(char speed , esc * ptr_esc );


#endif /* ESC_INTERFACE_H_ */