/*
 * Servo_Prog.c
 * version : 2.0
 * Created: 7/25/2023 11:25:14 AM
 *  Author: Menna Eid
 */ 
#include "../../MCAL/DIO/StdTypes.h"
#include "../../MCAL/DIO/Registers1.h"
#include "../../MCAL/DIO/errorstate.h"
#include "../../MCAL/DIO/DIO_priv.h"
#include "../../MCAL/DIO/DIO_confg.h"
#include "../../MCAL/DIO/DI0_interface.h"
#include "../../MCAL/Timer1/Timer1_Priv.h"
#include "../../MCAL/Timer1/Timer1_Init.h"
#include "Servo_Init.h"
void Servo_voidInit()
{
	Timer1_voidSelectMode(MODE_15);
	Timer1_voidSelectPrescaler(Timer1_Prescaler_8);
	Timer1FastPWM_voidSelectOutPutCompareMatch(Timer1_NON_INVERTING,Timer1_NON_INVERTING);
	Timer1_voidFastPWM_MODE15_SetOCRA(50);
	DIO_SetPinDirection(PORT_D,PIN4,OUT);
	DIO_SetPinDirection(PORT_D,PIN5,OUT);
}

void Servo_voidSetAngle(uint8_t Copy_u8angle)
{
	switch(Copy_u8angle)
	{
		case 0:
		Timer1_FastPWM_Mode15_SetDuty(0.05);
		break;
		case 90:
		Timer1_FastPWM_Mode15_SetDuty(0.075);
		break;
		case 180:
		Timer1_FastPWM_Mode15_SetDuty(0.1);
		break;
	}
}