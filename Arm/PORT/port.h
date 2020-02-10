#include "port_types.h"
#include "bit_math.h"

//void Port_Init( const Port_ConfigType* ConfigPtr );
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
void Port_Init(GPIOA_Type *GPIO,Port_PinDirectionType Direction);
