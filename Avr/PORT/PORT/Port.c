#include "port.h"
#define PNUM 4
extern const Port_ConfigType Port_config []={
	
{OUTPUT},	//DDRA_REG
{OUTPUT},	//DDRB_REG
{OUTPUT},	//DDRC_REG
{OUTPUT}	//DDRD_REG
	// Da Kda Linktime Confg ?
};





void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{
uint8	 PortNum=Pin/8;
uint8	 PortType=Pin%8;

	 switch(PortType){
		 case Dio_Port_A:
		 if(Direction==PORT_PIN_IN)
		 {
			 CLR_BIT(DDRA_REG,Pin);
		 }
		 else
		 {
			 SET_BIT(DDRA_REG,Pin);
		 }
		 break;
		 
		 case Dio_Port_B:
		 if(Direction==PORT_PIN_IN)
		 {
			 CLR_BIT(DDRB_REG,Pin);
		 }
		 else
		 {
			 SET_BIT(DDRB_REG,Pin);
		 }
		 break;
		 
		 case Dio_Port_C:
		 if(Direction==PORT_PIN_IN)
		 {
			 CLR_BIT(DDRC_REG,Pin);
		 }
		 else
		 {
			 SET_BIT(DDRC_REG,Pin);
		 }
		 break;
		 
		 case Dio_Port_D:
		 if(Direction==PORT_PIN_IN)
		 {
			 CLR_BIT(DDRD_REG,Pin);
		 }
		 else
		 {
			 SET_BIT(DDRD_REG,Pin);
		 }
		 break;
	 }
}
		 
void Port_Init( const Port_ConfigType* ConfigPtr )
{
for (uint8 i=0;i<PNUM;i++)
{

	if (ConfigPtr[i].Port_DirectionType==OUTPUT)
{
	switch(i)
	{
		case 0:
				DDRA_REG=OUTPUT;
		break;
		case 1:
				DDRB_REG=OUTPUT;
		break;
		case 2:
				DDRC_REG=OUTPUT;		
		break;
		case 3:
				DDRD_REG=OUTPUT;		
		break;
	}
}
else
{
	switch(i)
	{
		case 0:
		DDRA_REG=INPUT;
		break;
		case 1:
		DDRB_REG=INPUT;
		break;
		case 2:
		DDRC_REG=INPUT;
		break;
		case 3:
		DDRD_REG=INPUT;
		break;	
	}
}



}
}
