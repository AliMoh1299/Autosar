#include <TM4C123GH6PM.h>
#include "spi_types.h"
#include "bit_math.h"






void Spi_Init( void );
void Spi_WriteIB(  Spi_DataBufferType* DataBufferPtr );
uint8 Spi_ReadIB( void );
