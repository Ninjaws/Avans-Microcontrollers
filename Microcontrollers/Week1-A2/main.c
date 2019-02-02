/*
 * Week1-A2.c
 *
 * Created: 2-2-2019 10:50:29
 * Author : Gebruiker
 */ 

#define F_CPU 8000

#include <avr/io.h>
#include <util/delay.h>

void wait(int ms);

int main(void)
{
	// set PORTD for output
	DDRD = 0b01111111;					// PORTD.7 input all other bits output
	PORTC = 0x10;						// ??
	
	while (1)
	{
		if (PINC & 0x80)
		{
			PORTD = 0x01;				// write 1 to all the bits of PortD
		}
		else
		{
			PORTD = 0x00;				// write 0 to all the bits of PortD
		}
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