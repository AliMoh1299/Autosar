#include "port.h"

int main()
{ 
	     SET_BIT(SYSCTL->RCGC2,5);

	Port_Init(GPIOF,PORT_PIN_OUT);
	while(1)
	{
		GPIOF->DATA=0b10;
	}
return 0;
}