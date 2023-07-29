/*
 * SPI_Prog.c
 *
 * Created: 7/10/2023 6:06:30 AM
 *  Author: Menna Eid
 */ 
#include "../DIO/StdTypes.h"
#include "../DIO/Registers1.h"
#include "../DIO/errorstate.h"
#include "../DIO/DIO_priv.h"
#include "../DIO/DIO_confg.h"
#include "../DIO/DI0_interface.h"
#include "SPI_Priv.h"
#include "SPI_Config.h"
#include "SPI_Init.h"

void SPI_enuMasterInit()
{
	DDRB = 0xB0;
	// enable SPI
	SPCR |= (1<<SPE);
	SPCR |= (1<<MSTR);
}
void SPI_enuSlaveInit()
{
	DDRB = 0x40;
	// enable SPI
	SPCR |= (1<<SPE);
	SPCR &= ~(1<<MSTR);
	SPCR &= ~(1<<SPR0);
	SPCR &= ~(1<<SPR1);
	SPSR &= ~(1<<SPI2X);
	
}
void SPI_enuSelectClock_Polarity(Clock_Polarity enu_CPOL)
{
	switch(enu_CPOL)
	{
		case RISING:
			//DIO_SetPinDirection(PORT_B,PIN7,LOW);
			SPCR &= ~(1<<CPOL);
			break;
		case FALLING:
			//DIO_SetPinDirection(PORT_B,PIN7,HIGH);
			SPCR |= (1<<CPOL);
			break;
	}
}
void SPI_enuSelectClock_Phase(Clock_Phase enu_CPH)
{
	switch(enu_CPH)
	{
		 case SAMPLE:
			SPCR &= ~(1<<CPHA);
		    break;
		 case SETUP:
			 SPCR |= (1<<CPHA);
			 break;
	}
}
void SPI_enuSelectClock_Rate(Clock_Rate_Select enu_SCK)
{
	switch(enu_SCK)
	{
		case SCK_4:
			SPCR &= ~(1<<SPR0);
			SPCR &= ~(1<<SPR1);
			break;
		case SCK_16:
			SPCR |= (1<<SPR0);
			SPCR &= ~(1<<SPR1);
			break;
		case SCK_64:
			SPCR &= ~(1<<SPR0);
			SPCR |= (1<<SPR1);
			break;
		case SCK_128:
			SPCR |= (1<<SPR0);
			SPCR |= (1<<SPR1);
			break;
	}
	SPSR &= ~(1<<SPI2X); // disable double speed
}
void SPI_enuSelectData_Order(Data_Order type)
{
	if(type==LSB)
	{
		SPCR |= (1<<DORD);
	}
	else if(type==MSB)
	{
		SPCR &= ~(1<<DORD);
	}
}
void SPI_enuSendChar(uint8_t u8Copydata)
{
	SPDR = u8Copydata;
	while(!((SPSR>>SPIF)&1));
}
void SPI_enuReceiveChar(uint8_t*u8ptrdata)
{
	while(!((SPSR>>SPIF)&1));
	*u8ptrdata = SPDR;
}
void SPI_enuEnableInterrupt()
{
	SPCR |= (1<<SPIE);
}
void SPI_enuSendString(uint8_t*u8Copydata)
{
	while(*u8Copydata!='\0')
	{
		SPDR = *u8Copydata;
		while(!((SPSR>>SPIF)&1));
		u8Copydata++;
	}
	SPDR = '\0';
}
void SPI_enuReceiveString(uint8_t*u8ptrdata)
{
	while(1)
	{
		while(!((SPSR>>SPIF)&1));
		*u8ptrdata = SPDR;
		if(*u8ptrdata!='\0')
		{
			u8ptrdata++;
		}
		else
		{
			break;
		}
	}
}
void SPI_enuDisableInterrupt()
{
	SPCR &= ~(1<<SPIE);
}
