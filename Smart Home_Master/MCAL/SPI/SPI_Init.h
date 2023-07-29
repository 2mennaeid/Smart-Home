/*
 * SPI_Init.h
 *
 * Created: 7/10/2023 6:05:23 AM
 *  Author: Menna Eid
 */ 


#ifndef SPI_INIT_H_
#define SPI_INIT_H_
void SPI_enuMasterInit();

void SPI_enuSlaveInit();

void SPI_enuSelectClock_Polarity(Clock_Polarity enu_CPOL);

void SPI_enuSelectClock_Phase(Clock_Phase enu_CPH);

void SPI_enuSelectClock_Rate(Clock_Rate_Select enu_SCK);

void SPI_enuSelectData_Order(Data_Order type);

void SPI_enuSendChar(uint8_t u8Copydata);

void SPI_enuReceiveChar(uint8_t*u8ptrdata);

void SPI_enuSendString(uint8_t*u8Copydata);

void SPI_enuReceiveString(uint8_t*u8ptrdata);

void SPI_enuEnableInterrupt();

void SPI_enuDisableInterrupt();



#endif /* SPI_INIT_H_ */