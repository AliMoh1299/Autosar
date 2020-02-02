#include "dio.h"
#include "STD_Types.h"
#include "dio_cfg.h"

#define F_CPU 16000000UL
#include <util/delay.h>

int main()
{
	Dio_init();
		while(1)
	{ 
         Dio_WritePort(Dio_Port_D,0xF0);
    _delay_ms(1000);
         Dio_WritePort(Dio_Port_D,0x00);
	_delay_ms(2000);
	  	 Dio_WriteChannel(Dio_Channel_D7,STD_high);
	_delay_ms(500);
		 Dio_WriteChannel(Dio_Channel_D7,STD_low);
		 Dio_WriteChannel(Dio_Channel_D6,STD_high);
	_delay_ms(500);
		 Dio_WriteChannel(Dio_Channel_D6,STD_low);
		 Dio_WriteChannel(Dio_Channel_D5,STD_high);
	_delay_ms(500);
	     Dio_WriteChannel(Dio_Channel_D5,STD_low);
  
	}	
	return 0 ;
}
