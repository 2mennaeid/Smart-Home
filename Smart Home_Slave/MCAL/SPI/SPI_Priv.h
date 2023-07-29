/*
 * SPI_Priv.h
 *
 * Created: 7/10/2023 6:06:07 AM
 *  Author: Menna Eid
 */ 


#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define MASTER  1
#define SLAVE   0
typedef enum
{
	RISING=0,
	FALLING
	}Clock_Polarity;
typedef enum
{
	SAMPLE,
	SETUP
	}Clock_Phase;
typedef enum
{
	SCK_4,
	SCK_16,
	SCK_64,
	SCK_128
	
	}Clock_Rate_Select;

typedef enum
{
	LSB,
	MSB
	}Data_Order;

// define bits in SPCR
#define SPIE 7
#define SPE  6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0
//  SPSR
#define SPIF  7
#define SPI2X 0
#define WCOL  6
#endif /* SPI_PRIV_H_ */