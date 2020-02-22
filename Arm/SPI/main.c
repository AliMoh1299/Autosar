#include <TM4C123GH6PM.h>
#include "spi.h"

int main()
{
uint8 x=5;
Spi_Init();

while(1)
{ 
GPIOB->DATA &=~(1<<5); // Begin Trans 
Spi_WriteIB(&x);
GPIOB->DATA |=(1<<5);  // End Trans
}
	
}