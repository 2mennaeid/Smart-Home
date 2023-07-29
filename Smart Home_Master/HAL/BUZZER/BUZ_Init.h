/*
 * BUZ_Init.h
 *
 * Created: 7/28/2023 10:04:19 PM
 *  Author: Menna Eid
 */ 


#ifndef BUZ_INIT_H_
#define BUZ_INIT_H_

void BUZZER_Init(uint8_t buzport,uint8_t buzpin);

void BUZZER_ON(uint8_t buzport,uint8_t buzpin);

void BUZZER_OF(uint8_t buzport,uint8_t buzpin);


#endif /* BUZ_INIT_H_ */