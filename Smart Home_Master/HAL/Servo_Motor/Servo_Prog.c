/*
 * Servo_Prog.c
 *
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
void Servo_Init(TIMER1_PRESCALER enupres_val,TIMER1_SELECTMODE enuMode,Timer1_CompareOutMode enu_outputcompare)
{
	Timer1_SelectMode(enuMode);
	Timer1FastPWM_SelectOutPutCompareMatch(enu_outputcompare);
	Timer1_SelectPrescaler(enupres_val);
	Timer1_FrequancyValue(50);
}

void Servo_Speed(f32 f32duty)
{
	Timer1_Fast_PWM(f32duty);
	DIO_SetPinDirection(PORT_D,PIN4,OUT);
	DIO_SetPinDirection(PORT_D,PIN5,OUT);
}