#include "dio.h"


 // Pins 012 control B
//  Pins  4567 Data B

#define LCD_Port        	    GPIOB->DATA
#define LCD	                  GPIOB
#define RS 	                  Dio_Channel_B0
#define RW 	                  Dio_Channel_B1
#define EN 	                  Dio_Channel_B2

