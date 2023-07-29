/*
 * Slave_Mode.c
 *
 * Created: 7/25/2023 3:51:22 PM
 *  Author: Menna Eid
 */ 

#include "../MCAL/DIO/StdTypes.h"
#include "../MCAL/DIO/Registers1.h"
#include "../MCAL/DIO/errorstate.h"
#include "../MCAL/DIO/DIO_priv.h"
#include "../MCAL/DIO/DIO_confg.h"
#include "../MCAL/DIO/DI0_interface.h"
#include "../MCAL/Timer0/Timer_priv.h"
#include "../MCAL/Timer0/Timer_Init.h"
#include "../MCAL/SPI/SPI_Priv.h"
#include "../MCAL/SPI/SPI_Config.h"
#include "../MCAL/SPI/SPI_Init.h"
#include "../MCAL/ADC/ADC_priv.h"
#include "../MCAL/ADC/ADC_Init.h"
#include "../MCAL/External_Interrupt/EX_Intrrupt_priv.h"
#include "../MCAL/External_Interrupt/interrupt.h"
#include "../MCAL/External_Interrupt/EX_Interrupt_Interface.h"
#include "../HAL/LCD/LCD_Priv.h"
#include "../HAL/LCD/LCD_Config.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LM35/LM35_Priv.h"
#include "../HAL/LM35/LM35_Init.h"
#include "../HAL/DC_MOTOR/DC_Init.h"
#include "../HAL/LED/Led_priv.h"
#include "../HAL/LED/Led_interface.h"
#include "util/delay.h"
void AirCondition_Init()
{
	LCD_enInit();
	// init DC motor
	DC_Init(PORT_B,PIN3);
}

void Automatic_AirCondition()
{
	u16_t temp;
	Temp_enuInit(4);
	LCD_goto(1,1);
	LCD_enuDisplayString("Temperature: ");
	Temp_enuSychGetTemp_val(&temp);
		if(temp<=30)
		{
			//  stop
			DC_Speed(0,FPWM);
			LCD_goto(2,1);
			LCD_enDisplayNum((s32)temp);
			
		}
		else if(temp>30 && temp<=50)
		{
			//  speed 25%
			DC_Speed(0.25,FPWM);
			LCD_goto(2,1);
			LCD_enDisplayNum((s32)temp);
		}
		else if(temp>50 && temp<=70)
		{
			// speed 50%
			DC_Speed(0.5,FPWM);
			LCD_goto(2,1);
			LCD_enDisplayNum((s32)temp);
		}
		else if(temp>70 && temp<=90)
		{
			//  speed 75%
			DC_Speed(0.75,FPWM);
			LCD_goto(2,1);
			LCD_enDisplayNum((s32)temp);
		}
		else if(temp>90)
		{
			// fan speed 100%
			DC_Speed(1,FPWM);
			LCD_goto(2,1);
			LCD_enDisplayNum((s32)temp);
			
		}
}
ES_t Compare_enu(const char*data1 , const char*data2)
{
	
	uint8_t i =0;
	for(;data1[i]!='\0' && data2[i]!='\0';i++)
	{
		if(data1[i]!=data2[i])
		{
			break;
		}
	}
	if(data1[i]==0 && data2[i]==0)
	{
		return ES_OK;
	}
	else
	{
		return ES_NOK;
	}
}
ES_t Check_Connection()
{
	ES_t LocalErrorState = ES_NOK;
	uint8_t u8Recievedata;
	SPI_enuSlaveInit();
	SPI_enuSelectData_Order(MSB);
	SPI_enuSelectClock_Polarity(RISING);
	SPI_enuSelectClock_Phase(SAMPLE);
	DIO_SetPinValue(PORT_B,PIN7,LOW);
	SPI_enuReceiveChar(&u8Recievedata);
	if(u8Recievedata=='O')
	{
		LocalErrorState = ES_OK;
	}
	return LocalErrorState;
}

void Control_LightOfRoom()
{
	uint8_t u8Recievedata;
	SPI_enuReceiveChar(&u8Recievedata);
	if(u8Recievedata=='T') // turn on light of room1
	{
		led_on(PORT_A,PIN2,source);
	}
	else if(u8Recievedata=='F')  // turn off light of room1
	{
		led_of(PORT_A,PIN2,source);
	}
	else if(u8Recievedata=='t')  // turn on light of room2
	{
		led_on(PORT_A,PIN3,source);
	}
	else if(u8Recievedata=='f') // turn of light of room2
	{
		led_of(PORT_A,PIN3,source);
	}
}

void RecieveData_ToControl_OFLight()
{   
	DIO_SetPinValue(PORT_B,PIN7,LOW);
	SPI_enuEnableInterrupt();
	SPI_CallBack(&Control_LightOfRoom,NULLPTR);
	sei();
}
void Light_Init()
{
	led_init(PORT_D,PIN0);
	led_init(PORT_D,PIN1);
	led_init(PORT_D,PIN2);
	led_init(PORT_D,PIN7);
	led_init(PORT_A,PIN2);
	led_init(PORT_A,PIN3);
}
void Automatic_ControlLight()
{
	    u16_t val;
		LDR_enuInit(5);
		LDR_SychVoltageValue(&val);
		if(val>1000 && val<1024)
		{
			led_on(PORT_D,PIN0,source);
			led_on(PORT_D,PIN1,source);
			led_on(PORT_D,PIN2,source);
			led_on(PORT_D,PIN7,source);
		}
		else if(val>700 && val<1000)
		{
			led_of(PORT_D,PIN0,source);
			led_on(PORT_D,PIN1,source);
			led_on(PORT_D,PIN2,source);
			led_on(PORT_D,PIN7,source);
		}
		else if(val>600 && val<700)
		{
			led_of(PORT_D,PIN0,source);
			led_of(PORT_D,PIN1,source);
			led_on(PORT_D,PIN2,source);
			led_on(PORT_D,PIN7,source);
		}
		else if(val>=512 && val<=600)
		{
			led_of(PORT_D,PIN0,source);
			led_of(PORT_D,PIN1,source);
			led_of(PORT_D,PIN2,source);
			led_on(PORT_D,PIN7,source);
		}
		else if(val<500)
		{
			led_of(PORT_D,PIN0,source);
			led_of(PORT_D,PIN1,source);
			led_of(PORT_D,PIN2,source);
			led_of(PORT_D,PIN7,source);
		}
	
}

void OPEN_SmartHome()
{
	Light_Init();
	AirCondition_Init();
	ADC_euInit(AVCC,Left_Adjustment,Prescaler_8);
	RecieveData_ToControl_OFLight();
	while(1)
	{
		Automatic_AirCondition();
		Automatic_ControlLight();
	}
}