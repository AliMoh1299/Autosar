#include "dio_cfg.h"
#include "dio_hw.h"
#include "bit_math.h"

const Dio_pin_configType Dio_pin_config[]={
	/*PA0*/		{Output,STD_low},
	/*PA1*/		{Output,STD_low},
	/*PA2*/		{Output,STD_low},
	/*PA3*/		{Output,STD_low},
	/*PA4*/		{Output,STD_low},
	/*PA5*/		{Output,STD_low},
	/*PA6*/	   	{Output,STD_low},
	/*PA7*/		{Output,STD_low},
	/*PB0*/		{Output,STD_low},
	/*PB1*/		{Output,STD_low},
	/*PB2*/		{Output,STD_low},
	/*PB3*/		{Output,STD_low},
	/*PB4*/		{Output,STD_low},
	/*PB5*/		{Output,STD_low},
	/*PB6*/		{Output,STD_low},
	/*PB7*/		{Output,STD_low},
	/*PC0*/		{Output,STD_low},
	/*PC1*/		{Output,STD_low},
	/*PC2*/		{Output,STD_low},
	/*PC3*/		{Output,STD_low},
	/*PC4*/		{Output,STD_low},
	/*PC5*/		{Output,STD_low},
	/*PC6*/		{Output,STD_low},
	/*PC7*/		{Output,STD_low},
	/*PD0*/		{Output,STD_low},
	/*PD1*/		{Output,STD_low},
	/*PD2*/		{Output,STD_low},
	/*PD3*/		{Output,STD_low},
	/*PD4*/		{Output,STD_low},
	/*PD5*/		{Output,STD_low},
	/*PD6*/		{Output,STD_low},
	/*PD7*/		{Output,STD_low},
};

void Dio_init()
{
	for (uint8 i =Dio_Channel_A0;i<PINNUM;i++)
	{
		
	  Dio_PortType channel_port=i/8;
   	  Dio_ChannelType channelPos=i%8;		
	if(Dio_pin_config[i].pinDirection ==Output)
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


	