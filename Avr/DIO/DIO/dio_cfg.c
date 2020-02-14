#include "dio_cfg.h"
#include "dio_hw.h"
#include "bit_math.h"

const Dio_pin_configType Dio_pin_config[]={
	/*PA0*/		{PORT_PIN_OUT,STD_low},
	/*PA1*/		{PORT_PIN_OUT,STD_low},
	/*PA2*/		{PORT_PIN_OUT,STD_low},
	/*PA3*/		{PORT_PIN_OUT,STD_low},
	/*PA4*/		{PORT_PIN_OUT,STD_low},
	/*PA5*/		{PORT_PIN_OUT,STD_low},
	/*PA6*/	   	{PORT_PIN_OUT,STD_low},
	/*PA7*/		{PORT_PIN_OUT,STD_low},
	/*PB0*/		{PORT_PIN_OUT,STD_low},
	/*PB1*/		{PORT_PIN_OUT,STD_low},
	/*PB2*/		{PORT_PIN_OUT,STD_low},
	/*PB3*/		{PORT_PIN_OUT,STD_low},
	/*PB4*/		{PORT_PIN_OUT,STD_low},
	/*PB5*/		{PORT_PIN_OUT,STD_low},
	/*PB6*/		{PORT_PIN_OUT,STD_low},
	/*PB7*/		{PORT_PIN_OUT,STD_low},
	/*PC0*/		{PORT_PIN_OUT,STD_low},
	/*PC1*/		{PORT_PIN_OUT,STD_low},
	/*PC2*/		{PORT_PIN_OUT,STD_low},
	/*PC3*/		{PORT_PIN_OUT,STD_low},
	/*PC4*/		{PORT_PIN_OUT,STD_low},
	/*PC5*/		{PORT_PIN_OUT,STD_low},
	/*PC6*/		{PORT_PIN_OUT,STD_low},
	/*PC7*/		{PORT_PIN_OUT,STD_low},
	/*PD0*/		{PORT_PIN_OUT,STD_low},
	/*PD1*/		{PORT_PIN_OUT,STD_low},
	/*PD2*/		{PORT_PIN_OUT,STD_low},
	/*PD3*/		{PORT_PIN_OUT,STD_low},
	/*PD4*/		{PORT_PIN_OUT,STD_low},
	/*PD5*/		{PORT_PIN_OUT,STD_low},
	/*PD6*/		{PORT_PIN_OUT,STD_low},
	/*PD7*/		{PORT_PIN_OUT,STD_low}
};

void Dio_init()
{
	for (uint8 i =Dio_Channel_A0;i<PINNUM;i++)
	{
		
	  Dio_PortType channel_port=i/8;
   	  Dio_ChannelType channelPos=i%8;		
	if(Dio_pin_config[i].pinDirection ==PORT_PIN_OUT)
	{
		switch(channel_port)
	{
		case Dio_Port_A:
		SET_BIT(DDRA_REG,channelPos);
		break;
		case Dio_Port_B:
		SET_BIT(DDRB_REG,channelPos);
		break;
		case Dio_Port_C:
		SET_BIT(DDRC_REG,channelPos);
		break;
		case Dio_Port_D:
		SET_BIT(DDRD_REG,channelPos);
		break;
	}
		}
		else
		{
			switch (channel_port)
			{
				case Dio_Port_A:
				CLR_BIT(DDRA_REG,channelPos);
				break;
				case Dio_Port_B:
				CLR_BIT(DDRB_REG,channelPos);
				break;
				case Dio_Port_C:
				CLR_BIT(DDRC_REG,channelPos);
				break;
				case Dio_Port_D:
				CLR_BIT(DDRD_REG,channelPos);
				break;
			}
		  }
		}
	}


	