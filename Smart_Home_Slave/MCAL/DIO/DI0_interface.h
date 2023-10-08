/*
 * DI0_interface.h
 *
 * Created: 30/01/2023 12:15:19 ص
 *  Author: Menna eid
 * API for user
 */ 


#ifndef DI0_INTERFACE_H_
#define DI0_INTERFACE_H_
ES_t DIO_enInt(void);
ES_t DIO_enSetPortDirection(uint8_t portnumber,uint8_t value);
ES_t DIO_enSetPortValue(uint8_t portnumber,uint8_t value);
ES_t DIO_enGetPortValue(uint8_t portnumber,uint8_t *value);
ES_t DIO_enTogglePort(uint8_t portnumber);
ES_t DIO_SetPinDirection(uint8_t portnumber,uint8_t pinnumber,uint8_t direction);
ES_t DIO_SetPinValue(uint8_t portnumber,uint8_t pinnumber,uint8_t value);
ES_t DIO_togglepin(uint8_t portnumber,uint8_t pinnumber);
ES_t DIO_readpinvalue(uint8_t portnumber,uint8_t pinnumber,uint8_t *value);



#endif /* DI0_INTERFACE_H_ */