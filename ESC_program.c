/*
 * ESC_program.c
 *
 * Created: 4/10/2021 11:57:32 AM
 *  Author: Laptop Market
 */ 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <string.h>
#include <avr/io.h>
#include "TIMER_interface.h"
#include "TIMER_private.h"
#include "TIMER_config.h"
#include "ESC_interface.h"
#include "ESC_private.h"
#include "ESC_config.h"
#include <util/delay.h>

struct esc 
{   u8 channel ;
	u8 timer ;
	u8 port ;
	u8 pin ;
	u8 feedback_speed ;	
	};
	void HESC_voidInit(esc * ptr_esc , bool Delay )
	{
		MTIMER_voidInit(MODE_ESC , ptr_esc->timer ,MODE_OPTION_ESC , PRESCALER_ESC );
		u8 duty_cycle = 1500/TIMER_TICK_TIME *100 ;
		MTIMERn_voidSetDutyCycle( duty_cycle , ptr_esc->timer ,ptr_esc->channel);
		if (Delay)
		_delay_ms(7000);	
	}
	void HESC_voidSetMotorSpeed(char speed , esc * ptr_esc)
	{   char esc_speed = (4 * speed) + 1500 ; 
		u8 duty_cycle = esc_speed / TIMER_TICK_TIME * 100 ;
		MTIMERn_voidSetDutyCycle( duty_cycle , ptr_esc->timer ,ptr_esc->channel);	
	}