/*
 * BUZ_Prog.c
 *
 * Created: 7/28/2023 10:05:01 PM
 *  Author: Menna Eid
 */ 
#include "../../MCAL/DIO/StdTypes.h"
#include "../../MCAL/DIO/Registers1.h"
#include "../../MCAL/DIO/errorstate.h"
#include "../../MCAL/DIO/DIO_priv.h"
#include "../../MCAL/DIO/DIO_confg.h"
#include "../../MCAL/DIO/DI0_interface.h"

void BUZZER_Init(uint8_t buzport,uint8_t buzpin)
{
	DIO_SetPinDirection(buzport,buzpin,OUT);
}

void BUZZER_ON(uint8_t buzport,uint8_t buzpin)
{
	DIO_SetPinValue(buzport,buzpin,HIGH);
}

void BUZZER_OF(uint8_t buzport,uint8_t buzpin)
{
	DIO_SetPinValue(buzport,buzpin,LOW);
}