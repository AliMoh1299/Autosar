#include "STD_Types.h"
#include "bit_math.h"
#include "dio.h"
#include "lcd_cfg.h"

void LCD_int(void);
void LCD_WriteCommand(uint8 Command);
void LCD_WriteData(uint8 Data);
void LCD_WriteString(uint8 *String);
void LCD_Clear(void);
void LCD_GoToRowColumn(uint8 row, uint8 col);
void delayMs(int n);
void delayUs(int n);


