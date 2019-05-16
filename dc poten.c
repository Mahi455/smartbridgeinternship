/*
 * DC with poten.c
 *
 * Created: 5/15/2019 2:55:24 PM
 * Author : Chinni
 */ 

#include <avr/io.h>
#define F_CPU 1600000UL
#include <util/delay.h>
#include<stdlib.h>

#define E 5
#define RS 7

void send_a_command(unsigned char command);
void send_a_character(unsigned char character);
void send_a_string (char *string_of_characters);

void PWM_init()
{
	TCCR0=(1<<WGM00)|((1<<WGM01)|1<<COM01)|(1<<CS00);
	DDRB|=(1<<PB3);
}

int main(void)
{
	DDRC=0xFF;
	DDRA=0x00;
	DDRB=0xFF;
	DDRD=0XFF;
	_delay_ms(50);
	ADMUX|=(1<<REFS1)|(1<<REFS0);
	ADCSRA|=(1<<ADEN)|(1<<ADATE)|(1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2);
	
	int16_t COUNTA=0;
	char showa[3];
	send_a_command(0x01);
	_delay_ms(50);
	send_a_command(0x38);
	_delay_ms(50);
	send_a_command(0b00001111);
	_delay_ms(50);
	ADCSRA|=(1<<ADSC);
	PWM_init();
	while(1)
	{
		COUNTA=ADC/4;
		send_a_command(0x80+0x40+0);
		send_a_command(0x80+0x40+8);
		itoa(COUNTA,showa,10);
		send_a_string(showa);
		send_a_string("     ");
		send_a_command(0x80+0);
		if(COUNTA>0)
		{
			OCR0=COUNTA;
			PB0&=~(1<<PB3);
		}
	}
}
void send_a_command (unsigned char command)
{
	PORTC=command;
	
	
	PORTD&= ~(1<<RS);
	PORTD|=(1<<E);
	_delay_ms(50);
	PORTD&= ~(1<<E);
	PORTC=0;
}

void send_a_character (unsigned char character)
{
	PORTC=character;
	PORTD|=(1<<RS);
	PORTD|=(1<<E);
	_delay_ms(50);
	PORTD&= ~(1<<E);
	PORTC=0;
}
void send_a_string (char *string_of_characters)
{
	while(*string_of_characters>0)
	{
		send_a_character(*string_of_characters++);
	}
}

