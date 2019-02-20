/*
 * Week4-B3.c
 *
 * Created: 20-Feb-19 11:29:38
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
		//PORTB = ADCL;			// Show MSB/LSB (bit 10:0) of ADC
		PORTA = ADCH;
		wait(100);				// every 100 ms (busy waiting)
	}
}

void adcInit( void )
{
	ADMUX  = 0b01100011;			// AREF=VCC, result left adjusted, channel3 at pin PF3
	ADCSRA = 0b11000110;		// ADC-enable, no interrupt, start, not free running, division by 64
}

void wait( int ms )
{
	for (int tms=0; tms<ms; tms++)
		_delay_ms( 1 );			// library function (max 30 ms at 8MHz)
}
