/*
 * UART_Prog.c
 *
 * Created: 7/5/2023 12:08:11 AM
 *  Author: Menna Eid
 */ 
#include "../DIO/StdTypes.h"
#include "../DIO/Registers1.h"
#include "../DIO/errorstate.h"
#include "../External_Interrupt/interrupt.h"
#include "UART_Priv.h"
#include "UART_Config.h"
#include "UART_Init.h"

ES_t UART_enuInit()
{
	uint8_t ucsrc= 0;
	ucsrc |= (1<<URSEL); // select UCSRC
	ES_t LocalErrorstate = ES_OK;
	// define clock mode 
#if CLOCK_MODE == UART_ASYCH
	ucsrc &= ~(1<<UMSEL);
	ucsrc &= ~(1<<UCPOL);
#elif CLOCK_MODE == UART_SYCH
	ucsrc |= (1<<UMSEL);
	ucsrc |= (1<< UCPOL);
#endif
      // define  : Parity Mode
#if UART_PARITY_TYPE == UART_PARITY_EVEN
	ucsrc &= ~(1<<UPM0);
	ucsrc |= (1<<UPM1);
#elif UART_PARITY_TYPE == UART_PARITY_ODD
	ucsrc |= (1<<UPM0);
	ucsrc |= (1<<UPM1);
#elif UART_PARITY_TYPE == UART_PARITY_DISABLE
	 ucsrc &= ~(1<<UPM0);
	 ucsrc &= ~(1<<UPM1);
#endif
  // define Stop Bit Select
#if UART_SELECT_STOPBIT == UART_ONESTOP_BIT
	ucsrc &= ~(1<<USBS);
#elif UART_SELECT_STOPBIT == UART_TWOSTOP_BIT
	ucsrc |= (1<<USBS);
#endif
    // define data size
#if UART_DATASIZE == 5
	UCSRB &= ~(1<<UCSZ2);
	ucsrc &= ~(1<<UCSZ0);
	ucsrc &= ~(1<<UCSZ1);
#elif UART_DATASIZE == 8
	  UCSRB &= ~(1<<UCSZ2);
	  ucsrc |= (1<<UCSZ0);
	  ucsrc |= (1<<UCSZ1);
#endif
#if UART_MODE == TRANSIMTTER
	UCSRB |=(1<<TXEN);
#elif UART_MODE == RECIEVER
	  UCSRB |=(1<<RXEN); 
#elif UART_MODE == TRANSCIVER
	  UCSRB |=(1<<TXEN);
	  UCSRB |=(1<<RXEN);
#endif
#if SPEED_MODE == NORMAL
	UCSRA &=~(1<<U2X);
#elif SPEED_MODE == DOUBLE
	  UCSRA |= (1<<U2X);
#endif
  UCSRC = ucsrc;
  u16_t localubrr =0;
  localubrr &= ~(1<<15);
  localubrr = ((FF/(SPEED_MODE*8*BAUDRATE))-1);
 
 UBRRL = (uint8_t)localubrr;
 UBRRH = (localubrr>>8);
 
	return LocalErrorstate;	
}
ES_t UART_enuTransimtterchar(uint8_t data)
{
	ES_t LocalErrorstate = ES_OK;
		
		while (! (UCSRA & (1<<UDRE))); 
		UDR = data; 
		return LocalErrorstate;
	
}
ES_t UART_enuReceivechar(uint8_t *data)
{
	ES_t LocalErrorstate = ES_OK;
	while ((UCSRA & (1 << RXC)) == 0);
	*data = UDR;
	return LocalErrorstate;
}

ES_t UART_enuTransimtterString(char*data)
{
	ES_t LocalErrorstate = ES_OK;
	while(*data!= '\0')
	{
		while (! (UCSRA & (1<<UDRE))); 
		UDR = *data;
		data++;
	}
	
	return LocalErrorstate;
}
ES_t UART_enuReceiveString(char*data)
{
	ES_t LocalErrorstate = ES_OK;
	uint8_t index = 0;
	uint8_t localdata = 0;
	uint8_t temdata=0;
	while ((UCSRA & (1 << RXC)) == 0);
	temdata= UDR;
	while(1)
	{
		while ((UCSRA & (1 << RXC)) == 0);
		localdata = UDR;
		if(localdata == temdata)
		{
			data[index] = '\0';
			break;
		}
		data[index]= localdata;
		index++;
	}
	
	return LocalErrorstate;
}