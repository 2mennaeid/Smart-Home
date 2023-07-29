/*
 * ADC_Prog.c
 *
 * Created: 11/03/2023 06:11:39 م
 *  Author: Menna Eid
 */ 
#include "../DIO/StdTypes.h"
#include "../DIO/Registers1.h"
#include "../DIO/errorstate.h"
#include "../DIO/DIO_priv.h"
#include "../DIO/DI0_interface.h"
#include "../External_Interrupt/interrupt.h"
#include "ADC_priv.h"
#include "ADC_Init.h"
static void (*INT0_ADC) (void*) = NULLPTR;
static void *ADC_pvoid = NULLPTR;
ES_t ADC_euInit(ADC_enTypesVref type, ADC_enTypeAdjustment adjust_val , ADC_enTypePrescaler pres_value)
{
	ES_t LocalErrorState = ES_OK;
	// enable adc
	ADCSRA |= (1<<ADEN);
	// select Vref
	switch(type)
	{
		case AREF:
			ADMUX &= ~(1<<REFS0);
			ADMUX &= ~(1<<REFS1);
			break;
		case AVCC:
			ADMUX &= ~(1<<REFS1);
			ADMUX |= (1<<REFS0);
			break;
		case Internal_VREF:
			ADMUX |= (1<<REFS1);
			ADMUX |= (1<<REFS0);
			break;				
	}
	switch(pres_value)
	{
		case Prescaler_8:
			ADCSRA |=  (1<<ADPS0);
			ADCSRA |=  (1<<ADPS1);
			ADCSRA &= ~(1<<ADPS2);
			break;
		case Prescaler_16:
			ADCSRA &= ~(1<<ADPS0);
			ADCSRA &= ~(1<<ADPS1);
			ADCSRA |= (1<<ADPS2);
			break;
		case Prescaler_32:
			ADCSRA |=  (1<<ADPS0);
			ADCSRA &= ~(1<<ADPS1);
			ADCSRA |= (1<<ADPS2);
			break;
	}
	if(adjust_val==Right_Adjustment)
	{
		 ADMUX &= ~(1<<ADLAR); // ADLAR
	}
	else if(adjust_val==Left_Adjustment)
	{
		ADMUX |= (1<<ADLAR);
	}
		
	return LocalErrorState;
}
ES_t ADC_SelectChannel(ADC_enCHANNELS enChannelId)
{
	ES_t LocalErrorState = ES_OK;
		// ADC channels
		ADMUX &= ~(0x1F); // Masking
		switch(enChannelId)
		{
			case ADC0:
				ADMUX |=0;
				break;
			case ADC1:
				ADMUX |=1;
				break;
			case ADC2:
				ADMUX |=2;
				break;
		   case ADC3:
				ADMUX |=3;
				break;
		   case ADC4:
				ADMUX |=4;
				break;
		   case ADC5:
				ADMUX |=5;
				break;
		   case ADC6:
				ADMUX |=6;
				break;
			case ADC7:
				ADMUX |=7;
				break;
		}
	return LocalErrorState;
}
ES_t ADC_enStartConversion()
{
	ES_t LocalErrorState = ES_OK;
	
     ADCSRA |=(1<<ADSC);
	
	return LocalErrorState;
}
ES_t ADC_enPollingSystem(void)
{
	ES_t LocalErrorState = ES_OK;
	
	while(((ADCSRA>>ADIF)&1) == 0);
	
	return LocalErrorState;
}

ES_t ADC_euReadADC(uint8_t *value)
{
	ES_t LocalErrorstate = ES_OK;
	if(((ADMUX>>ADLAR)&1)==0) // right
	{
		*value = (ADCL>>2);
		*value |= (ADCH<<6);
		
	}
	else if(((ADMUX>>ADLAR)&1)==1) // left
	{
		*value = ADCH;
	}
	ADCSRA &= ~(1<<ADIF); // clear flag
	return LocalErrorstate;
	
}
ES_t ADC_enReadHighValue(u16_t *value)
{
	ES_t LocalErrorstate = ES_OK;
	if(((ADMUX>>ADLAR)&1)==0) // right
	{
		*value  = ADCL;
		*value |= ((u16_t)ADCH<<8);
	}
	else if(((ADMUX>>ADLAR)&1)==1) // left
	{
		*value  = (ADCL>>6);
		*value |= (ADCH<<2);
	}
	ADCSRA &= ~(1<<ADIF); // clear flag
	return LocalErrorstate;
}

float ADC_AnalogVal(u16_t value,ADC_enTypesVref type)
{
	float volatile _Analog;
	switch(type)
	{
		case AVCC:
			_Analog = ( value *(5000ul))/1024.0;
			break;
		case AREF:
			_Analog = ( value *(5000ul))/1024.0;
			break;
		case Internal_VREF:
			_Analog = ( value *(2.56))/1024.0;
			break;
	}
	return _Analog;
}
ES_t ADC_enEnableTriggeringMode(ADC_enTriggeringTypes en_TriggerId)
{
	ES_t LocalErrorState = ES_OK;
	ADCSRA &= ~(1<<ADATE); //clear trigger 
	switch(en_TriggerId)
	{
		case FREE_RUNNING:
			SFIOR &= ~(1<<ADTS2);
			SFIOR &= ~(1<<ADTS1);
			SFIOR &= ~(1<<ADTS0);
			break;
		case EX_IN:
			SFIOR &= ~(1<<ADTS2);
			SFIOR |= (1<<ADTS1);
			SFIOR &= ~(1<<ADTS0);
			break;
	}
	ADCSRA |= (1<<ADATE); // enable trigger
	return LocalErrorState;
}
ES_t ADC_enDisableTriggeringMode(void)
{
	ES_t LocalErrorState = ES_OK;
	ADCSRA &= ~(1<<ADATE);
	return LocalErrorState;
}
ES_t ADC_enEnableInterruptMode(void)
{
	ES_t LocalErrorState = ES_OK;
	ADCSRA |= (1<<ADIE);
	return LocalErrorState;
}
ES_t ADC_enCallBack(void(*Localptrfunc)(void*),void *Localptr)
{
	ES_t LocalErrorState = ES_OK;
	if(Localptrfunc!=NULLPTR)
	{
		INT0_ADC = Localptrfunc;
		ADC_pvoid = Localptr;
	}
	
	return LocalErrorState;
}

ISR(VECT_ADC)
{
	INT0_ADC(ADC_pvoid);
}
