#include "STD_Types.h"
#include "bit_math.h"
#include "lcd.h"
#include "lcd_cfg.h"



void delayMs(int n){
	int x,y;
	for(x=0;x<n;x++){
		for(y=0;y<3180;y++){}
		}
}

void delayUs(int n){
	
	int x,y;
	for(x=0;x<n;x++){
		for(y=0;y<3;y++){}
		}
}

void LCD_int()
{ 
	SYSCTL->RCGCGPIO=(1U<<1)|(1U<<0);
	LCD->DATA=0xFF;
	LCD->DEN=0xFF;
	delayUs(40);		
//LCD_WriteCommand(0x33); 
//LCD_WriteCommand(0x32);	
	LCD_WriteCommand(0x28);	
  LCD_WriteCommand(0x0c);	
	LCD_WriteCommand(0x06);	
	LCD_WriteCommand(0x01);	
}

void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
	delayUs(40);
	LCD_WriteCommand(0x80); 
delayUs(40);
}

void LCD_WriteString(uint8 *String)
{
	while((*String) != 0)
	{
		delayUs(40);
		LCD_WriteData(*String);
	delayUs(40);
		String++;
	}
}

void LCD_WriteCommand(uint8 Command)
{   
		Dio_WriteChannel(RW,STD_low);

	LCD_Port = (LCD_Port & 0x0F) | (Command & 0xF0);
	Dio_WritePort(Dio_Port_B,((LCD_Port & 0x0F) | (Command & 0xF0)));
	Dio_WritePort(LCD_Dir,STD_low);
	Dio_WriteChannel(RS,STD_low);
	Dio_WriteChannel(EN,STD_high);
	delayUs(40);
	Dio_WriteChannel(EN,STD_low);	
    delayUs(40);
	Dio_WritePort(Dio_Port_B,((LCD_Port & 0x0F) | (Command << 4)));
	Dio_WriteChannel(EN,STD_high);
    delayUs(40);
	Dio_WriteChannel(EN,STD_low);	
	delayUs(40);	
}

void LCD_WriteData(uint8 Data)
{
	LCD_Port = (LCD_Port& 0x0F) | (Data & 0xF0);
	Dio_WritePort(Dio_Port_B,((LCD_Port & 0x0F) | (Data & 0xF0)));
	Dio_WriteChannel(RS,STD_high);
	Dio_WriteChannel(EN,STD_high);
	delayUs(40);
	Dio_WriteChannel(EN,STD_low);
	delayUs(40);
	Dio_WritePort(Dio_Port_B,((LCD_Port & 0x0F) | (Data << 4)));
	Dio_WriteChannel(EN,STD_high);
	delayUs(40);
	Dio_WriteChannel(EN,STD_low);
	delayUs(40);
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
