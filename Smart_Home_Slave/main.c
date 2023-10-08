/*
 * Smart Home_Slave.c
 *
 * Created: 7/25/2023 2:49:36 PM
 * Author : Menna Eid
 */ 
#include "MCAL/DIO/errorstate.h"
#include "APP/Slave_Mode.h"

int main(void)
{

		 if(ES_OK==Check_Connection())
		 {
			OPEN_SmartHome();
		 }
     
			
		 
		
}

