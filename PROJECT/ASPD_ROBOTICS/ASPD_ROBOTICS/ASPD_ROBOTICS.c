/*
 * ASPD_ROBOTICS.c
 *
 * Created: 03-05-2024 12:22:31
 *  Author: Vatsal Patel
 */ 
#define F_CPU 14745600
#include <util/delay.h>
#include <avr/io.h>

void buzzer_pin_config(void)
{
	DDRC = 0x08;
	PORTC = 0x00;
}

void buzzer_on(void)
{
	PORTC = PORTC | 0x08;
}

void buzzer_off(void)
{
	PORTC = PORTC & 0xF7;
}
void ctrl(void)
{
	
	buzzer_pin_config();
	
	buzzer_on();
	_delay_ms(3000);
	
	buzzer_off();
	_delay_ms(3000);
	
	buzzer_on();
	_delay_ms(2000);
	
	buzzer_off();
	_delay_ms(2000);
	
	buzzer_on();
	_delay_ms(1000);
	
	buzzer_off();	
	_delay_ms(1000);
}
int main(void)
{
	ctrl();
	ctrl();
	ctrl();
}