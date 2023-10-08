/*
 * Led_interface.h
 *
 * Created: 30/01/2023 03:14:37 م
 *  Author: Menna Eid
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
ES_t led_init(uint8_t ledport,uint8_t ledpin);
ES_t led_on(uint8_t ledport,uint8_t ledpin,uint8_t type_connection);
ES_t led_of(uint8_t ledport,uint8_t ledpin,uint8_t type_connection);




#endif /* LED_INTERFACE_H_ */