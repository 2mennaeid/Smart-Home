/*
 * Servo_Init.h
 *
 * Created: 7/25/2023 11:24:55 AM
 *  Author: Menna Eid
 */ 


#ifndef SERVO_INIT_H_
#define SERVO_INIT_H_
void Servo_Init(TIMER1_PRESCALER enupres_val,TIMER1_SELECTMODE enuMode,Timer1_CompareOutMode enu_outputcompare);

void Servo_Speed(f32 f32duty);



#endif /* SERVO_INIT_H_ */