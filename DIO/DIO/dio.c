#include "dio.h"
#include "dio_hw.h"
#include "dio_types.h"
#include "STD_Types.h"
#include "bit_math.h"

void Dio_WritePort(Dio_PortType portx,uint8 uxvalue)
{
	switch (portx)
	{
		case Dio_Port_A :
		PORTA_REG=uxvalue;
		break;
		
		case Dio_Port_B :
		PORTB_REG=uxvalue;
		break;
		
		case Dio_Port_C :
		PORTC_REG=uxvalue;
		break;
		
		case Dio_Port_D :
		PORTD_REG=uxvalue;
		break;
		
	}
}

void Dio_WriteChannel(Dio_ChannelType channel,STD_levelType level)
{
			Dio_PortType channel_port=channel/8;     // Determine Port A,B,C,D
			Dio_ChannelType ChannelPos =channel%8;  //Determine Which Pin In Port A,B,C,D

	
	switch(channel_port){
		case Dio_Port_A:
		if(level == STD_low)
		{
			CLR_BIT(PORTA_REG,ChannelPos );
		}
		else
		{
			SET_BIT(PORTA_REG,ChannelPos );
		}
		break;
		case Dio_Port_B:
		if(level == STD_low)
		{
			CLR_BIT(PORTB_REG,ChannelPos );
		}
		else
		{
			SET_BIT(PORTB_REG,ChannelPos );
		}
		break;
		case Dio_Port_C:
		if(level == STD_low)
		{
			CLR_BIT(PORTC_REG,ChannelPos );
		}
		else
		{
			SET_BIT(PORTC_REG,ChannelPos );
		}
		break;
		case Dio_Port_D:
		if(level == STD_low)
		{
			CLR_BIT(PORTD_REG,ChannelPos );
		}
		else
		{
			SET_BIT(PORTD_REG,ChannelPos );
		}
		break;
		
	}
	
}

void DIO_ReadPort(Dio_ChannelType channel,uint8 *data)
{
	Dio_PortType channel_port=channel/8;
	Dio_ChannelType channelPos=channel%8;
	switch(channel_port)
	{
		case Dio_Port_A:
		*data=GET_BIT(PINA_REG,channelPos);
		break;
		
		case Dio_Port_B:
		*data=GET_BIT(PINB_REG,channelPos);
		break;
		case Dio_Port_C:
		*data=GET_BIT(PINC_REG,channelPos);
		break;
		
		case Dio_Port_D:
		*data=GET_BIT(PIND_REG,channelPos);
		break;
		
	}
	
}

STD_levelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
		Dio_PortType channel_port=ChannelId/8;
		Dio_ChannelType channelPos =ChannelId%8;
		STD_levelType level;
		switch(channel_port){

			case Dio_Port_A:
			level=GET_BIT(PINA_REG,channelPos);
			return level;
			break;

			case Dio_Port_B:
			level=GET_BIT(PINB_REG,channelPos);
			return level;
			break;

			case Dio_Port_C:
			level=GET_BIT(PINC_REG,channelPos);
			return level;
			break;
			
			case Dio_Port_D:
			level=GET_BIT(PIND_REG,channelPos);
			return level;
			break;									
		}
}

STD_levelType Dio_FlipChannel( Dio_ChannelType ChannelId)
{
	Dio_PortType channel_port=ChannelId/8;    
	Dio_ChannelType ChannelPos =ChannelId%8;  
	
	switch(channel_port)
	{
		
		case Dio_Port_A:
		TOGGLE_BIT(PORTA_REG,ChannelPos);
		return GET_BIT(PORTA_REG,ChannelPos);
        break;
		
		case Dio_Port_B:
		TOGGLE_BIT(PORTB_REG,ChannelPos);
		return GET_BIT(PORTB_REG,ChannelPos);
		break;		

		case Dio_Port_C:
		TOGGLE_BIT(PORTC_REG,ChannelPos);
		return GET_BIT(PORTC_REG,ChannelPos);
		break;

		case Dio_Port_D:
		TOGGLE_BIT(PORTD_REG,ChannelPos);
		return GET_BIT(PORTD_REG,ChannelPos);
		break;
	}
}