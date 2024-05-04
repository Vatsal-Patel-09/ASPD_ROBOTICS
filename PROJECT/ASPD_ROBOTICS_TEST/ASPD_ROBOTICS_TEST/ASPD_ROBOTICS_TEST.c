#define F_CPU 14745600

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "lcd.h"


void buzzer_on(void){
	PORTC |= 0x08;
}

void buzzer_off(void){
	PORTC &= 0x00;
}

void buzzer_pin_config() {
	DDRC |= 0x00;
	PORTC |= 0x00;
}
void motion_pin_config() {
	DDRA |= 0x0F;
	PORTA |= 0x00;
	DDRL |= 0x18;
	PORTL |= 0x18;
}

void timer5_init() {
	TCCR5A |= 0xA9;
	TCCR5B |= 0x0B;
	TCNT5H |= 0xFF;
	TCNT5L |= 0x00;
	OCR5AH |= 0x00;
	OCR5BH |= 0x00;
}

void velocity(unsigned char left_motor, unsigned char right_motor) {
	OCR5AL = (unsigned char)left_motor;
	OCR5BL = (unsigned char)right_motor;
}


void forward() {
	PORTA = 0x06;
}

void hard_left() {
	PORTA = 0x05;
}

void soft_left() {
	PORTA = 0x04;
}

void back() {
	PORTA = 0x09;
}

void stop() {
	PORTA &= 0x00;
	_delay_ms(500);
}


void init(void) {
	motion_pin_config();
	timer5_init();
	buzzer_pin_config();
	// forward();
	lcd_port_config();
	lcd_init();
}


void buzzer_start_stop() {
	buzzer_on();
	_delay_ms(1000);
	buzzer_off();
}

void fast_lcd() {
	lcd_string(1 , 5, "Fast");
	lcd_string(2, 4, "Forward");
}

void slow_lcd() {
	lcd_string(1 , 5, "slow");
	lcd_string(2, 4, "Forward");
}

int main(void)
{
	
	init();

	// 	lcd_string(1, 1, "Adani University");
	// 	_delay_ms(5000);
	// 	lcd_string(2, 3, "Team - 1");
	// 	_delay_ms(5000);
	// 	lcd_clear();
	// 	lcd_numeric_value(2, 6, 458, 4);
	
	// 1. forward fast
	fast_lcd();
	forward();
	velocity(255 ,255);
	_delay_ms(5000);
	lcd_clear();
	buzzer_start_stop();
	
	// 2. pause revers
	stop();
	forward();
	lcd_string(1 , 1, "revers");
	velocity(255, 0);
	_delay_ms(700);
	back();
	velocity(255, 255);
	_delay_ms(3535);
	lcd_clear();
	
	
	
	// 3. park change diraction
	forward();
	velocity(0, 255);
	_delay_ms(500);
	stop();
	for (int i = 0; i < 3; i++)
	{
		buzzer_start_stop();
	}
	forward();
	velocity(255, 255);
	_delay_ms(2500);
	stop();
	
	
	// 4. hard left then slow
	buzzer_start_stop();
	forward();
	hard_left();
	lcd_string(1, 2, "Hard left");
	velocity(100, 100);
	_delay_ms(1000);
	lcd_clear();
	
	
	forward();
	slow_lcd();
	velocity(100, 100);
	_delay_ms(9000);
	lcd_clear();
	stop();
	
	// 5. soft left then fast
	
	forward();
	lcd_string(1,2 , "soft left");
	soft_left();
	velocity(0, 255);
	_delay_ms(1400);
	stop();
	lcd_clear();
	fast_lcd();
	forward();
	velocity(255, 255);
	_delay_ms(5000);
	lcd_clear();
	stop();
	
	
	
	// 6. left then slow and end stop
	buzzer_start_stop();
	forward();
	hard_left();
	lcd_string(1, 2, "Hard left");
	velocity(100, 100);
	_delay_ms(1500);
	lcd_clear();
	forward();
	slow_lcd();
	velocity(100, 100);
	_delay_ms(17500);
	lcd_clear();
	stop();
	
	lcd_string(1, 2, "bye....");
	
}