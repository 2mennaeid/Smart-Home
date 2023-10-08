/*
 * LCD_Priv.h
 *
 * Created: 14/02/2023 08:45:16 ص
 *  Author: Menna Eid
 */ 


#ifndef LCD_PRIV_H_
#define LCD_PRIV_H_
#define 	FORCE_CURSOR_START_FIRST_LINE					0x80
#define 	FORCE_CURSOR_START_SECOND_LINE					0xC0
#define 	LCD_ONE			1
#define 	LCD_TWO			2
#define EIGHT  8
#define FOUR   4
static inline void LCD_invidSendCommend(uint8_t _command);
static void LCD_Latch(uint8_t _u8command);





#endif /* LCD_PRIV_H_ */