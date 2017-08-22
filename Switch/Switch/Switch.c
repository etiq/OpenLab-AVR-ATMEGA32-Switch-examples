/*
 * Switch.c
 *
 * Created: 3/21/2016 10:42:38 AM
 * Author : Etiq Technologies
 *
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

/* 
PRESS PD1 to start the LED blinking.
PRESS PD0 to stop the LED blinking.
*/

int main(void)
{    
	DDRC=0xFF;    //configure PORTD as input and PORTC as output
	DDRD=0x00;
	PORTD=0xff;
	PORTC=0x00;

	while(1)
	{
	if((PIND & (1<<PD1))==0)           //if switch at the PD1 pin pressed
	{
	while((PIND & (1<<PD1))==0);      //wait until debounce
    while(1)
    {
	    PORTC=0xFF;      //PORTC loaded with 0xff for 250 ms and 0x00 for next 250ms
	    _delay_ms(250);
	    PORTC=0x00;
	    _delay_ms(250);
		if((PIND & (1<<PD0))==0)           //if switch at PD0 pressed
		{
			PORTC=0x00;
			while((PIND & (1<<PD0))==0);        //wait until debounce
			break;                              //exit out of while loop
		}
	}
}
PORTC=0x00;
	}
}