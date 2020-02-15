#include "dio.h"
#include "lcd.h"



int main()
{
	LCD_int();
	while(1)
	{

		LCD_Clear();
		delayMs(1000);
		LCD_GoToRowColumn(1,5);
		LCD_WriteData('A');
		delayMs(1000);
	}
	return 0;
}