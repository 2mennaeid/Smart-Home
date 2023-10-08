/*
 * LDR_Init.h
 *
 * Created: 7/23/2023 10:17:59 AM
 *  Author: Menna Eid
 */ 


#ifndef LDR_INIT_H_
#define LDR_INIT_H_

ES_t LDR_enuInit(ADC_enCHANNELS enChannelId);

void LDR_SychGetResistanceValue(u16_t*Copy_u16value);

void LDR_SychVoltageValue(u16_t*Copy_u16value);

#endif /* LDR_INIT_H_ */