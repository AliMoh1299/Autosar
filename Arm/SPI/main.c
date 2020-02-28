#include <TM4C123GH6PM.h>
#include "spi.h"

int main()
{
	Spi_InitAsMaster();
uint8 x;
while(1)
{
x=1;	
Spi_WriteIB(&x);
for(int i = 0 ; i<10000 ; i++){}	
x=9;	
Spi_WriteIB(&x);
for(int i = 0 ; i<10000 ; i++){}	
}	
}