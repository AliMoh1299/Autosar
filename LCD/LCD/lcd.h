#include "STD_Types.h"
#include "bit_math.h"
#include "dio.h"
#define  F_CPU 16000000UL
#include <util/delay.h>

#define LCD_Port_Control	  PORTB_REG
#define LCD_Port_Data	      PORTA_REG	
#define LCD_Dir_Data		  DDRA_REG	
#define LCD_Dir_Control		  DDRB_REG
#define RS 	                  Dio_Channel_B1
#define RW 	                  Dio_Channel_B2
#define EN 	                  Dio_Channel_B3

void LCD_int(void);
void LCD_WriteCommand(uint8 Command);
void LCD_WriteData(uint8 Data);
void LCD_WriteString(uint8* String);
void LCD_Clear(void);
void LCD_GoToRowColumn(uint8 row, uint8 col);



