#include "port.h"

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
		 
	