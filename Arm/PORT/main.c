#include "port.h"
#include "dio.h"

int main()
{ 
SET_BIT(SYSCTL->RCGC2,5);	
uint32	Delay=SYSCTL->RCGC2;	
Port_Init(&Config);
		

	while(1)
	{
Dio_WriteChannel(Dio_Channel_F1,STD_high);
Dio_WriteChannel(Dio_Channel_F2,STD_high);
Dio_WriteChannel(Dio_Channel_F3,STD_high);
	}
return 0;
}