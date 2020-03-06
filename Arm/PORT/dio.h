#ifndef DIO_H_
#define DIO_H_
#include <TM4C123GH6PM.h>
#include "dio_types.h"
#include "STD_Types.h"
#include "bit_math.h"

void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId );
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId );
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId);

#endif /* DIO_H_ */