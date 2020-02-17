#define  F_CPU 16000000UL
#include <util/delay.h>

#define LCD_Port_Control	  PORTB_REG
#define LCD_Port_Data	      PORTA_REG
#define LCD_Dir_Data		  DDRA_REG
#define LCD_Dir_Control		  DDRB_REG
#define RS 	                  Dio_Channel_B1
#define RW 	                  Dio_Channel_B2
#define EN 	                  Dio_Channel_B3