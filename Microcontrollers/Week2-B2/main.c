/*
 * Week2-B2.c
 *
 * Created: 06-Feb-19 12:02:20
 * Author : Daan & Max
 */ 

#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int bit = 0;

void wait(int);
void showLight();

int main(void)
{
	// Init I/O
	DDRD = 0xF0;			// PORTD(7:4) output, PORTD(3:0) input
	DDRC = 0xFF;			// All output

	// Init Interrupt hardware
	EICRA |= 0x3F;			// INT1 rising edge, INT2 rising edge
	EIMSK |= 0x07;			// Enable INT1 & INT2
	sei();

	while (1)
	{
		
	}
	return 1;
}

void wait(int ms)
{
	for (int i=0; i<ms; i++)
		_delay_ms(1);		// library function (max 30 ms at 8MHz)
}

ISR(INT1_vect)
{
	bit++;
	showLight();
}

ISR(INT2_vect)
{
	bit--;
	showLight();	
}

void showLight()
{
	if (bit < 0)
		bit = 7;
	if (bit > 7)
		bit = 0;
	
	PORTC = 1 << bit;
}
