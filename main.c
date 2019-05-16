/*
 * Gcca1.c
 *
 * Created: 5/12/2019 11:29:18 AM
 * Author : Chinni
 */ 
#ifndef F_CPU
#define F_CPU 16000000UL
#endif 
#include <avr/io.h>
#include <util/delay.h>

#define RS 7
#define E 5
void send_command(unsigned char command);
void send_character(unsigned char character);
int main(void)
{
	DDRD=0XFF;
	DDRC=0XFF;
	
	_delay_ms(50);
	
	send_command(0x01);
	send_command(0x38);
	send_command(0x0E);
	
	send_character(0x4a);
	send_character(0x5a);
}

void send_command(unsigned char command)
{
	PORTD=command;
	PORTC&=~(1<<RS);
	PORTC|=(1<<E);
	_delay_ms(50);
	PORTC&=~(1<<E);
	PORTC=0;
}
 void send_character(unsigned char character)
 {
	 PORTD=character;
	 PORTC|=(1<<RS);
	 PORTC|=(1<<E);
	 _delay_ms(50);
	 PORTC&=~(1<<E);
	 PORTC=0;
 }


