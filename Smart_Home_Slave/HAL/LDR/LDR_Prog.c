/*
 * LDR_Prog.c
 *
 * Created: 7/23/2023 10:18:43 AM
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
#include "LDR_Priv.h"
#include "LDR_Init.h"
ES_t LDR_enuInit(ADC_enCHANNELS enChannelId)
{
	ES_t LocalErrorstate = ES_NOK;
	DIO_SetPinDirection(PORT_A,enChannelId,IN);
	if(enChannelId>=ADC0 && enChannelId<=ADC7)
	{
		ADC_SelectChannel(enChannelId);
		LocalErrorstate = ES_OK;
	}
	
	return LocalErrorstate;
}

void LDR_SychGetResistanceValue(u16_t*Copy_u16value)
{
	u16_t _Vout;
	u16_t _Vin;
	ADC_enStartConversion();
	ADC_enPollingSystem();
	ADC_enReadHighValue(&_Vout);
	_Vout = (_Vout/1024)*5;
	*Copy_u16value = (_Vout*1000)/(5-_Vout);
}

void LDR_SychVoltageValue(u16_t*Copy_u16value)
{
	u16_t _Vin;
	ADC_enStartConversion();
	ADC_enPollingSystem();
	ADC_enReadHighValue(Copy_u16value);
}