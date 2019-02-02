/*
 * Week1-B3.c
 *
 * Created: 2-2-2019 11:21:13
 * Author : Gebruiker
 */ 

#define F_CPU 8000000L
#define ON 0xAA
#define OFF 0x55
#define ALL_OUTPUT 0b11111111;

#include <avr/io.h>
#include <util/delay.h>

void wait(int ms);
void blink();

int main(void)
{	
	//row of buttons.
	DDRC = 0b00000000;
	
	//row of lamps
	DDRD = 0b11111111;
	
	while (1)
	{
		unsigned int pinc = PINC;
		
		//checks if pin is on.
		if((pinc & 1) > 0){
			blink();
		}
		else {
			PORTD = 0b00000000;
		}
	}

	return 1;
}

void blink(){
	wait(250);
	PORTD = 0b10000000;
	wait(250);
	PORTD = 0b00000000;
}

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}


