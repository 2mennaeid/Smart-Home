/*
 * Timer_priv.h
 *
 * Created: 6/22/2023 6:07:56 AM
 *  Author: Menna Eid
 */ 


#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_
 
typedef enum{
	OVF=0,
	CTC,
	FPWM,
	PhaseCorrect
	}TIMER_MODE;
	
typedef enum
{
	Timer0_Prescaler_8,
	Timer0_Prescaler_64,
	Timer0_Prescaler_256,
	Timer0_Prescaler_1024,
	Timer0_NO_Prescaling
}TIMER_PRESCALER;
typedef enum
{
	Toggle,
	Clear,
	Set,
	INVERTING,
	NON_INVERTING
	
	}Timer_CompareOutMode;
typedef enum
{
	ON,
	OFF
	
	}Timer_DutyType;
#define frequency   (8000000uL)
#define counts_Timer 255
#define counts_Timer_phasecorrect   510
// bits in Timer/Counter Control Register TCCR0
#define CS00   0
#define CS01   1
#define CS02   2
#define WGM01  3
#define COM00  4
#define COM01  5
#define WGM00  6
#define FOC0   7

// bits in Timer/Counter Interrupt Flag Register(TIFR)
#define TOV0  0
#define OCF0  1
#define OCIE0 1
#define TOIE0 0







#endif /* TIMER_PRIV_H_ */