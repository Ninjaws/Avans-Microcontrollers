/*
 * Week2-B4.c
 *
 * Created: 30-1-2019 15:24:21
 * Author : Max & Daan
 */ 

#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void display(int);
void wait(int);

int displayChars[] = {
	0x01, 0x02, 0x40, 0x10, 0x08, 0x04, 0x40, 0x20
};

int main( void )
{
	DDRC = 0xFF;			// All output
	
	int i = 0;
	while (1)				// Looping through all the chars
	{
		display(i);
		wait(100);
		i++;
		if (i >= 8)
			i = 0;
	}
	return 1;
}

void wait( int ms )
{
	for (int i=0; i<ms; i++)
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
}

void display(int digit)		// Lighting the display
{
	if (digit > 8)
		digit = 0;
	PORTC = displayChars[digit];
}
