/*
 * interrupt.h
 *
 * Created: 01/03/2023 10:04:06 م
 *  Author: Pc
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define INT0_vect			__vector_1
#define INT1_vect			__vector_2
#define INT2_vect			__vector_3
#define VECT_TIMER2_CTC		__vector_4
#define VECT_ADC			__vector_16
#define VECT_TIMER0_OVF     __vector_11
#define VECT_TIMER0_CTC     __vector_10




# define sei()  __asm__ __volatile__ ("sei" ::)


#define ISR(vector,...)		void vector (void) __attribute__ ((signal))__VA_ARGS__;\
						    void vector(void)




#endif /* INTERRUPT_H_ */