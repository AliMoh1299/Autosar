#include "STD_Types.h"
#include "dio_hw.h"
#include "dio_types.h"

typedef uint8 Port_PinType ;

typedef struct{
	uint8 DDRA_REG;
	uint8 DDRB_REG;
	uint8 DDRC_REG;
	uint8 DDRD_REG;

	}Port_ConfigType;
typedef enum {
	
	PORT_PIN_IN=0,
	PORT_PIN_OUT
	
	}Port_PinDirectionType;
	
	void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
	