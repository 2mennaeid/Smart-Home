/*
 * EX_Intrrupt_priv.h
 *
 * Created: 27/02/2023 08:04:19 م
 *  Author: Pc
 */ 


#ifndef EX_INTRRUPT_PRIV_H_
#define EX_INTRRUPT_PRIV_H_


typedef enum {
	EX_INT0=0,
	EX_INT1,EX_INT2
	
 }EX_TYPESOURCE;

typedef enum {
	FALLING_EDGE=0,
	RISING_EDGE,
	LOGICAL_CHANGE,
	LOW_LEVEL
	}EX_SENCE_MODE;

#define ISC2  6
#define ISC00 0
#define ISC01 1
#define ISC10 2	
#define ISC11 3				
#define INT0 6
#define INT1 7
#define INT2 5


#endif /* EX_INTRRUPT_PRIV_H_ */