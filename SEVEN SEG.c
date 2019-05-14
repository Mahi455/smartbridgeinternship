/*
 * seven seg.c
 *
 * Created: 5/14/2019 9:54:16 AM
 * Author : Chinni
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA=0XFF;
	
    /* Replace with your application code */
    while (1) 
    {
		PORTA=0XEE;
		_delay_ms(1000);
		PORTA=0XFE;
		_delay_ms(1000);
		PORTA=0X9C;
		_delay_ms(1000);
		PORTA=0XFC;
		_delay_ms(1000);
		PORTA=0X9E;
		_delay_ms(1000);
		PORTA=0X8E;
		_delay_ms(1000);
		PORTA=0XBE;
		_delay_ms(1);
		PORTA=0XE0;
		_delay_ms(10);
		PORTA=0XFE;
		_delay_ms(10);
		PORTA=0XB6;
		_delay_ms(5);
		
		
		
		
		_delay_ms(100);
		PORTA=0XFD;
		
    }
}

