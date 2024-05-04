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

void motion_pin_config(void)
{
	DDRA = 0x0F;
	PORTA = 0x00;
	DDRL = 0x18;
	PORTL = 0x18;
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

void forward(void)
{
	PORTA = 0x06;
}
void stop(void)
{
	PORTA = 0x00;
}
void velocity(unsigned char Lm,unsigned char Rm)
{
	OCR5AL = (unsigned char )Lm;
	OCR5BL = (unsigned char )Rm;
}
int main(void)
{
	motion_pin_config();
	timer5_init();
	//1
	forward();
	velocity(160,160);
	_delay_ms(5000);
	stop();
	//turn right
	forward();
	velocity(255,0);
	_delay_ms(1800);
	//2
	forward();
	velocity(200,200);
	_delay_ms(2000);
	stop();
	//turn left
	forward();
	velocity(0,255);
	_delay_ms(1500);
	//3
	forward();
	velocity(200,200);
	_delay_ms(2000);
	stop();
	//right turn
	forward();
	velocity(255,0);
	_delay_ms(1900);
	//4
	forward();
	velocity(255,255);
	_delay_ms(3500);
	stop();
	//u turn
	forward();
	velocity(240,140);
	_delay_ms(7500);
	stop();
		
}	