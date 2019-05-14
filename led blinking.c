/*
 * ledblink.c
 *
 * Created: 5/9/2019 2:20:04 PM
 * Author : Chinni
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util\delay.h>


int main(void)
{
	DDRA=0X80;
	DDRB=0X80;
	DDRC=0X80;
	DDRD=0X80;
    /* Replace with your application code */
    while (1) 
		PORTA=0X80;
		_delay_ms(100);
		PORTB=0x80;
		_delay_ms(100);
		PORTC=0X80;
		_delay_ms(100);
		PORTD=0x80;
		_delay_ms(100);
    }
}

































