/*
 * dio.h
 *
 * Created: 30/09/2022 09:19:35 م
 *  Author: Menna Eid
 */ 


#ifndef DIO_H_
#define DIO_H_
// define type of port
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'
// define state of devices (input or output) 
#define IN 0
#define OUT 1
// define Writing on pins
#define LOW 0
#define HIGH 1
#define PULL_UP 1
#define FLOAT 0
// define pin
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
//////////////////////
#define ConC_help(b7,b6,b5,b4,b3,b2,b1,b0)    0b##b7##b6##b5##b4##b3##b2##b1##b0
#define ConC(b7,b6,b5,b4,b3,b2,b1,b0)         ConC_help(b7,b6,b5,b4,b3,b2,b1,b0) 


#endif /* DIO_H_ */