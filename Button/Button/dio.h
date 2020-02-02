#ifndef DIO_H_
#define DIO_H_

#include "STD_Types.h"
#include "dio_cfg.h"
#include "dio_hw.h"
#include "dio_types.h"

void Dio_WriteChannel(Dio_ChannelType Channel, STD_levelType level);
void Dio_WritePort(Dio_PortType portx,uint8 uxvalue);
void DIO_ReadPort(Dio_ChannelType channel,uint8 *data);
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId );
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId);

#endif /* DIO_H_ */