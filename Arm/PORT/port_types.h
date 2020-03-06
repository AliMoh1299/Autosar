#include "STD_Types.h"
#include "dio_types.h"
#include <TM4C123GH6PM.h>


typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;

typedef struct{
uint32  DEN_R;      //1                        
uint32  LOCK_R;  //2                             
uint32  CR_R; //3
uint32  AFSEL_R ;//4
uint32  AMSEL_R ;//5
uint32  PCTL_R  ;//6
uint32  DIR_R ;	//7
}Port_ConfigType;

typedef Dio_ChannelType Port_PinType;