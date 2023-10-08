/*
 * LM35_PROG.c
 *
 * Created: 7/7/2023 2:54:44 PM
 *  Author: Menna Eid
 */ 
#include "../../MCAL/DIO/StdTypes.h"
#include "../../MCAL/DIO/errorstate.h"
#include "../../MCAL/DIO/Registers1.h"
#include "../../MCAL/DIO/DIO_priv.h"
#include "../../MCAL/DIO/DIO_confg.h"
#include "../../MCAL/DIO/DI0_interface.h"
#include "../../MCAL/ADC/ADC_priv.h"
#include "../../MCAL/ADC/ADC_Init.h"
#include "LM35_Priv.h"
#include "LM35_Init.h"
void read(void*ptr)
{
	ADC_enReadHighValue((u16_t*)ptr);
	*(u16_t*)ptr = (*(u16_t*)ptr*MAX_ADC*1000ul)/MAX_ADC_RES;
}
ES_t Temp_enuInit(uint8_t Th_num)
{
	ES_t LocalErrorState = ES_NOK;
	DIO_SetPinDirection(PORT_A,Th_num,IN);
	if(Th_num>=ADC0 && Th_num<=ADC7)
	{
		ADC_SelectChannel(Th_num);
		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}
void Temp_enuASYchGetTemp_val(u16_t*Tem_value)
{
	ADC_enEnableInterruptMode();
	ADC_enEnableTriggeringMode(EX_IN);
	ADC_enCallBack(&read,Tem_value);
	ADC_enStartConversion();
}
void Temp_enuSychGetTemp_val(u16_t*Tem_value)
{
	ADC_enStartConversion();
	ADC_enPollingSystem();
	ADC_enReadHighValue(Tem_value);
	*Tem_value = ((*Tem_value)*MAX_ADC*1000ul)/MAX_ADC_RES;
}