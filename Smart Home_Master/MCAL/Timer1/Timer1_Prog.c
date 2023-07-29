/*
 * Timer1_Prog.c
 *
 * Created: 7/27/2023 3:50:27 PM
 *  Author: Menna Eid
 */ 
#include "../DIO/Registers1.h"
#include "../DIO/StdTypes.h"
#include "../DIO/errorstate.h"
#include "../DIO/DIO_priv.h"
#include "Timer1_Priv.h"
#include "Timer1_Init.h"
u16_t counts;
u16_t ocrx;
f32 Time_sys;
void Timer1_Fast_PWM(f32 f32duty_Value)
{
	Timer1_FastPWM_CalC_OCRX(f32duty_Value);
	
}
void Timer1_FrequancyValue(uint8_t u8Frequancy_value)
{
	 f32 Time = ((f32)1/u8Frequancy_value);
	 counts = Time / Time_sys;
	 OCR1AH = ((counts & 0xFF00)>>8);
	 OCR1AL = counts;
}
void Timer1_FastPWM_CalC_OCRX(f32 f32duty_Value)
{
	ocrx = f32duty_Value*(counts+1);
		OCR1BH = ((ocrx & 0xFF00)>>8);
		OCR1BL = ocrx;
	
}
void Timer1_SelectPrescaler(TIMER1_PRESCALER enupres_val)
{
	switch(enupres_val)
	{
		case Timer1_Prescaler_8:
			 TCCR1B &= ~(1<<CS10);
			 TCCR1B |= (1<<CS11);
			 TCCR1B &= ~(1<<CS12);
			 Time_sys = (f32)8/8000000UL;
			 break;
		case Timer1_Prescaler_64:
			 TCCR1B |= (1<<CS10);
			 TCCR1B |= (1<<CS11);
			 TCCR1B &= ~(1<<CS12);
			 Time_sys = (f32)64/8000000UL;
			 break;
		case Timer1_Prescaler_256:
		     TCCR1B &= ~(1<<CS10);
		     TCCR1B &= ~(1<<CS11);
		     TCCR1B |= (1<<CS12);
			 Time_sys = (f32)256/8000000UL;
		     break;
		case Timer1_Prescaler_1024:
			 TCCR1B |= (1<<CS10);
			 TCCR1B &= ~(1<<CS11);
			 TCCR1B |= (1<<CS12);
			 Time_sys = (f32)1024/8000000UL;
			 break;
		case Timer1_NO_Prescaling:
			TCCR1B |= (1<<CS10);
			TCCR1B &= ~(1<<CS11);
			TCCR1B &= ~(1<<CS12);
			Time_sys = (f32)1/8000000UL;
			break;
	}
}
 
void Timer1_SelectMode(TIMER1_SELECTMODE enuMode)
{
	switch(enuMode)
	{
		case MODE_1:
			TCCR1A |= (1<<WGM10);
			TCCR1A &= ~(1<<WGM11);
			TCCR1B &= ~(1<<WGM12);
			TCCR1B &= ~(1<<WGM13);
			break;
		case MODE_5:
			 TCCR1A |= (1<<WGM10);
			 TCCR1A &= ~(1<<WGM11);
			 TCCR1B |= (1<<WGM12);
			 TCCR1B &= ~(1<<WGM13);
			 break;
		case MODE_8:
			 TCCR1A &= ~(1<<WGM10);
			 TCCR1A &= ~(1<<WGM11);
			 TCCR1B &= ~(1<<WGM12);
			 TCCR1B |= (1<<WGM13);
			 break;
		case MODE_9:
			 TCCR1A |= (1<<WGM10);
			 TCCR1A &= ~(1<<WGM11);
			 TCCR1B &= ~(1<<WGM12);
			 TCCR1B |= (1<<WGM13);
			 break;
		case MODE_10:
			 TCCR1A &= ~(1<<WGM10);
			 TCCR1A |= (1<<WGM11);
			 TCCR1B &= ~(1<<WGM12);
			 TCCR1B |= (1<<WGM13);
			 break;
		case MODE_14:
			 TCCR1A &= ~(1<<WGM10);
			 TCCR1A |= (1<<WGM11);
			 TCCR1B |= (1<<WGM12);
			 TCCR1B |= (1<<WGM13);
			 break;
		case MODE_15:
			 TCCR1A |= (1<<WGM10);
			 TCCR1A |= (1<<WGM11);
			 TCCR1B |= (1<<WGM12);
			 TCCR1B |= (1<<WGM13);
			 break;
	}
}

void Timer1FastPWM_SelectOutPutCompareMatch(Timer1_CompareOutMode enu_outputcompare)
{
	switch(enu_outputcompare)
	{
		case Timer1_INVERTING:
			 TCCR1A |= (1<<COM1B0);
			 TCCR1A |= (1<<COM1B1);
			 break;
		case Timer1_NON_INVERTING:
			 TCCR1A &= ~(1<<COM1B0);
			 TCCR1A |= (1<<COM1B1);
			 break;
	}
}