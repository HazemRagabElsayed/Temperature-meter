/*
 * temperature_meter.c
 *
 * Created: 26/04/2024 10:32:52 ص
 *  Author: Hazem Ragab Elsayed
 */ 


#include<avr/io.h>
#define  F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "LCD.h"
#include "ADC.h"
volatile unsigned short temp;
unsigned short counter = 0;
int main(void)
{
	LCD_init();
	ADC_init();
	temp = .25 * ADC_read();
	
	LCD_send_string("Temperature=");
	while(1)
	{
		temp = .25 * ADC_read();
		
		if(temp < 10)
		{
			LCD_move_cursor(1,13);
			LCD_send_char(temp + 48);
			LCD_send_char(0xdf);
			LCD_send_char('C');
			LCD_send_char(0x20);
			LCD_move_cursor(2,1);
			LCD_send_string("     ");
		}
		if(temp < 100 && temp >= 10)
		{
			LCD_move_cursor(1,13);
			LCD_send_char(temp / 10 + 48);
			LCD_send_char(temp % 10 + 48);
			LCD_send_char(0xdf);
			LCD_send_char('C');
			LCD_move_cursor(2,1);
			LCD_send_string("     ");
		}
		if(temp<1000 && temp >= 100)
		{
			LCD_move_cursor(1,13);
			LCD_send_string("    ");
			LCD_move_cursor(2,1);
			LCD_send_char(temp / 100 + 48);
			LCD_send_char(temp / 10 % 10 + 48);
			LCD_send_char(temp % 10 + 48);
			LCD_send_char(0xdf);
			LCD_send_char('C');
		}
		
		
	}
}
