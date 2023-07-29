/*
 * EEPROM_Init.h
 *
 * Created: 7/18/2023 7:46:52 AM
 *  Author: Menna Eid
 */ 


#ifndef EEPROM_INIT_H_
#define EEPROM_INIT_H_

void EEPROM_EnableInterrupt(void);

void EEPROM_WriteChar(uint8_t Copy_u8Data ,uint8_t Copy_u8Address);

void EEPROM_WriteString(uint8_t*Copy_u8Data ,uint8_t Copy_u8Address);

void EEPROM_ReadChar(uint8_t *Copy_u8Data,uint8_t Copy_u8Address);

void EEPROM_ReadString(uint8_t *Copy_u8Data,uint8_t Copy_u8Address);


#endif /* EEPROM_INIT_H_ */