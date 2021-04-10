/*
 * BIT_MATH.h
 *
 * Created: 4/10/2021 11:44:49 AM
 *  Author: Laptop Market
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define BIT_SET (VAR,BIT)        (VAR |= (1<<BIT))
#define BIT_CLR (VAR,BIT)        (VAR &= ~(1<<BIT))
#define BIT_TOG (VAR,BIT)        (VAR ^= (1<<BIT))
#define BIT_GET (VAR,BIT)        ((VAR>>BIT) & 1)



#endif /* BIT_MATH_H_ */