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

#include "lcd.h"

int main(void)
{
	DDRF = 0x00;				// set PORTF for input (ADC)
	DDRA = 0xFF;				// set PORTA for output
	DDRB = 0xFF;				// set PORTB for output
	adcInit();					// initialize ADC
	lcd_init();

	while (1)
	{
	    PORTA = ADCH;
	    char snum[3];
		lcd_clear();
		lcd_set_cursor(0);
		lcd_write_string(itoa(ADCH << 1, snum, 10));
		wait(1000);				// every 100 ms (busy waiting)
	}
}

void adcInit( void )
{
	ADMUX  = 0b11100001;		// AREF=VCC, result left adjusted, channel3 at pin PF3, reference voltage is 2,56V
	ADCSRA = 0b11100110;		// ADC-enable, no interrupt, start, free running, division by 64
}

void wait( int ms )
{
	for (int tms=0; tms<ms; tms++)
		_delay_ms( 1 );			// library function (max 30 ms at 8MHz)
}
