#include "lcd.h"
#include <avr/io.h>
#include <util/delay.h>

int main(){
	{
		// Init I/O
		DDRD = 0xFF;			// PORTD(7) output, PORTD(6:0) input

		// Init LCD
		init();

		// Write sample string
		display_text("daan");
		set_cursor(8);	// Toggle PORTD.7

		// Loop forever
		while (1)
		{
			PORTD ^= (1<<7);
			
			
		}

		return 1;
	}

}