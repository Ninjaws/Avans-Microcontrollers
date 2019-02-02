/*
 * Week1-B4.c
 *
 * Created: 2-2-2019 11:21:36
 * Author : Gebruiker
 */ 

#define F_CPU 8000000L
#define ON 0x11111111
#define OFF 0x00000000
#define ALL_OUTPUT 0b11111111

#include <avr/io.h>
#include <util/delay.h>

void wait(int ms);
void changeRow(int row, int state);
void changeBit(int row, int bit, int on);
int getRow(int row);

int main(void)
{
	DDRA = ALL_OUTPUT;
	DDRB = ALL_OUTPUT;
	DDRC = ALL_OUTPUT;
	DDRD = ALL_OUTPUT;
	DDRE = ALL_OUTPUT;
	DDRF = ALL_OUTPUT;
	DDRG = ALL_OUTPUT;
	
	while (1)
	{
		for (int i = 0; i <= 6; i++)
		{
			changeRow(i, OFF);
		}
		for (int i = 0; i <= 6; i++)
		{
			for (int j = 0; j <= 7; j++)
			{
				changeBit(i, j, 1);
				wait(50);
			}
		}
		
		/*for (int i = 0; i <= 6; i++)
		{
			changeRow(i, ON);
			wait(50);
		}
		
		for (int i = 0; i <= 6; i++)
		{
			changeRow(i, OFF);
			wait(50);
		}*/
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

void changeBit(int row, int bit, int on)
{
	if (on == 1)
	{
		changeRow(row, getRow(row) | (1<<bit));
	} else
	{
		changeRow(row, getRow(row) | ~(1<<bit));
	}
}

int getRow(int row)
{
	int returnValue = 0;
	switch (row)
	{
		case 0:
		returnValue = PORTA;
		break;
		case 1:
		returnValue = PORTB;
		break;
		case 2:
		returnValue = PORTC;
		break;
		case 3:
		returnValue = PORTD;
		break;
		case 4:
		returnValue = PORTE;
		break;
		case 5:
		returnValue = PORTF;
		break;
		case 6:
		returnValue = PORTG;
		break;
		default:
		returnValue = 0;
		break;
	}
	return returnValue;
}