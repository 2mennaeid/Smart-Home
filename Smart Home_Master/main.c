/*
 * Smart Home.c
 *
 * Created: 7/24/2023 3:02:32 AM
 * Author : Menna Eid
 */ 


#include "APP/Master_Mode.h"
#include "MCAL/DIO/errorstate.h"
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

