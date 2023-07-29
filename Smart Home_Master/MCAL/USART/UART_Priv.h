/*
 * UART_Priv.h
 *
 * Created: 7/5/2023 12:08:37 AM
 *  Author: Menna Eid
 */ 


#ifndef UART_PRIV_H_
#define UART_PRIV_H_
#define FF        8000000UL


#define UART_ASYCH   8
#define UART_SYCH    9

#define UART_PARITY_ODD  2
#define UART_PARITY_EVEN 3
#define UART_PARITY_DISABLE 1

#define UART_ONESTOP_BIT   6
#define UART_TWOSTOP_BIT   7

#define TRANSIMTTER  7
#define RECIEVER     3
#define TRANSCIVER   2

#define NORMAL       2
#define DOUBLE       1
// define bits in  UCSRC 
#define URSEL  7
#define UMSEL  6
#define UPM1   5
#define UPM0   4
#define USBS   3
#define UCSZ1  2
#define UCSZ0  1
#define UCPOL  0

// define bits in  UCSRB
#define UCSZ2  2
#define RXEN   4
#define TXEN   3
#define RXB8   1
#define TXB8   0
#define RXCIE  7
#define TXCIE  6
#define UDRIE  5

// define bits in  UCSRA
#define UDRE  5
#define RXC   7
#define TXC   6
#define FE    4
#define DOR   3
#define PE    2
#define U2X   1
#define MPCM  0
#endif /* UART_PRIV_H_ */