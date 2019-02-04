/*
 * Week1-B2.c
 *
 * Created: 2-2-2019 11:14:33
 * Author : Daan & Max
 */ 

// Define some handy constants
#define F_CPU 8000000L
#define ON 0xF0			// hex code to turn all LED's on
#define OFF 0xF			// hex code to turn all LED's off

#include <avr/io.h>
#include <util/delay.h>

void wait(int ms);

int main(void)
{
	DDRD = 0b11111111;			// Set all pins to output mode
	
	while (1)
	{
		PORTD = ON;			    // Turn all LED's on
		wait( 250 );
		PORTD = OFF;			// Turn all LED's off
		wait( 250 );
	}
	return 1;
}

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}
