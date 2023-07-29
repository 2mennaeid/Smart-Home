/*
 * DC_Init.h
 *
 * Created: 7/13/2023 6:13:54 AM
 *  Author: Menna Eid
 */ 


#ifndef DC_INIT_H_
#define DC_INIT_H_

void DC_Init(uint8_t u8portId ,uint8_t u8pinnumber);
void DC_Speed(f32 u8duty,TIMER_MODE enumode);

#endif /* DC_INIT_H_ */