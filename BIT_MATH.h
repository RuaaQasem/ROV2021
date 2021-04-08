/*
 * BIT_MATH.h
 *
 * Created: 4/6/2021 12:54:47 PM
 *  Author: Laptop Market
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define SET_BIT(VAR,BIT)        (VAR |= (1<<BIT))
#define CLR_BIT(VAR,BIT)        (VAR &= ~(1<<BIT))
#define TOG_BIT(VAR,BIT)        (VAR ^= (1<<BIT))
#define GET_BIT(VAR,BIT)        ((VAR>>BIT) & 1)




#endif /* BIT_MATH_H_ */