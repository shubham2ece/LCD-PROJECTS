#include<avr/io.h>
#define F_CPU8000000UL
#include<util/delay.h>
#define RS (1<<0)
#define RW (1<<1)
#define EN (1<<2)
void lcd_init(); 
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);

void main()
{ 
	
	DDRD=0xff;
	DDRB=0xff;
	unsigned char_name[4]="ABCD";
	lcd_init();
	lcd_cmd(0x84);
	for(i=0; i<4; i++)
	{
		lcd_data(name[i]);
	}	
}	  	      
	
void lcd_init()
{
	lcd_cmd(0x38);
	lcd_cmd(0x0C);
	lcd_cmd(0x01);
	lcd_cmd(0x80);
	lcd_cmd(0x06);
	
}
void lcd_data(unsigned char data)
{
	PORTB=PORTB|RS;
	PORTB=PORTB&~RW;
	PORTD=data;
	PORTB=PORTB|EN;
	_delay_ms(2);
	PORTB=PORTB&~EN;
}
void lcd_cmd(unsigned char cmd)
{
	PORTB=PORTB&~RS;
	PORTB=PORTB&~RW;
	PORTD=cmd;
	PORTB=PORTB|EN;
	_delay_ms(2);
	PORTB=PORTB&~EN;
	
}