/*
 * LCD.c
 *
 * Created: 24/03/2024 
 *  Author: Hazem Ragab Elsayed
 */ 
#define F_CPU 8000000UL
#include<util/delay.h>
#include"LCD.h"
#include"DIO.h"
#include<avr/io.h>

void LCD_init()
{
	DIO_set_port_direction('D',1);
	DIO_vsetPINDir('C',RS,1);
	DIO_vsetPINDir('C',RW,1);
	DIO_vsetPINDir('C',EN,1);
	DIO_write('C',RW,0);
	
	LCD_send_command(ENTRYMODE);
	LCD_send_command(CURSOR_OFF_DISPLAY_ON);
	LCD_send_command(EIGHTBIT_MODE);
	LCD_send_command(CLRSCREEN);
	_delay_ms(10);
}

void LCD_send_command(char command)
{
	DIO_write('C',RS,0);
	DIO_write_port('D',command);
	LCD_Enable_pulse();
	_delay_ms(1);
}

void LCD_send_char(char character)
{
	DIO_write('C',RS,1);
	DIO_write_port('D',character);
	LCD_Enable_pulse();
}

void LCD_send_string(char * string)
{
	while(*string != '\0')
	{
		LCD_send_char(*string);
		string++;
	}
}

void LCD_move_cursor(char row,char col)
{
	if(row > 2 || row < 0 || col <0 || col > 16 )
	{
		LCD_send_command(RETURNHOME);
	}
	else if (1 == row)
	{
		LCD_send_command(0x80 + col -1);
	}
	else if (2 == row)
	{
		LCD_send_command(0xC0 + col - 1);
	}
}

void LCD_Enable_pulse()
{
	DIO_write('C',EN,1);
	_delay_ms(2);
	DIO_write('C',EN,0);
	_delay_ms(2);
}

