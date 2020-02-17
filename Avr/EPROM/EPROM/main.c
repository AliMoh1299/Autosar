//#include <avr/io.h>
#include "EEPROM.h"
#include "dio.h"
#include "lcd.h"
#include <util/delay.h>

int main(void)
{
	LCD_int();
 uint8 val = '9';
 uint8 x = 'A';

	  DDRD_REG  = 0xFF;
	    Eep_Init();
		Eep_Write(0x0001,&x/*,2)*/);
		_delay_ms(10);
		Eep_Read(0x0001,&val/*,2*/);
		
	LCD_Clear();	
	while(1)
	{
		LCD_GoToRowColumn(0,8);
		LCD_WriteData(val);
	}
	return 0;
}