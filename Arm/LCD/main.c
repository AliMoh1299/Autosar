#include "dio.h"
#include "lcd.h"



int main()
{
	LCD_int();
	while(1)
	{

		//LCD_Clear();
		delayUs(600);
		LCD_WriteCommand(0x80);
	//	LCD_GoToRowColumn(1,5);
		LCD_WriteData('A');
		delayUs(600);
	}
	return 0;
}