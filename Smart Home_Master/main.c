/*
 * Smart Home.c
 *
 * Created: 7/24/2023 3:02:32 AM
 * Author : Menna Eid
 */ 


//#include "APP/Master_Mode.h"
#include "MCAL/DIO/errorstate.h"
#include "MCAL/DIO/Registers1.h"
#include "MCAL/DIO/StdTypes.h"
#include "MCAL/DIO/DIO_priv.h"
#include "MCAL/DIO/DIO_confg.h"
#include "MCAL/DIO/DI0_interface.h"
#include "MCAL/Timer1/Timer1_Priv.h"
#include "MCAL/Timer1/Timer1_Init.h"
#include "HAL/Servo_Motor/Servo_Init.h"
int main(void)
{
  
   int i =3;
   while(i>0)
   {
	   if(ES_OK==DoorLockSystem())
	   {
			break;	   
	   }
	   else
	   {
			i--;
	   }
   }
 
}

