/*
 * lcd.h
 *
 * Created: 13-2-2019 13:46:15
 *  Author: User
 */ 


#define LCD_E 	3
#define LCD_RS	2

void init();
void display_text(char *str);
void display_char(unsigned char byte);
void lcd_command(unsigned char byte);
void set_cursor(int position);
void lcd_strobe_lcd_e();