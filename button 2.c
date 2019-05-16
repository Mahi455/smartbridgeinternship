/*
 * button.c
 *
 * Created: 5/10/2019 11:22:13 AM
 * Author : Chinni
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

 
int main(void)
{
	DDRB=0XFF;
	DDRD=0X00;
	
	
    /* Replace with your application code */
    while (1) 
    {
		if((PIND &(1<<PD0)) == 0)
		{
			PORTB=0X80;
			_delay_ms(100);
			PORTB=0X40;
			_delay_ms(100);
			PORTB=0X20;
			_delay_ms(100);
			PORTB=0X10;
			_delay_ms(100);
			PORTB=0X01;
			_delay_ms(100);
			PORTB=0X02;
			_delay_ms(100);
			PORTB=0X04;
			_delay_ms(100);
			PORTB=0X02;
			_delay_ms(100);
			PORTB=0X01;
			_delay_ms(100);
			}
			if((PIND &(1<<PD0)) == 1)
			{
				PORTB=0X08;
				_delay_ms(100);
				PORTB=0X04;
				_delay_ms(100);
				PORTB=0X02;
				_delay_ms(100);
				PORTB=0X01;
				_delay_ms(100);
				PORTB=0X10;
				_delay_ms(100);
				PORTB=0X20;
				_delay_ms(100);
				PORTB=0X40;
				_delay_ms(100);
				PORTB=0X80;
				_delay_ms(100);
				
    }
}

