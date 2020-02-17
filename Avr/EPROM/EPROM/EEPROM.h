#include "EEPROM_types.h"
#include "STD_types.h"
#include "I2C.h"
#include <util/delay.h>


void Eep_Init( /*const Eep_ConfigType* ConfigPtr*/ void );
Std_ReturnType Eep_Write( Eep_AddressType EepromAddress, const uint8* DataBufferPtr/*,Eep_LengthType Length */);
Std_ReturnType Eep_Read( Eep_AddressType EepromAddress, uint8* DataBufferPtr/* ,Eep_LengthType Length */);
