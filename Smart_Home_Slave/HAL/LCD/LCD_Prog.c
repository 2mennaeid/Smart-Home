/*
 * LCD_Prog.c
 *
 * Created: 14/02/2023 08:46:17 ص
 *  Author: Menna Eid
 */
#include "../../MCAL/DIO/StdTypes.h"
#include "../../MCAL/DIO/Registers1.h"
#include "../../MCAL/DIO/DIO_priv.h"
#include "../../MCAL/DIO/errorstate.h"
#include "../../MCAL/DIO/DI0_interface.h"
#include "LCD_Priv.h"
#include "LCD_Config.h"
//#include "LCD_Interface.h"
#define F_CPU  8000000UL

#include "util/delay.h"

ES_t LCD_enInit(void)
{
	ES_t LocalErrorstate = ES_OK;
	// set control pins
	DIO_SetPinDirection(RS_PORT,RS_PIN,OUT);
	DIO_SetPinDirection(RW_PORT,RW_PIN,OUT);
	DIO_SetPinDirection(EN_PORT,EN_PIN,OUT);
	// set data pins
	DIO_SetPinDirection(D7_PORT,D7_PIN,OUT);
	DIO_SetPinDirection(D6_PORT,D6_PIN,OUT);
	DIO_SetPinDirection(D5_PORT,D5_PIN,OUT);
	DIO_SetPinDirection(D4_PORT,D4_PIN,OUT);
	_delay_ms(35);
#if LCD_MODE==EIGHT
	DIO_SetPinDirection(D3_PORT,D3_PIN,OUT);
	DIO_SetPinDirection(D2_PORT,D2_PIN,OUT);
	DIO_SetPinDirection(D1_PORT,D1_PIN,OUT);
	DIO_SetPinDirection(D0_PORT,D0_PIN,OUT);
	// function set
	LCD_invidSendCommend(0x38);
#elif LCD_MODE == FOUR
	LCD_invidSendCommend(0x28);
#endif
	_delay_ms(1);
	// display on
	LCD_invidSendCommend(0x0c);
	_delay_ms(1);
	// clear lcd
	LCD_invidSendCommend(0x01);
	_delay_ms(2);
	// entry mode set (I/D)
	LCD_invidSendCommend(0x06);
	return LocalErrorstate;
	
}

ES_t LCD_enDisplayChar(uint8_t u8name)
{
	ES_t LocalErrorstate =ES_OK;
	// set rs as data
	DIO_SetPinValue(RS_PORT,RS_PIN,HIGH);
	LCD_Latch(u8name);
	return LocalErrorstate;
}
ES_t LCD_enuDisplayString(uint8_t*str)
{
	ES_t LocalErrorstate =ES_OK;
	 while(*str!='\0')
	 {
		 LCD_enDisplayChar(*str);
		 str++;
	 }
	return LocalErrorstate;
}
ES_t LCD_enDisplayNum(s32 s32num)
{
	ES_t LocalErrorstate= ES_OK;
	s32 LocalReverse=0;
	uint8_t Numdigit=0;
	uint8_t LocalRemiander=0;
	// reverse number
	while(s32num)
	{
		LocalRemiander = s32num % 10;
		LocalReverse = LocalReverse*10 + LocalRemiander;
		s32num /=10;
		Numdigit++;
	}
	// display num
	while(Numdigit)
	{
		LocalRemiander = LocalReverse%10;
		DIO_SetPinValue(RS_PORT,RS_PIN,HIGH);
		LCD_Latch(LocalRemiander + '0');
		LocalReverse /=10;
		Numdigit--;
	}
	
	
	return LocalErrorstate;
}

ES_t LCD_enSendCommand(uint8_t _u8command)
{
    ES_t LocalErrorstate= ES_OK;
	// set rs  as command
	DIO_SetPinValue(RS_PORT,RS_PIN,LOW);
	LCD_Latch(_u8command);
	
	return LocalErrorstate;
}

static void LCD_Latch(uint8_t _u8command)
{
	// set rw 0 as write
	DIO_SetPinValue(RW_PORT,RW_PIN,LOW);
	// EN is low
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	// set data pins
#if LCD_MODE == EIGHT
	DIO_SetPinValue(D7_PORT,D7_PIN, ((_u8command>>7)&1) );
	DIO_SetPinValue(D6_PORT,D6_PIN, ((_u8command>>6)&1) );
	DIO_SetPinValue(D5_PORT,D5_PIN, ((_u8command>>5)&1) );
	DIO_SetPinValue(D4_PORT,D4_PIN, ((_u8command>>4)&1) );
	DIO_SetPinValue(D3_PORT,D3_PIN, ((_u8command>>3)&1) );
	DIO_SetPinValue(D2_PORT,D2_PIN, ((_u8command>>2)&1) );
	DIO_SetPinValue(D1_PORT,D1_PIN, ((_u8command>>1)&1) );
	DIO_SetPinValue(D0_PORT,D0_PIN, ((_u8command>>0)&1) );
#elif LCD_MODE==FOUR
	DIO_SetPinValue(D7_PORT,D7_PIN, ((_u8command>>7)&1) );
	DIO_SetPinValue(D6_PORT,D6_PIN, ((_u8command>>6)&1) );
	DIO_SetPinValue(D5_PORT,D5_PIN, ((_u8command>>5)&1) );
	DIO_SetPinValue(D4_PORT,D4_PIN, ((_u8command>>4)&1) );
#endif
	// enable latch
	DIO_SetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(10);
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	_delay_ms(10);
	
	
}
static inline void LCD_invidSendCommend(uint8_t _u8command)
{
	// set rw 0 as write
	DIO_SetPinValue(RW_PORT,RW_PIN,LOW);
	// EN is low
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	// set data pins
	DIO_SetPinValue(D7_PORT,D7_PIN, ((_u8command>>7)&1) );
	DIO_SetPinValue(D6_PORT,D6_PIN, ((_u8command>>6)&1) );
	DIO_SetPinValue(D5_PORT,D5_PIN, ((_u8command>>5)&1) );
	DIO_SetPinValue(D4_PORT,D4_PIN, ((_u8command>>4)&1) );
	DIO_SetPinValue(D3_PORT,D3_PIN, ((_u8command>>3)&1) );
	DIO_SetPinValue(D2_PORT,D2_PIN, ((_u8command>>2)&1) );
	DIO_SetPinValue(D1_PORT,D1_PIN, ((_u8command>>1)&1) );
	DIO_SetPinValue(D0_PORT,D0_PIN, ((_u8command>>0)&1) );
	
	// enable latch
	DIO_SetPinValue(EN_PORT,EN_PIN,HIGH);
	_delay_ms(10);
	DIO_SetPinValue(EN_PORT,EN_PIN,LOW);
	_delay_ms(10);
}
ES_t LCD_goto(uint8_t x,uint8_t y)
{
	ES_t Local=ES_OK;
	uint8_t Local_u8RowLocation [] = {FORCE_CURSOR_START_FIRST_LINE , FORCE_CURSOR_START_SECOND_LINE};
	LCD_enSendCommand(Local_u8RowLocation [x-LCD_ONE]+(y-LCD_ONE));
	return Local;
}
