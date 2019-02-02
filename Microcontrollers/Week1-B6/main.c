/*
 * Week1-B6.c
 *
 * Created: 2-2-2019 11:22:30
 * Author : Gebruiker
 */ 

#define F_CPU 8000000L

#include <avr/io.h>
#include <util/delay.h>

int interval = 1000;

void wait(int ms);
void blink();


int main(void)
{
	
	DDRD = 0b11111111;
	DDRC = 0b00000000;
	
	int state = 0;
	int pressed = 0;
	
	
	while (1)
	{
		//Keep blinking constantly, at different intervals
		blink();
		
		if(!((PINC & 1) > 0)){
			pressed = 0;
			continue;
		}
		
		//Switch between state 0 and state 1.
		//Change the state only when the button was previously released
		//(to prevent it from switching constantly if the button is held down)
		if((state == 0) & (pressed == 0)){
			interval = 250;
			state = 1;
			pressed = 1;
		}
		else if ((state == 1) & (pressed == 0)){
			interval = 1000;
			state = 0;
			pressed = 1;
		}
	}
}

void blink(){
	wait(interval);
	PORTD = 0b10000000;
	wait(interval);
	PORTD = 0b00000000;
}

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

