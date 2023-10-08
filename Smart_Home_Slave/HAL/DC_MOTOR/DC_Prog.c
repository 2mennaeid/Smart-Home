/*
 * DC_Prog.c
 *
 * Created: 7/13/2023 6:24:11 AM
 *  Author: Menna Eid
 */ 
#include "../../MCAL/DIO/StdTypes.h"
#include "../../MCAL/DIO/Registers1.h"
#include "../../MCAL/DIO/errorstate.h"
#include "../../MCAL/DIO/DIO_priv.h"
#include "../../MCAL/DIO/DIO_confg.h"
#include "../../MCAL/DIO/DI0_interface.h"
#include "../../MCAL/Timer0/Timer_priv.h"
#include "../../MCAL/Timer0/Timer_Init.h"
void DC_Init(uint8_t u8portId ,uint8_t u8pinnumber)
{
	DIO_SetPinDirection(u8portId,u8pinnumber,OUT);
	DIO_SetPinValue(u8portId,u8pinnumber,LOW);
}
void DC_Speed(f32 u8duty,TIMER_MODE enumode)
{
	if(enumode==FPWM)
	{
		Timer_enSelectPrescaler(Timer0_Prescaler_1024);
		Timer_enSelectmode(enumode);
		TimerFPWM_enuSelectCompare_Output_Mode(NON_INVERTING);
		TimerFPWM_enuCalc_OCR(u8duty,ON);
	}
	else if(enumode==PhaseCorrect)
	{
		Timer_enSelectPrescaler(Timer0_Prescaler_1024);
		Timer_enSelectmode(enumode);
		TimerPhaseCorrect_enuSelectCompare_Output_Mode(NON_INVERTING);
		TimerPhaseCorrect_enuCalc_OCR(u8duty,ON);
	}
}