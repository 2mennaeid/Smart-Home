/*
 * EEPROM_Prog.c
 *
 * Created: 7/18/2023 7:47:41 AM
 *  Author: Menna Eid
 */ 
#include "../DIO/Registers1.h"
#include "../DIO/StdTypes.h"
#include "EEPROM_Priv.h"
#include "EEPROM_Init.h"
void EEPROM_EnableInterrupt(void)
{
	EECR |= (1<<EERIE);
}

void EEPROM_WriteChar(uint8_t Copy_u8Data ,uint8_t Copy_u8Address)
{
	while(((EECR>>EEWE)&1)==1);
	EEARL = Copy_u8Address;
	EEDR = Copy_u8Data;
	EECR |= (1<<EEMWE);
	EECR |= (1<<EEWE);
}

void EEPROM_ReadChar(uint8_t *Copy_u8Data,uint8_t Copy_u8Address)
{
	while(((EECR>>EEWE)&1)==1);
	EEARL = Copy_u8Address;
	EECR |= (1<<EERE);
	*Copy_u8Data = EEDR;
}
void EEPROM_ReadString(uint8_t *Copy_u8Data,uint8_t Copy_u8Address)
{
   while(1)
   {
	    EEPROM_ReadChar(Copy_u8Data,Copy_u8Address);
	    if(*Copy_u8Data!='\0')
		{
			Copy_u8Data++;
			Copy_u8Address++;
		}
		else
		{
			break;
	
		}
	  
   }
   
}

void EEPROM_WriteString(uint8_t*Copy_u8Data ,uint8_t Copy_u8Address)
{
	while(*Copy_u8Data!='\0')
	{
		EEPROM_WriteChar(*Copy_u8Data,Copy_u8Address);
		Copy_u8Data++;
		Copy_u8Address++;
	}
	EEPROM_WriteChar('\0',Copy_u8Address);
}