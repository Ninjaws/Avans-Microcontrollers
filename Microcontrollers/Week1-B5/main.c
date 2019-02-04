/*
 * Week1-B5.c
 *
 * Created: 2-2-2019 11:22:00
 * Author : Daan & Max
 */ 

// Define handy constants
#define F_CPU 8000000L
#define ON 0x11111111
#define OFF 0x00000000
#define ALL_OUTPUT 0b11111111

#include <avr/io.h>
#include <util/delay.h>

// Cycle array where each element represents a state of the LED's in an animation
int cycle[] = {0b00000000, 0b10000001, 0b11000011, 0b11100111, 0b11111111};

void wait(int ms);
void changeRow(int row, int state);

int main(void)
{
	// Set all the rows to output mode to make sure all LED's can be set
	DDRA = ALL_OUTPUT;
	DDRB = ALL_OUTPUT;
	DDRC = ALL_OUTPUT;
	DDRD = ALL_OUTPUT;
	DDRE = ALL_OUTPUT;
	DDRF = ALL_OUTPUT;
	DDRG = ALL_OUTPUT;
	
	while (1)
	{
		int size = sizeof(cycle)/sizeof(int);
		for (int i = 0; i < size; i++)		// Perform all the states in the cycle with a delay
		{
			changeRow(0, cycle[i]);
			wait(200);
		}

		for (int i = size - 1; i >= 0; i--)		// Perform all the states in the cycle with a delay backwards
		{
			changeRow(0, cycle[i]);
			wait(200);
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

// Changes the LED's of a row using a number so it can be iterated upon
void changeRow(int row, int state)
{
	switch (row)
	{
		case 0:
		PORTA = state;
		break;
		case 1:
		PORTB = state;
		break;
		case 2:
		PORTC = state;
		break;
		case 3:
		PORTD = state;
		break;
		case 4:
		PORTE = state;
		break;
		case 5:
		PORTF = state;
		break;
		case 6:
		PORTG = state;
		break;
		default:
		break;
	}
}
