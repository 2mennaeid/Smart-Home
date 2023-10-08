/*
 * Slave_Mode.h
 *
 * Created: 7/25/2023 3:51:47 PM
 *  Author: Menna Eid
 */ 


#ifndef SLAVE_MODE_H_
#define SLAVE_MODE_H_

ES_t Check_Connection();

void Automatic_ControlLight();

void Light_Init();

void OPEN_SmartHome();

void AirCondition_Init();

void Automatic_AirCondition();

void Control_LightOfRoom();

void RecieveData_ToControl_OFLight();


#endif /* SLAVE_MODE_H_ */