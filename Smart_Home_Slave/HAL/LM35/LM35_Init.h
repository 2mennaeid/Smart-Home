/*
 * LM35_Init.h
 *
 * Created: 7/7/2023 2:54:22 PM
 *  Author: Menna Eid
 */ 


#ifndef LM35_INIT_H_
#define LM35_INIT_H_
uint8_t flag;
ES_t Temp_enuInit(uint8_t Th_num);
void Temp_enuASychGetTemp_val(u16_t*Tem_value);
void Temp_enuSychGetTemp_val(u16_t*Tem_value);




#endif /* LM35_INIT_H_ */