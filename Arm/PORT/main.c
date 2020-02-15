#include "port.h"

int main()
{ 
Port_Init(GPIOF);
Port_SetPinDirection(Dio_Channel_F3,PORT_PIN_OUT);

	while(1)
	{
		GPIOF->DATA=0b01110;
	}
return 0;
}