/*
 * ASPD_ROBOTICS_LCD.c
 *
 * Created: 04-05-2024 11:57:19
 *  Author: Vatsal Patel
 */ 

#define F_CPU 14745600
#include <util/delay.h>
#include <avr/io.h>
#include "lcd.h"


int main(void)
{
    lcd_port_config();
	lcd_init();
	lcd_string(1,1,"ADANI UNIVERSITY");
	_delay_ms(500);
	lcd_string(2,6,"TEAM 3");
	_delay_ms(5000);
}