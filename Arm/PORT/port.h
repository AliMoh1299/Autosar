#include "port_types.h"
#include "bit_math.h"
#include "STD_Types.h"
#include "dio.h"

void Port_Init(  Port_ConfigType* ConfigPtr );
void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
extern const Port_ConfigType Config[];

 