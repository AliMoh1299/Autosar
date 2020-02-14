#include "port.h"

int main()
{
	Port_Init( Port_config );
	while (1)
	{
		PORTD_REG=0b11100000;
	}
	return 0;
}