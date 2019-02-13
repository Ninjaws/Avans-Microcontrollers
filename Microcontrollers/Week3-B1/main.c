/*
 * Week3-B1.c
 *
 * Created: 13-Feb-19 14:42:36
 * Author : Daan
 */ 

#define F_CPU 8000000L

#include "lcd.h"

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Init I/O
	DDRD = 0xFF;			// PORTD(7) output, PORTD(6:0) input

	// Init LCD
	lcd_init();

	// Write sample string
	lcd_set_cursor(0);
	lcd_write_string("Yedi you are");
	lcd_set_cursor(24);
	lcd_write_string("not...");

	// Loop forever
	while (1)
	{
		PORTD ^= (1<<7);	// Toggle PORTD.7
		_delay_ms( 250 );
	}

	return 1;
}
