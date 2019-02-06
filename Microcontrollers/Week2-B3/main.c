/*
 * T1B7A.c
 *
 * Created: 30-1-2019 15:24:21
 * Author : Max & Daan
 */ 

#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void changeValue(int);
void display(int);
void wait(int);

int value = 0;
int displayChars[] = {
	0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F,
	0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
};

int main( void )
{
	// Init I/O
	DDRD = 0xF0;			// PORTD(7:4) output, PORTD(3:0) input
	DDRC = 0xFF;			// All output

	// Init Interrupt hardware
	EICRA |= 0x3F;			// INT0 rising edge, INT2 rising edge
	EIMSK |= 0x07;			// Enable INT0 & INT2
	sei();
	
	display(value);
	//int i = 0;
	while (1)
	{
		/*display(i);
		wait(1000);
		i++;
		if (i >= 16)
			i = 0;*/
	}
	return 1;
}

ISR(INT0_vect)
{
	changeValue(1);
	display(value);
}

ISR(INT1_vect)
{
	changeValue(-1);
	display(value);
}

ISR(INT2_vect)
{
	value = 0;
	display(value);
}

void wait( int ms )
{
	for (int i=0; i<ms; i++)
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
}

void changeValue(int difference)
{
	value += difference;
	if (value < 0)
	value = 15;
	if (value > 15)
	value = 0;
}

void display(int digit)
{
	int displayValue;
	if (digit < 0 || digit > 15)
		displayValue = displayChars[14];
	else
		displayValue = displayChars[digit];
	PORTC = displayValue;
}
