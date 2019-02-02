/*
 * Week1-B2.c
 *
 * Created: 2-2-2019 11:14:33
 * Author : Gebruiker
 */ 

#define F_CPU 8000000L
#define ON 0xF0
#define OFF 0xF

#include <avr/io.h>
#include <util/delay.h>

void wait(int ms);

int main(void)
{
	DDRD = 0b11111111;			// Pins 6+7 PORTD are set to output
	
	while (1)
	{
		PORTD = ON;			// Write 10101010b PORTD
		wait( 250 );
		PORTD = OFF;			// Write 01010101b PORTD
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


