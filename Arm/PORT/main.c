#include "port.h"

int main()
{ 
	     SET_BIT(SYSCTL->RCGC2,5);

	while(1)
	{
		GPIOF->DATA=0b110;
	}
return 0;
}