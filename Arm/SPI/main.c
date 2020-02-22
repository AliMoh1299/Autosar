#include <TM4C123GH6PM.h>
#include "spi.h"

int main()
{
Spi_Init();
uint16 x='5';
while(1)
{ 
CLR_BIT(GPIOB->DATA,5);
	Spi_WriteIB(&x);
SET_BIT(GPIOB->DATA,5);
}
	
}
