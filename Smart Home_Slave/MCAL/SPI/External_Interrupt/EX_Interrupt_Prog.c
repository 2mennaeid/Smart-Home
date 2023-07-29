/*
 * EX_Interrupt_Prog.c
 *
 * Created: 27/02/2023 08:03:43 
 *  Author: menna eid
 */ 
#include "../DIO/StdTypes.h"
#include "../DIO/Registers1.h"
#include "../DIO/errorstate.h"
#include "../DIO/DIO_priv.h"
#include "interrupt.h"
#include "EX_Intrrupt_priv.h"

static void (*INT0_PTR) (void*) = NULLPTR;
static void (*INT1_PTR) (void*) = NULLPTR;
static void (*INT2_PTR) (void*) = NULLPTR;
static void *EXI_pvoidGenricprameter[3] = {NULLPTR,NULLPTR,NULLPTR};

void EXI_SetCallBack(EX_TYPESOURCE EXI_type, void(*Localptrfunc)(void*),void*Localptr)
{
	switch(EXI_type)
	{
		case EX_INT0:
			INT0_PTR=Localptrfunc;
			EXI_pvoidGenricprameter[0]=Localptr;
			break;
		case EX_INT1:
			INT1_PTR=Localptrfunc;
			EXI_pvoidGenricprameter[1]=Localptr;
			break;
		case EX_INT2:
			INT2_PTR=Localptrfunc;
			EXI_pvoidGenricprameter[2]=Localptr;
			break;
	}
	
}

void Enable_EXInterrupt(EX_TYPESOURCE EX_type)
{
	switch(EX_type)
	{
		case EX_INT0:
			GICR |= (1<<INT0);
			break;
		case EX_INT1:
			GICR |= (1<<INT1);
			break;
		case EX_INT2:
			GICR |=(1<<INT2);
			break;
		 
			
	}
}
void Disable_EXInterrupt(EX_TYPESOURCE EX_type)
{
	switch(EX_type)
	{
		case EX_INT0:
			GICR &= ~(1<<INT0);
		break;
		case EX_INT1:
			GICR &= ~(1<<INT1);
		break;
		case EX_INT2:
			GICR &= ~(1<<INT2);
		break;
		
		
	}
}
void EXI_SetSenceMode(EX_TYPESOURCE EX_type,EX_SENCE_MODE Sence_type)
{
	switch(EX_type)
	{
		case EX_INT0:
		    switch(Sence_type)
			{
				case FALLING_EDGE:
					MCUCR &= ~(1<<ISC00);
					MCUCR |= (1<<ISC01);
					break;
				case RISING_EDGE:
					MCUCR |=(1<<ISC00);
					MCUCR |=(1<<ISC01);
					break;
				case LOW_LEVEL:
					MCUCR &= ~(1<<ISC00);
					MCUCR &= ~(1<<ISC01);
					break;
				case LOGICAL_CHANGE:
					MCUCR |= (1<<ISC00);
					MCUCR &= ~(1<<ISC01);
					break;	
				
			}
		break;
		case EX_INT1:
			 switch(Sence_type)
			 {
				 case FALLING_EDGE:
					 MCUCR &= ~(1<<ISC10);
					 MCUCR |= (1<<ISC11);
					 break;
				 case RISING_EDGE:
					 MCUCR |=(1<<ISC10);
					 MCUCR |=(1<<ISC11);
					 break;
				 case LOW_LEVEL:
					 MCUCR &= ~(1<<ISC10);
					 MCUCR &= ~(1<<ISC11);
					 break;
				 case LOGICAL_CHANGE:
					 MCUCR |= (1<<ISC10);
					MCUCR &= ~(1<<ISC11);
					break;
				 
			 }
		break;
		case EX_INT2:
			switch(Sence_type)
			{
				case FALLING_EDGE:
					MCUCSR &= ~(1<<ISC2);
					break;
				case RISING_EDGE:
					MCUCSR |= (1<<ISC2);
					break;
				default:
					MCUCSR &= ~(1<<ISC2);
					break;
			}
		break;
	}
}

ISR(INT0_vect)
{
	if(INT0_PTR!=NULLPTR)
	{
		INT0_PTR(EXI_pvoidGenricprameter[0]);
	}
	
}
ISR(INT1_vect)
{
	if(INT1_PTR!=NULLPTR)
	{
		INT1_PTR(EXI_pvoidGenricprameter[1]);
	}
	
}

ISR(INT2_vect)
{
	if(INT2_PTR!=NULLPTR)
	{
		INT2_PTR(EXI_pvoidGenricprameter[2]);
	}
	
}
