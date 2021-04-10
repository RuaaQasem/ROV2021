/*
 * TIMER_interface.h
 *
 * Created: 4/10/2021 11:52:21 AM
 *  Author: Laptop Market
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
# define RESOLUTION          8
# define TIME_COUNT          256
# define OVERFLOW            255

//timer number
#define TIMER0   0
#define TIMER1   1
#define TIMER2   2
// timer modes
#define NORMAL_MODE              0
#define CTC_MODE                 1
#define FAST_PWM_MODE            2
#define PHASE_CORRECT_PWM_MODE   3

// Mode option
#define  INVERTING       3
#define  NON_INVERTING   2
// prescaler
#define NO_PRESCALAR   1
#define 8_PRESCALAR    2
#define 64_PRESCALAR   3
#define 256_PRESCALAR  4
#define 1024_PRESCALAR 5
// channel
#define CHANNELA       0
#define CHANNELB       1
void  MTIMER_voidInit(u8 Mode, u8 n , u8 ModeOption,u8 Prescalar_shift);
void  MTIMERn_voidSetDutyCycle(u16 DutyCycle , u8 n,u8 Channel); // write in ocr



#endif /* TIMER_INTERFACE_H_ */