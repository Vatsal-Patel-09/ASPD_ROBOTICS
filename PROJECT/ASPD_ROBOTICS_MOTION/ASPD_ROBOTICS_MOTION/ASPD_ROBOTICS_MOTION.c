/*
 * ASPD_ROBOTICS_MOTION.c
 *
 * Created: 03-05-2024 14:22:17
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
void forward(void)
{
	PORTA= 0x06;
}
void stop(void)
{
	PORTA = 0x00;
}
void backward(void)
{	
	PORTA = 0x09;
}
void sharp_left(void)
{
	PORTA = PORTA | 0x05;
}
void sharp_right(void)
{
	PORTA = PORTA | 0x0A;
}
void soft_left(void)
{
	PORTA = PORTA | 0x04;
}
void soft_right(void)
{
	PORTA = PORTA | 0x02;
}
void soft_back_left(void)
{
	PORTA = PORTA | 0x01;
}
void soft_back_right(void)
{
	PORTA = PORTA | 0x08;
}

int main(void)
{
	motion_pin_config();
	//1
	
	forward();
	_delay_ms(2300);		
	stop();
	_delay_ms(100);
	
	
	sharp_right();
	_delay_ms(700);
	stop();
	//2
	forward();
	_delay_ms(1000);	
	stop();
	_delay_ms(100);
	
	
	sharp_right();
	_delay_ms(500);
	stop();
	//3
	forward();
	_delay_ms(1000);
	stop();
	_delay_ms(100);
	
	sharp_left();
	_delay_ms(800);
	stop();
	//4
	forward();
	_delay_ms(1500);
	stop();
	_delay_ms(100);
	
	//perfect
	
	
	sharp_right();
	_delay_ms(750);
	stop();
	//5
	forward();
	_delay_ms(2200);
	stop();
	_delay_ms(100);
	
	sharp_right();
	_delay_ms(700);
	stop();
	//6
	forward();
	_delay_ms(1500);
	stop();
	_delay_ms(100);
	
	sharp_left();
	_delay_ms(700);
	stop();
	//7
	forward();
	_delay_ms(1200);
	stop();
	_delay_ms(100);
	
	sharp_right();
	_delay_ms(350);
	stop();
	//8
	forward();
	_delay_ms(1000);
	stop();
	_delay_ms(100);
	
	sharp_right();
	_delay_ms(800);
	stop();
	//9
	forward();
	_delay_ms(1500);
	stop();
}