/*
 * Week3-B2.c
 *
 * Created: 13-2-2019 20:05:26
 * Author : Gebruiker
 */ 

#define F_CPU 8000000L
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "lcd.h"

#define BIT(x)(1 << (x))

void wait (int ms);

unsigned int i = 0;

int main( void )
{
	TCCR2 = 0x07;
	unsigned char *c[7];
	DDRD &= ~BIT(7);
	DDRA = 0x00;
	init_4bits_mode();
	
	while (1)
	{
		//If a button from A is pressed...
		if((PINA & 1) > 0)
		{
			//... increase the counter
			i += 1;
			//Clear the screen
			lcd_clear();
			
			//convert the int number to a char *
			itoa(i, c, 10);
			//Write to the lcd
			lcd_write_string(c);
		}
	}
}

void wait (int ms)
{
	for (int i  = 0; i<ms; i++){
		_delay_ms(1);
	}
}

