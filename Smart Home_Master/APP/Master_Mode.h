/*
 * Master_Mode.h
 *
 * Created: 7/24/2023 3:38:08 AM
 *  Author: Menna Eid
 */ 


#ifndef MASTER_MODE_H_
#define MASTER_MODE_H_

void Store_Information_InEEPROM();

void Open_System();

ES_t DoorLockSystem();

void TurnON_LightofRoom();

void TurnOFF_LightofRoom();

void SendData_ToControl_OFLight();

#endif /* MASTER_MODE_H_ */