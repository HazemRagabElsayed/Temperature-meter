/*
 * LCD.h
 *
 * Created: 24/03/2024 07:47:02 ص
 *  Author: FREINDS
 */ 


#ifndef LCD_H_
#define LCD_H_
#define ENTRYMODE 0x06
#define CLRSCREEN 0x01
#define RETURNHOME 0x02
#define CURSOR_OFF_DISPLAY_ON 0x0c
#define EIGHTBIT_MODE 0x38
#define RS 0
#define RW 1
#define EN 2

void LCD_init(void);
void LCD_send_char(char character);
void LCD_send_command(char command);
void LCD_send_string(char * string);
void LCD_move_cursor(char row,char col);
void LCD_Enable_pulse();





#endif /* LCD_H_ */