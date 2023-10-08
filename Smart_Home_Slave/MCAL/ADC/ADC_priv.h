/*
 * ADC_priv.h
 *
 * Created: 11/03/2023 06:12:07 
 *  Author: Menna Eid
 */ 


#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_


typedef enum
{
	Prescaler_8,
	Prescaler_16,
	Prescaler_32
	}ADC_enTypePrescaler;

typedef enum
{
	 Right_Adjustment=0,
	 Left_Adjustment
	}ADC_enTypeAdjustment;
typedef enum
{
	AVCC=0,
	Internal_VREF,
	AREF	
}ADC_enTypesVref;

typedef enum
{
	ADC0=0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7
	
	}ADC_enCHANNELS;
typedef enum
{
	FREE_RUNNING=0,
	EX_IN
	//Analog_Comparator
	//Timer_Counter0_Compare_Match,
	//Timer_Counter0_Overflow,
	//Timer_Counter1_Capture_Event
	
	}ADC_enTriggeringTypes;	
// define bits in ADCSRA Register
#define  ADEN	7	   // ADC Enable
#define  ADSC	6    // start conversion
#define	 ADATE	5   // adc outo triggering
#define	 ADIF   4  // adc interrupt flag
#define  ADIE   3 // adc Enable interrupt flag
 // bits of prescaler 
#define  ADPS2  2
#define  ADPS1  1
#define  ADPS0  0
// define SFIOR Register
#define ADTS2	7
#define ADTS1	6
#define ADTS0	5

// ADC Multiplexer Register
#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define MUX4  4
#define REFS0 6
#define REFS1 7
#define ADLAR 5 // ADC Left Adjust Result
#endif /* ADC_PRIV_H_ */