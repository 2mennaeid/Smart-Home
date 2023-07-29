/*
 * dio.c
 *
 * Created: 30/09/2022 09:19:10 م
 *  Author: Menna Eid
 */ 
#include "StdTypes.h"
#include "Registers1.h"
#include "DIO_priv.h"
#include "errorstate.h"
//#include "DI0_interface.h"
ES_t DIO_enSetPortDirection(uint8_t portnumber,uint8_t value)
{
	ES_t Local_enErrorstate;
	if(portnumber>='A' && portnumber<='D')
	{
		switch(portnumber)
		{
			case PORT_A:
			   DDRA = value;
			   break;
			case PORT_B:
			    DDRB=value;
				break;
			case PORT_C:
			     DDRC=value;
			     break;
		    case PORT_D:
			     DDRD=value;
				 break;
		}
		Local_enErrorstate = ES_OK;
	}
	else
	{
		Local_enErrorstate=ES_NOK;
	}
	return Local_enErrorstate;
}
ES_t DIO_enSetPortValue(uint8_t portnumber,uint8_t value)
{
	
	ES_t Local_enErrorstate;
	if(portnumber>='A' && portnumber<='D')
	{
		switch(portnumber)
		{
			case PORT_A:
			     PORTA = value;
			break;
			case PORT_B:
			    PORTB=value;
			break;
			case PORT_C:
			    PORTC=value;
			break;
			case PORT_D:
			    PORTD=value;
			break;
		}
		Local_enErrorstate = ES_OK;
	}
	else
	{
		Local_enErrorstate=ES_NOK;
	}
	return Local_enErrorstate;
}
ES_t DIO_enGetPortValue(uint8_t portnumber,uint8_t *value)
{
	ES_t Local_Errorstate;
	if(portnumber>='A' && portnumber<='D')
	{
		switch(portnumber)
		{
			case PORT_A:
			     *value= PINA;
		    break;
			case PORT_B:
				*value=PINB;
			break;
			case PORT_C:
				*value=PINC;
			break;
			case PORT_D:
				*value=PIND;
			break;
		}
		Local_Errorstate=ES_OK;
	}
	else {
		Local_Errorstate = ES_NOK;
	}
  return Local_Errorstate;
}
ES_t DIO_enTogglePort(uint8_t portnumber)
{
	ES_t Local_enErrorstate;
	if(portnumber>='A' && portnumber<='D')
	{
		switch(portnumber)
		{
			case PORT_A:
				PORTA = ~PORTA;
			break;
			case PORT_B:
				PORTB=~PORTB;
			break;
			case PORT_C:
				PORTC=~PORTC;
			break;
			case PORT_D:
				PORTD=~PORTD;
			break;
		}
		Local_enErrorstate = ES_OK;
	}
	else
	{
		Local_enErrorstate=ES_NOK;
	}
	return Local_enErrorstate;
}
ES_t DIO_SetPinDirection(uint8_t portnumber,uint8_t pinnumber,uint8_t direction)
{
	ES_t Local_Errorstate;
	if(portnumber>='A' && portnumber<='D' && direction<=OUT)
	{
	 switch(portnumber)
	 {
		case PORT_A:
		    if(direction==IN)
			{
				DDRA &= ~(1<<pinnumber);
			}
			else if(direction==OUT)
			{
				DDRA |=(1<<pinnumber);
			}
		break;
		case PORT_B:
		    if(direction==IN)
		    {
			    DDRB &= ~(1<<pinnumber);
		    }
		    else if(direction==OUT)
		    {
			    DDRB |=(1<<pinnumber);
		    }
		break;
		case PORT_C:
		    if(direction==IN)
		    {
			    DDRC &= ~(1<<pinnumber);
		    }
		    else if(direction==OUT)
		    {
			    DDRC |=(1<<pinnumber);
		    }
		break;
		case PORT_D:
		    if(direction==IN)
		    {
			    DDRD &= ~(1<<pinnumber);
		    }
		    else if(direction==OUT)
		    {
			    DDRD |=(1<<pinnumber);
		    }
		break; 
	}
	Local_Errorstate =ES_OK;
  }
  else
  {
	  Local_Errorstate = ES_NOK;
  }
  return Local_Errorstate;
}
ES_t DIO_SetPinValue(uint8_t portnumber,uint8_t pinnumber,uint8_t value)
{
	ES_t Local_Errorstate;
    if(portnumber>='A' && portnumber<='D' && value<=OUT)
    {
		switch(portnumber)
		{
			case PORT_A:
				PORTA &=~(1<<pinnumber);//Mask
				PORTA |=(value<<pinnumber);	
			    break;
			case PORT_B:
				PORTB &=~(1<<pinnumber);//Mask
				PORTB |=(value<<pinnumber);
				break;
			case PORT_C:
				PORTC &=~(1<<pinnumber);//Mask
				PORTC |=(value<<pinnumber);
				break;
			case PORT_D:
				PORTD &=~(1<<pinnumber);//Mask
				PORTD |=(value<<pinnumber);
				break;
			
		}
		Local_Errorstate =ES_OK;
	}
   else
   {
	 Local_Errorstate= ES_NOK;
   }
  return Local_Errorstate;
}

ES_t DIO_readpinvalue(uint8_t portnumber,uint8_t pinnumber,uint8_t *value)
{
	ES_t LocalErrorstate;
	if(portnumber>='A' && portnumber<='D')
	{
		
	 switch(portnumber)
	 {
		case PORT_A:
		    *value= ((PINA>>pinnumber)&1);
		break;
		case PORT_B:
		    *value= ((PINB>>pinnumber)&1);
		break;
		case PORT_C:
		   *value= ((PINC>>pinnumber)&1);
		break;
		case PORT_D:
		  *value= ((PIND>>pinnumber)&1);
		break;
	}
	LocalErrorstate =ES_OK;
  }
  else
  {
     LocalErrorstate=ES_NOK;
  }
	
  return LocalErrorstate;
}
ES_t DIO_togglepin(uint8_t portnumber,uint8_t pinnumber)
{
	ES_t LocalErrorstate;
	if(portnumber>='A' && portnumber<='D')
	{
		
	 switch(portnumber)
	 {
	   case PORT_A:
	      PORTA ^= (1<<pinnumber);
	   break;
	   case PORT_C:
	      PORTC ^= (1<<pinnumber);
	   break;
	   case PORT_B:
	      PORTB ^= (1<<pinnumber);
	   break;
	   case PORT_D:
	      PORTD ^= (1<<pinnumber);
	   break;
	}
	LocalErrorstate=ES_OK;
  }
  else
  {
	  LocalErrorstate=ES_NOK;
  }
  return LocalErrorstate;
}