/*
 * Week4-B2.c
 *
 * Created: 20-Feb-19 11:08:03
 * Author : Daan
 */ 

#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRF = 0x00;				// set PORTF for input (ADC)
	DDRA = 0xFF;				// set PORTA for output
	DDRB = 0xFF;				// set PORTB for output
	adcInit();					// initialize ADC

	while (1)
	{
		ADCSRA |= 1 << 6;		// Turn on start bit
		PORTA = ADCH;
		wait(1000);				// every 100 ms (busy waiting)
	}
}

void adcInit()
{
	ADMUX  = 0b11100011;			// AREF=VCC, result left adjusted, channel3 at pin PF3
	ADCSRA = 0b11000110;		// ADC-enable, no interrupt, start, not free running, division by 64
}

void wait(int ms)
{
	for (int tms=0; tms<ms; tms++)
		_delay_ms( 1 );			// library function (max 30 ms at 8MHz)
}
