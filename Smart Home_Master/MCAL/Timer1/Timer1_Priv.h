/*
 * Timer1_Priv.h
 *
 * Created: 7/27/2023 3:50:54 PM
 *  Author: Menna Eid
 */ 


#ifndef TIMER1_PRIV_H_
#define TIMER1_PRIV_H_

typedef enum
{
	Timer1_Prescaler_8,
	Timer1_Prescaler_64,
	Timer1_Prescaler_256,
	Timer1_Prescaler_1024,
	Timer1_NO_Prescaling
	
}TIMER1_PRESCALER;

typedef enum
{
	Timer1_INVERTING,
	Timer1_NON_INVERTING
	
}Timer1_CompareOutMode;


typedef enum
{
	MODE_1=0,
	MODE_5,
	MODE_8,
	MODE_9,
	MODE_10,
	MODE_14,
	MODE_15
	}TIMER1_SELECTMODE;
// bits in  TCCR1B
#define CS10   0
#define CS11   1
#define CS12   2
#define WGM12  3
#define WGM13  4
#define ICES1  6
#define ICNC1  7

// bits in  TCCR1A
#define WGM10  0
#define WGM11  1
#define FOC1B  2
#define FOC1A  3
#define COM1B0 4
#define COM1B1 5
#define COM1A0 6
#define COM1A1 7

#endif /* TIMER1_PRIV_H_ */