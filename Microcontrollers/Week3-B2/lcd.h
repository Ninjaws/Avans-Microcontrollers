/*
 * lcd.h
 *
 * Created: 13-2-2019 20:08:47
 *  Author: Gebruiker
 */ 

void lcd_strobe_lcd_e(void);
void init_4bits_mode(void);
void lcd_write_string(char *str);
void lcd_write_data(unsigned char byte);
void lcd_write_command(unsigned char byte);
void setCursor(int pos);
void lcd_clear();