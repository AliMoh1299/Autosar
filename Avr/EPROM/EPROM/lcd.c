#include "STD_Types.h"
#include "bit_math.h"
#include "lcd.h"





void LCD_int()
{ 
	LCD_Dir_Data=0xF0;     // data PORTA 4 to 7 pins
	LCD_Dir_Control=0x0F; // Control PORTB 0 tO 2  RS 1   RW 2   E 3 
	_delay_ms(20);		/* LCD Power ON delay always >15ms */	
	LCD_WriteCommand(0x33); //3 3 3 2
	LCD_WriteCommand(0x32);	/* Send for 4 bit initialization of LCD  */
	LCD_WriteCommand(0x28);	/* 2 line, 5*8 matrix in 4-bit mode */
    LCD_WriteCommand(0x0c);	/* Display on cursor off */
	LCD_WriteCommand(0x06);	/* Increment cursor (shift cursor to right) */
	LCD_WriteCommand(0x01);	/* Clear display screen */
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
	_delay_ms(10);
	LCD_WriteCommand(0x80); // Yrg3 ll home
	_delay_ms(10);
}

void LCD_WriteString(uint8 *String)
{
	while((*String) != 0)
	{
		_delay_ms(10);
		LCD_WriteData(*String);
		_delay_ms(10);
		String++;
	}
}

void LCD_WriteCommand(uint8 Command)
{   
	LCD_Port_Data = (LCD_Port_Data & 0x0F) | (Command & 0xF0);
	Dio_WritePort(Dio_Port_A,((LCD_Port_Data & 0x0F) | (Command & 0xF0)));
	Dio_WritePort(LCD_Dir_Control,STD_low);
	Dio_WriteChannel(RS,STD_low);
	Dio_WriteChannel(EN,STD_high);
	_delay_ms(10);
	Dio_WriteChannel(EN,STD_low);	
    _delay_ms(10);
	Dio_WritePort(Dio_Port_A,((LCD_Port_Data & 0x0F) | (Command << 4)));
	Dio_WriteChannel(EN,STD_high);
	_delay_ms(10);
	Dio_WriteChannel(EN,STD_low);	
	_delay_ms(10);	
}

void LCD_WriteData(uint8 Data)
{
	LCD_Port_Data = (LCD_Port_Data & 0x0F) | (Data & 0xF0);
	Dio_WritePort(Dio_Port_A,((LCD_Port_Data & 0x0F) | (Data & 0xF0)));
	Dio_WriteChannel(RS,STD_high);
	Dio_WriteChannel(EN,STD_high);
	_delay_ms(10);
	Dio_WriteChannel(EN,STD_low);
	_delay_ms(10);
	Dio_WritePort(Dio_Port_A,((LCD_Port_Data & 0x0F) | (Data << 4)));
	Dio_WriteChannel(EN,STD_high);
	_delay_ms(10);
	Dio_WriteChannel(EN,STD_low);
	_delay_ms(10);
}

void LCD_GoToRowColumn(uint8 row, uint8 col)
{
	uint8 Address=0;
	switch(row)
	{
		case 0:
		Address=col;
		break;
		case 1:
		Address=col+0x40;
		break;
		
	}
	
	LCD_WriteCommand(Address | 0x80);
}
