/*
 * EX_Interrupt_Interface.h
 *
 * Created: 27/02/2023 08:04:57 م
 *  Author: Menna Eid
 */ 


#ifndef EX_INTERRUPT_INTERFACE_H_
#define EX_INTERRUPT_INTERFACE_H_


void Enable_EXInterrupt(EX_TYPESOURCE EX_type);
void Disable_EXInterrupt(EX_TYPESOURCE EX_type);
void EXI_SetSenceMode(EX_TYPESOURCE EX_type,EX_SENCE_MODE Sence_type);

void EXI_SetCallBack(EX_TYPESOURCE EXI_type, void(*Lpcalptr)(void));



#endif /* EX_INTERRUPT_INTERFACE_H_ */