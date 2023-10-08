/*
 * Led_priv.c
 *
 * Created: 30/01/2023 03:16:09 م
 *  Author: Menna Eid
 */
#include "../../MCAL/DIO/StdTypes.h" 
#include "../../MCAL/DIO/Registers1.h"
#include "../../MCAL/DIO/DIO_priv.h"
#include "../../MCAL/DIO/errorstate.h"
#include "Led_priv.h"
#include "../../MCAL/DIO/DI0_interface.h"
//#include "Led_interface.h"
ES_t led_init(uint8_t ledport,uint8_t ledpin){
	ES_t LocalErrorstate;
	if(ledport>='A' && ledport<='D')
	{
		DIO_SetPinDirection(ledport,ledpin,OUT);
		LocalErrorstate=ES_OK;
	}
	else
	{
		LocalErrorstate=ES_NOK;
	}
	return LocalErrorstate;
}
ES_t led_on(uint8_t ledport,uint8_t ledpin,uint8_t type_connection)
{
	ES_t LocalErrorstate;
	if(ledport>='A' && ledport<='D')
	{
		if(type_connection==source)//source
		{
			DIO_SetPinValue(ledport,ledpin,HIGH);
		}
		else
		{
			DIO_SetPinValue(ledport,ledpin,LOW);
		}
		LocalErrorstate=ES_OK;
	}
	else
	{
		LocalErrorstate=ES_NOK;
	}
	return LocalErrorstate;
}
ES_t led_of(uint8_t ledport,uint8_t ledpin,uint8_t type_connection)
{
	ES_t LocalErrorstate;
	if(ledport>='A' && ledport<='D')
	{
		if(type_connection==source)//source
		{
			DIO_SetPinValue(ledport,ledpin,LOW);
		}
		else if(type_connection==sink)
		{
			DIO_SetPinValue(ledport,ledpin,HIGH);
		}
		LocalErrorstate=ES_OK;
	}
	else
	{
		LocalErrorstate=ES_NOK;
	}
	return LocalErrorstate;
}


