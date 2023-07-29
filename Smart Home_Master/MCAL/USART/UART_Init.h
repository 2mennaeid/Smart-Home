/*
 * UART_Init.h
 *
 * Created: 7/5/2023 12:09:14 AM
 *  Author: Menna Eid
 */ 


#ifndef UART_INIT_H_
#define UART_INIT_H_
ES_t UART_enuInit();
ES_t UART_enuTransimtterchar(uint8_t data);
ES_t UART_enuReceivechar(uint8_t *data);
ES_t UART_enuTransimtterString(char*data);
ES_t UART_enuReceiveString(char*data);





#endif /* UART_INIT_H_ */