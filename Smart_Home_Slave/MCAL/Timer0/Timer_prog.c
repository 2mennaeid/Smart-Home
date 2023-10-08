/*
 * Timer_prog.c
 *
 * Created: 6/22/2023 6:21:14 AM
 *  Author: Menna Eid
 */ 
#include "../DIO/StdTypes.h"
#include "../DIO/Registers1.h"
#include "../DIO/errorstate.h"
#include "../External_Interrupt/interrupt.h"
#include "Timer_priv.h"
#include "Timer_Init.h"
f32 num_ovf;
u32_t  preload;
f32 Time_ovf;

static void (*gptr) (void*) = NULLPTR;
static void * gparameter = NULLPTR; 
static void (*gptr_ctc) (void*) = NULLPTR;
static void * gparameter_ctc = NULLPTR;
f32 Timer_enCalC_OVF(f32 f32delay)
{
	f32 Num_ovf = f32delay / Time_ovf;
	 return Num_ovf;
	
}
ES_t TimerOVF_enSeDelay(f32 f32delay)
{
	
	ES_t LocalErrorstate = ES_OK;
	num_ovf = Timer_enCalC_OVF(f32delay);
		if((num_ovf-(u32_t)num_ovf)!=0)
		{
			preload = counts_Timer - ((num_ovf-(u32_t)num_ovf)*counts_Timer);
			TCNT0 = preload;
			num_ovf =(u32_t)num_ovf+1;
			while(num_ovf>0)
			{
				while(((TIFR>>TOV0)&1)==0);
				TIFR |= (1<<TOV0);
				num_ovf--;
			}
		}
		else
		{
			num_ovf = (u32_t)num_ovf;
			while(num_ovf>0)
			{
				while(((TIFR>>TOV0)&1)==0);
				TIFR |= (1<<TOV0);
				num_ovf--;
			}
			
		}
		
	return LocalErrorstate;
	
}
ES_t TimerOVF_enASeDelay(f32 f32delay,void (*Localtptrfunc)(void*),void *parameter)
{
	ES_t LocalErrorstate =ES_OK;
		num_ovf = Timer_enCalC_OVF(f32delay);
		if((num_ovf-(u32_t)num_ovf)!=0)
		{
			preload = counts_Timer - ((num_ovf-(u32_t)num_ovf)*counts_Timer);
			num_ovf =(u32_t)num_ovf+1;
		}
		else
		{
			num_ovf =(u32_t)num_ovf;
			preload = 0;
		}
			
	 if(Localtptrfunc != NULLPTR)
	 {
		 		gptr = Localtptrfunc;
				gparameter = parameter;
	 }
	return LocalErrorstate;
}
ES_t TimerCTC_enuASyDelay(f32 f32delay,void (*Localtptrfunc)(void*),void *parameter)
{
	ES_t LocalErrorstate = ES_OK;
	num_ovf = Timer_enCalC_OVF(f32delay);
    OCR0 =(num_ovf*counts_Timer);
	if(Localtptrfunc!=NULLPTR)
	{
		gptr_ctc = Localtptrfunc;
		gparameter_ctc = parameter;
	}
	
	return LocalErrorstate;
	
}
ES_t Timer_enSelectmode(TIMER_MODE IdMode)
{
	ES_t LocalErrorstate = ES_OK;
		switch(IdMode)
		{
			case OVF:
				TCCR0 &= ~(1<<WGM01);
				TCCR0 &= ~(1<<WGM00);
				TCCR0 &= ~(1<<COM00);
				TCCR0 &= ~(1<<COM01);
				break;
			case FPWM:
				TCCR0 |= (1<<WGM00);
				TCCR0 |= (1<<WGM01);
				break;
			case CTC:
				TCCR0 |= (1<<WGM01);
				TCCR0 &= ~(1<<WGM00);
				break;
			case PhaseCorrect:
				 TCCR0 |= (1<<WGM00);
				 TCCR0 &= ~(1<<WGM01);
				 break;
				
				
		}
	return LocalErrorstate;
}
ES_t Timer_enSelectPrescaler(TIMER_PRESCALER pres_val)
{
	ES_t LocalErrorstate = ES_OK;
	 switch(pres_val)
	 {
		 case Timer0_Prescaler_8:
			TCCR0 &= ~(1<<CS00);
			TCCR0 |= (1<<CS01);
			TCCR0 &= ~(1<<CS02);
			Time_ovf = counts_Timer * ((f32)8/frequency);
			break;
		case Timer0_Prescaler_64:
			TCCR0 |= (1<<CS00);
			TCCR0 |= (1<<CS01);
			TCCR0 &= ~(1<<CS02);
			Time_ovf = counts_Timer * ((f32)64/frequency);
			break;
		case Timer0_Prescaler_256:
			TCCR0 &= ~(1<<CS00);
			TCCR0 &= ~(1<<CS01);
			TCCR0 |= (1<<CS02);
			Time_ovf = counts_Timer * ((f32)256/frequency);
			break;
		case Timer0_Prescaler_1024:
			TCCR0 |= (1<<CS00);
			TCCR0 &= ~(1<<CS01);
			TCCR0 |= (1<<CS02);
			Time_ovf = counts_Timer * ((f32)1024/frequency);
			break;
		case Timer0_NO_Prescaling:
			TCCR0 |= (1<<CS00);
			TCCR0 &= ~(1<<CS01);
			TCCR0 &= ~(1<<CS02);
			Time_ovf = counts_Timer * ((f32)1/frequency);
			break;
	 }
	return LocalErrorstate;
}
ES_t TimerCTC_enuSelectCompare_Output_Mode(Timer_CompareOutMode ctc_value)
{
	ES_t LocalErrorstate = ES_OK;
	switch(ctc_value)
	{
		case Toggle:
			TCCR0 |= (1<<COM00);
			TCCR0 &= ~(1<<COM01);
			break;
		case Clear:
			TCCR0 &= ~(1<<COM00);
			TCCR0 |= (1<<COM01);
			break;
		case Set:
			TCCR0 |= (1<<COM00);
			TCCR0 |= (1<<COM01);
			break;
		default:
			TCCR0 &= ~(1<<COM00);
			TCCR0 &= ~(1<<COM01);
			break;
	}
	return LocalErrorstate;
}
ES_t TimerFPWM_enuSelectCompare_Output_Mode(Timer_CompareOutMode fpwm_value)
{
	ES_t LocalErrorstate = ES_OK;
	switch(fpwm_value)
	{
		case NON_INVERTING:
			 TCCR0 &= ~(1<<COM00);
			 TCCR0 |= (1<<COM01);
			 break;
		case INVERTING:
			TCCR0 |= (1<<COM00);
			TCCR0 |= (1<<COM01);
			break;
		default:
			TCCR0 &= ~(1<<COM00);
			TCCR0 &= ~(1<<COM01);
			break;
	}
	return LocalErrorstate;
}
ES_t TimerFPWM_enuCalc_OCR(f32 f32duty,Timer_DutyType value)
{
	uint8_t ocr=0;
	ES_t LocalErrorstate =ES_OK;
	  switch(value)
	  {
		  case ON:
		     ocr = (f32duty*counts_Timer);
			 OCR0  = ocr;
		     break;
		   case OFF:
			 OCR0 = (((f32duty*counts_Timer) - counts_Timer)/-1);
			 break;
			
	  }
	return LocalErrorstate;
}
ES_t TimerPhaseCorrect_enuSelectCompare_Output_Mode(Timer_CompareOutMode phase_value)
{
	ES_t LocalErrorstate = ES_OK;
	switch(phase_value)
	{
		case INVERTING:
			TCCR0 |= (1<<COM00);
			TCCR0 |= (1<<COM01);
			break;
		case NON_INVERTING:
			TCCR0 &= ~(1<<COM00);
			TCCR0 |= (1<<COM01);
			break;
		default:
			TCCR0 &= ~(1<<COM00);
			TCCR0 &= ~(1<<COM01);
			break;
	}
	return LocalErrorstate;
}
ES_t TimerPhaseCorrect_enuCalc_OCR(uint8_t u8duty,Timer_DutyType value)
{
	ES_t LocalErrorstate = ES_OK;
	switch(value)
	{
		case ON:
		OCR0  = ((counts_Timer_phasecorrect*(u8duty/100))/2);
		break;
		case OFF:
		OCR0  = (counts_Timer_phasecorrect/2) - ((counts_Timer_phasecorrect*(u8duty/100))/2);
		break;
		
	}
	return LocalErrorstate;
}
ES_t TimerOVF_enEnableInterrupt()
{
	ES_t localErrorstate = ES_OK;
	TIMSK |= (1<<TOIE0);
	return localErrorstate;
}
ES_t TimerOVF_enDisableInterrupt()
{
	ES_t localErrorstate = ES_OK;
	TIMSK &= ~(1<<TOIE0);
	return localErrorstate;
}
ES_t TimerCTC_enEnableInterrupt()
{
	ES_t localErrorstate = ES_OK;
	TIMSK |= (1<<OCIE0);
	return localErrorstate;
}
ISR(VECT_TIMER0_OVF)
{
	if(gptr!=NULLPTR)
	{
		static u32_t counts = 0;
		counts++;
		if(counts==num_ovf)
		{
			TCNT0=preload;
			counts=0;
			gptr(gparameter);
		}
	}
}
ISR(VECT_TIMER0_CTC)
{
	if(gptr_ctc!=NULLPTR)
	{
		gptr_ctc(gparameter_ctc);
	}
}