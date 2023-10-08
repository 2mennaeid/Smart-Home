/*
 * Master_Mode.c
 *
 * Created: 7/24/2023 3:37:46 AM
 *  Author: Menna Eid
 */
#include "../MCAL/DIO/errorstate.h"
#include "../MCAL/DIO/Registers1.h"
#include "../MCAL/DIO/StdTypes.h"
#include "../MCAL/DIO/DIO_priv.h"
#include "../MCAL/DIO/DIO_confg.h"
#include "../MCAL/DIO/DI0_interface.h" 
#include "../MCAL/USART/UART_Priv.h"
#include "../MCAL/USART/UART_Config.h"
#include "../MCAL/USART/UART_Init.h"
#include "../MCAL/EEPROM/EEPROM_Priv.h"
#include "../MCAL/EEPROM/EEPROM_Init.h"
#include "../MCAL/SPI/SPI_Priv.h"
#include "../MCAL/SPI/SPI_Config.h"
#include "../MCAL/SPI/SPI_Init.h"
#include "../MCAL/Timer1/Timer1_Priv.h"
#include "../MCAL/Timer1/Timer1_Init.h"
#include "../HAL/LCD/LCD_Priv.h"
#include "../HAL/LCD/LCD_Config.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LED/Led_priv.h"
#include "../HAL/LED/Led_interface.h"
#include "../HAL/Servo_Motor/Servo_Init.h"
<<<<<<< HEAD
#include "../HAL/BUZZER/BUZ_Init.h"
	
=======
#include "util/delay.h"
>>>>>>> 09ea2c79ec431e5ee3ad0486f4bee36ba8adc2a9
void Store_Information_InEEPROM()
{
	char name[20] = "Menna Eid";
	char pass[10] = "123456";
	EEPROM_WriteString(name,1);
	EEPROM_WriteString(pass,15);
}
// this function send data to slave to open smart home system to the user

void Open_System()
{
	PORTB =0x10;
	SPI_enuMasterInit();
	SPI_enuSelectData_Order(MSB);
	SPI_enuSelectClock_Polarity(RISING);
	SPI_enuSelectClock_Phase(SAMPLE);
	SPI_enuSelectClock_Rate(SCK_64);
	DIO_SetPinValue(PORT_B,PIN4,LOW);
	SPI_enuSendChar('O'); // to open smart home
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
// this function receive data from user through uart protocol to control of light of rooms

void SendData_ToControl_OFLight()
{
		uint8_t data[12];
		SPI_enuEnableInterrupt();
		while(1)
		{
			UART_enuReceiveString(data);
			UART_enuTransimtterString("\r\n");
			UART_enuTransimtterString(data);
			if(ES_OK==Compare_enu(data,"LedonRoom1"))
			{
				DIO_SetPinValue(PORT_B,PIN4,LOW);
				SPI_enuSendChar('T'); // mean turn on led on room
			}
			else if(ES_OK==Compare_enu(data,"LedofRoom1"))
			{
				DIO_SetPinValue(PORT_B,PIN4,LOW);
				SPI_enuSendChar('F'); // mean turn off led of room1
			}
			else if(ES_OK==Compare_enu(data,"LedonRoom2"))
			{
				DIO_SetPinValue(PORT_B,PIN4,LOW);
				SPI_enuSendChar('t'); //mean turn on led of room2
			}
			else if(ES_OK==Compare_enu(data,"LedofRoom2"))
			{
				DIO_SetPinValue(PORT_B,PIN4,LOW);
				SPI_enuSendChar('f'); //mean turn off led of room2
			}
			
		}
}
ES_t DoorLockSystem()
{
	  ES_t LocalError;
	  Store_Information_InEEPROM();
	  led_init(PORT_D,PIN6);
	  led_init(PORT_D,PIN7);
	  Servo_voidInit();
	  LCD_enInit();
	  char username[20];
	  char password[10];
	  char check1[20];
	  char check2[20];
	  UART_enuInit();
	  // ask user to enter username
	  LCD_enSendCommand(0x01);
	  LCD_goto(1,1);
	  LCD_enuDisplayString("Enter user name");
	  UART_enuReceiveString(username);
	  UART_enuTransimtterString(username);
	  UART_enuTransimtterString("\r\n");
	  // ask user to enter password 
	  LCD_enSendCommand(0x01);
	  LCD_enuDisplayString("Enter Password");
	  UART_enuReceiveString(password);
	  UART_enuTransimtterString(password);
	  UART_enuTransimtterString("\r\n");
	  EEPROM_ReadString(check1,1);
	  EEPROM_ReadString(check2,15);
	  // check pass and user from data that is stored in epprom
	  if(ES_OK==Compare_enu(username,check1) && ES_OK==Compare_enu(password,check2))
	  {
		  //yellow led will be turn on
		  led_of(PORT_D,PIN6,source);
		  led_on(PORT_D,PIN7,source);
		  // turn on servo motor 
		  Servo_voidSetAngle(180);
		  _delay_ms(3000);
		   Servo_voidSetAngle(0);
		  _delay_ms(2000);
		  LCD_enSendCommand(0x01); // clear lcd
		  LCD_goto(1,1);
		  LCD_enuDisplayString(" Smart Home ");
		  Open_System();
		  SendData_ToControl_OFLight();
		  LocalError = ES_OK;
	  }
	  else
	  {
		 LCD_enSendCommand(0x01); // clear lcd
		 LCD_goto(1,1);
		 LCD_enuDisplayString(" Wrong Password   ");
		 _delay_ms(200);
		 //red led will be turn on
		 led_of(PORT_D,PIN7,source);
		 led_on(PORT_D,PIN6,source);
		 LocalError = ES_NOK;
	  }
	return LocalError;
}

