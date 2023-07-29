/*
 * LCD_Config.h
 *
 * Created: 14/02/2023 08:45:46 ص
 *  Author: Menna Eid
 */ 
				

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

// LCD Mode
#define LCD_MODE  EIGHT

// LCD Control PINS
#define RS_PORT PORT_A
#define RS_PIN  PIN0

#define RW_PORT PORT_D
#define RW_PIN  PIN2

#define EN_PORT PORT_D
#define EN_PIN  PIN3

// LCD DATA PINS
#define D7_PORT PORT_C
#define D7_PIN  PIN0

#define D6_PORT PORT_C
#define D6_PIN  PIN1

#define D5_PORT PORT_C
#define D5_PIN  PIN2

#define D4_PORT PORT_C
#define D4_PIN  PIN3

#define D3_PORT PORT_C
#define D3_PIN  PIN4

#define D2_PORT PORT_C
#define D2_PIN  PIN5

#define D1_PORT PORT_C
#define D1_PIN  PIN6

#define D0_PORT PORT_C
#define D0_PIN  PIN7






#endif /* LCD_CONFIG_H_ */