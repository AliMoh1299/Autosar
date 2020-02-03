#ifndef DIO_CFG_H_
#define DIO_CFG_H_

#include "STD_Types.h"
#include "dio_types.h"
#include "port.h"

#define PINNUM   32 // Pins Number In MCU
#define Port_PinType 8
typedef struct
{
	
	Port_PinDirectionType pinDirection;// To Determine Pin Output Or Input
	STD_levelType pinState;  // To Determine Pin High Or Low
	
}Dio_pin_configType;

extern const Dio_pin_configType Dio_pin_config [];


void Dio_init(void);

#endif /* DIO_CFG_H_ */