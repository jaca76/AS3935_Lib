/*
 * Interrupt_Lib.c
 *
 *  Created on: 15 sie 2016
 *      Author: Jacek
 */
	#include <avr/io.h>
	#include <avr/interrupt.h>
	#include <util/atomic.h>

volatile  uint32_t ms_count=0;

	void Timer0_init(void)
	{
		TCCR0A |= (1<<WGM01); //CTC
		TCCR0B |= (1<<CS02); //256
		OCR0A = 71;
		TIMSK0 |= (1<<OCIE0A);
	}


	void Int2_init(void)
	{
		EICRA|= (1<<ISC21);
		EIMSK|= (1<<INT2);
		DDRB &= ~(1<<PB2);

	}

	uint32_t millis(void){
		ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
		return ms_count;
		}
	}


	ISR(TIMER0_COMPA_vect)
	{
	ms_count++;
	}


