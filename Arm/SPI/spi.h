#include <TM4C123GH6PM.h>
#include "spi_types.h"
#include "bit_math.h"






void Spi_InitAsMaster( void );
void Spi_InitAsSlave( void );
void Spi_WriteIB(  Spi_DataBufferType* DataBufferPtr );
void Spi_ReadIB(Spi_DataBufferType* DataBufferPointer);
