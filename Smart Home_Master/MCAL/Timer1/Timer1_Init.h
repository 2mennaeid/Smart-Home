/*
 * Timer1_Init.h
 *
 * Created: 7/27/2023 3:49:17 PM
 *  Author: Menna Eid
 */ 


#ifndef TIMER1_INIT_H_
#define TIMER1_INIT_H_



void Timer1_Fast_PWM(f32 f32duty_Value);

void Timer1_FrequancyValue(uint8_t u8Frequancy_value);

void Timer1_FastPWM_CalC_OCRX(f32 f32duty_Value);

void Timer1_SelectPrescaler(TIMER1_PRESCALER enupres_val);

void Timer1_SelectMode(TIMER1_SELECTMODE enuMode);

void Timer1FastPWM_SelectOutPutCompareMatch(Timer1_CompareOutMode enu_outputcompare);
#endif /* TIMER1_INIT_H_ */