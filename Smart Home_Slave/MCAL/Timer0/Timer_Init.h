/*
 * Timer_Init.h
 *
 * Created: 6/22/2023 6:20:42 AM
 *  Author: Menna Eid
 */ 


#ifndef TIMER_INIT_H_
#define TIMER_INIT_H_

f32 Timer_enCalC_OVF(f32 f32delay);

ES_t TimerOVF_enSeDelay(f32 f32delay);

ES_t TimerOVF_enASeDelay(f32 f32delay,void (*Localtptrfunc)(void*),void *parameter);

ES_t TimerCTC_enuASyDelay(f32 f32delay,void (*Localtptrfunc)(void*),void *parameter);

ES_t TimerCTC_enuSelectCompare_Output_Mode(Timer_CompareOutMode ctc_value);

ES_t TimerFPWM_enuSelectCompare_Output_Mode(Timer_CompareOutMode fpwm_value);

ES_t TimerPhaseCorrect_enuSelectCompare_Output_Mode(Timer_CompareOutMode phase_value);

ES_t TimerFPWM_enuCalc_OCR(f32 f32duty,Timer_DutyType value);

ES_t TimerPhaseCorrect_enuCalc_OCR(uint8_t u8duty,Timer_DutyType value);

ES_t Timer_enSelectmode(TIMER_MODE IdMode);

ES_t Timer_enSelectPrescaler(TIMER_PRESCALER pres_val);

ES_t TimerOVF_enEnableInterrupt();

ES_t TimerCTC_enEnableInterrupt();

ES_t TimerOVF_enDisableInterrupt();






#endif /* TIMER_INIT_H_ */