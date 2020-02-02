#include "dio.h"
#include "lcd.h"



int main()
{
	Dio_init();
	LCD_int();
	while(1)
	{
		LCD_Clear();
		_delay_ms(500);
		LCD_WriteString("Welcome Ali");
		_delay_ms(1000);
		LCD_Clear();
		_delay_ms(500);
		LCD_GoToRowColumn(1,5);
		LCD_WriteData('A');
		_delay_ms(1000);		
	}
	return 0;
}