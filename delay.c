/*
 * delay.c
 *
 * Created: 5/15/2019 10:44:52 AM
 * Author : Chinni
 */ 

#include <avr/io.h>
#define LED PB0

int main()
{
	uint8_t timeroverflowcount=0;
	DDRB=0xFF;
	TCNT0=0X00;
	TCCR0=(1<<CS00)|(1<<CS02);
	while(1)
	{
		
			while((TIFR & 0x01)==0);
			TCNT0=0x00;
			TIFR=0x01;
			timeroverflowcount++;
			if(timeroverflowcount>=6)
			{
				PORTB=0xFF;
				timeroverflowcount=0;
			}
	}
}

