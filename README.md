# Smart-Home
Smart Home System Based on AVR(ATMEGA32).
This Project consists of 2 Microcontroller (Master&Slave) are connected together with SPI Protocol.
Master connected to MObile Application using USART Protocol.
In Master Mode: ask user to enter user name and password through mobile application and check if the user name and password that are stored in EEPROM match the user name and password of the user to open the smart home system by sending message to Slave to open smart home by using SPI protocol.
In Slave Mode : Automatic control of light , Automatic open Aircondition based on Temperature and Turn on/of light of rooms using mobile application.
Software Architecture :
  •	APP Layer.
  •	HAL:
      o	LM35
      o	LDR
      o	LCD
      o	LED
      o	DC MOTOR
      o	SERVO MOTOR
  •	MCAL:
      o	DIO
      o	TIMER0
      o	TIMER1
      o	ADC
      o	External Interrupt
      o	USART 
      o	SPI

