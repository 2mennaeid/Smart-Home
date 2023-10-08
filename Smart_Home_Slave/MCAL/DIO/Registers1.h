/*
 * Registers1.h
 *
 * Created: 30/09/2022 08:30:42 م
 *  Author: Menna eid
 */ 

/*---------------------------
DIO register
-----------------------------*/
#ifndef REGISTERS1_H_
#define REGISTERS1_H_
#include "StdTypes.h"
// PORTA
#define PORTA *((volatile uint8_t*)0x3B) // 8-bit 
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)
// PORT B
#define PORTB *((volatile uint8_t*)0x38) // 8-bit
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)
// PORT C 
#define PORTC *((volatile uint8_t*)0x35) // 8-bit
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)
// PORT D
#define PORTD *((volatile uint8_t*)0x32) // 8-bit
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)

// Timer0 Register
#define TCCR0 *((volatile uint8_t*)0x53) // 8-bit
#define TCNT0 *((volatile uint8_t*)0x52)
#define TIFR  *((volatile uint8_t*)0x58)
#define TIMSK *((volatile uint8_t*)0x59)
#define OCR0  *((volatile uint8_t*)0x5C)
#define TCCR1A *((volatile uint8_t*)0x4F)
#define TCCR1B *((volatile uint8_t*)0x4E)
#define TCNT1H *((volatile uint8_t*)0x4D)
#define TCNT1L *((volatile uint8_t*)0x4C)
#define OCR1AH *((volatile uint8_t*)0x4B)
#define OCR1AL *((volatile uint8_t*)0x4A)
#define OCR1BH *((volatile uint8_t*)0x49)
#define OCR1BL *((volatile uint8_t*)0x48)
// Interrupt Register
#define MCUCR  *((volatile uint8_t*)0x55)
#define MCUCSR *((volatile uint8_t*)0x54)
#define GICR   *((volatile uint8_t*)0x5B)
#define GIFR    *((volatile uint8_t*)0x5A)
#define SREG 	*((volatile uint8_t*)0x5F)

// ADC Registers
#define ADCL    *((volatile uint8_t*)0x24)
#define ADCH    *((volatile uint8_t*)0x25)
#define ADMUX  *((volatile uint8_t*)0x27) // 
#define ADCSRA *((volatile uint8_t*)0x26)
#define SFIOR	*((volatile uint8_t*)0x50)

// UART Register
#define UDR    *((volatile uint8_t*)0x2C)
#define UCSRA  *((volatile uint8_t*)0x2B)
#define UCSRB  *((volatile uint8_t*)0x2A)
#define UBRRL  *((volatile uint8_t*)0x29)
#define UBRRH  *((volatile uint8_t*)0x40)
#define UCSRC  *((volatile uint8_t*)0x40)

// SPI Registers

#define  SPDR  *((volatile uint8_t*)0x2F)
#define  SPSR  *((volatile uint8_t*)0x2E)
#define  SPCR  *((volatile uint8_t*)0x2D)

// EEPROM Register
#define EEARH  *((volatile uint8_t*)0x3F)
#define EEARL  *((volatile uint8_t*)0x3E)
#define EEDR   *((volatile uint8_t*)0x3D)
#define EECR   *((volatile uint8_t*)0x3C)
#endif /* REGISTERS1_H_ */