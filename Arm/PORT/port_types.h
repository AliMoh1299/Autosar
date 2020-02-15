#include "STD_Types.h"
#include "dio_types.h"
#include <TM4C123GH6PM.h>


typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;

typedef GPIOA_Type Port_ConfigType;

typedef Dio_ChannelType Port_PinType;