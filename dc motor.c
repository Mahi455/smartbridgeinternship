/*
 * dc motor.c
 *
 * Created: 5/15/2019 2:15:32 PM
 * Author : Chinni
 */ 



#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <util\delay.h>


int main(void)
{
	DDRA=0XFF;
    /* Replace with your application code */
    while (1) 
    {
		PORTA=0X01;
		_delay_ms(1000);
		PORTA=0X00;
		
		_delay_ms(1000);
		PORTA=0X10;
		_delay_ms(1000);
		PORTA=0X00;
		_delay_ms(1000);
    }
}

