/*
 * ASPD_ROBOTICS_PWM.c
 *
 * Created: 04-05-2024 10:07:16
 *  Author: Vatsal Patel
 */ 
#define F_CPU 14745600
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

void motion_pin_config(void)
{
	DDRA = 0x0F;
	PORTA = 0x00;
	DDRL = 0x18;
	PORTL = 0x18;
}
// MOTION
void forward(void)
{
	PORTA = 0x06;
}
void backward(void)
{
	PORTA = 0x09;
}
void stop(void)
{
	PORTA = 0x00;
}
void soft_back_right(void)
{
	PORTA = 0x08;
}
void soft_back_left(void)
{
	PORTA = 0x01;
}
void sharp_left(void)
{
	PORTA = 0x05;
}
//PWM
void velocity(unsigned char Lm,unsigned char Rm)
{
	OCR5AL = (unsigned char )Lm;
	OCR5BL = (unsigned char )Rm;
}
void timer5_init()
{
	TCCR5A = 0xA9;
	TCCR5B = 0x0B;
	TCNT5L= 0x00;
	OCR5AH = 0x00;
	OCR5AL = 0xFF;
	OCR5BH = 0x00;
	OCR5BL = 0xFF;
}
// BUZZER
void buzzer_pin_config(void)
{
	DDRC = 0x08;
	PORTC = 0x00;
}

void buzzer_on(void)
{
	PORTC = 0x08;
}

void buzzer_off(void)
{
	PORTC = 0xF7;
}

int main(void)
{
	motion_pin_config();
	timer5_init();
	buzzer_pin_config();
	// led team 3
	lcd_port_config();
	lcd_init();
	lcd_string(1,6,"TEAM 3");
	
	// forward 1
	lcd_string(2,5,"FORWARD");
	forward();
	velocity(255,255);
	_delay_ms(3000);
	stop();
	
	//reverse parking
	lcd_string(2,5,"REVERSE");
	for (int i = 0; i<=5;i++)
	{
		buzzer_on();
		_delay_ms(100);
		buzzer_off();
		backward();
		velocity(110,210);
		_delay_ms(510);
	}
	
	lcd_clear();
	lcd_string(1,6,"TEAM 3");
	lcd_string(2,5,"FORWARD");
	stop();       //parked
	_delay_ms(3000);
	
	sharp_left();
	_delay_ms(1050); //rotation
	stop();
	
	// forward after parking
	lcd_clear();
	lcd_string(1,6,"TEAM 3");
	lcd_string(2,5,"FORWARD");
	forward();
	velocity(255,255);
	_delay_ms(2000);
	stop();
	
	//oriant towards left 
	sharp_left();
	_delay_ms(550);
	stop();
	
	//left soft turn
	lcd_clear();
	lcd_string(1,6,"TEAM 3");
	lcd_string(2,5,"CURVE");
	forward();
	velocity(105,250);
	_delay_ms(3400);
	stop();
	
	// forward 2
	lcd_clear();
	lcd_string(1,6,"TEAM 3");
	lcd_string(2,5,"FORWARD");
	forward();
	velocity(255,255);
	_delay_ms(2500);
	stop();
	
	//sharp left 
	sharp_left();
	_delay_ms(650);
	stop();
	
	//forward final
	forward();
	velocity(255,255);
	_delay_ms(2800);
	stop();
	
}	