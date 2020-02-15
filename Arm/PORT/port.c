#include "port.h"

#define UNLOCKED 0x4C4F434B
#define PINNUM   42

uint32 Delay;


void Port_Init(  Port_ConfigType* ConfigPtr )
{
	if(ConfigPtr==GPIOA)
{
	SET_BIT(SYSCTL->RCGC2,0);	
	Delay=SYSCTL->RCGC2;
}	

else if(ConfigPtr==GPIOB)
{
	SET_BIT(SYSCTL->RCGC2,1);	
	Delay=SYSCTL->RCGC2;
}		

else if(ConfigPtr==GPIOC)
{
	SET_BIT(SYSCTL->RCGC2,2);	
	Delay=SYSCTL->RCGC2;
}	

else if(ConfigPtr==GPIOD)
{
	SET_BIT(SYSCTL->RCGC2,3);	
	Delay=SYSCTL->RCGC2;
}	

else if(ConfigPtr==GPIOE)
{
	SET_BIT(SYSCTL->RCGC2,4);	
	Delay=SYSCTL->RCGC2;
}	

else if(ConfigPtr==GPIOF)
{
	SET_BIT(SYSCTL->RCGC2,5);	
	Delay=SYSCTL->RCGC2;
}	
  ConfigPtr->LOCK  = UNLOCKED ;
	ConfigPtr->DEN   = 0xFF ;
	ConfigPtr->CR    = 0xFF;
	ConfigPtr->AFSEL = 0;
	ConfigPtr->AMSEL = 0;
	ConfigPtr->PCTL  = 0;	


	
}


void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{

		uint32 channelpos;

	 channelpos =Pin%8;
//----------------------------------------------------------------------PORT A		
   if (Pin >=0 && Pin <=7)
	 {
		if(Direction == PORT_PIN_IN)
		{
			CLR_BIT(GPIOA->DIR,channelpos);
		}
	
		else
		 {
			SET_BIT(GPIOA->DIR,channelpos );
		 }
	 }
//----------------------------------------------------------------------PORT B
   else if (Pin >=8 && Pin <=15)
	 {
		if(Direction == PORT_PIN_IN)
		{
			CLR_BIT(GPIOB->DIR,channelpos);
		}
	
		else
		 {
			SET_BIT(GPIOB->DIR,channelpos );
		 }
	 }
//----------------------------------------------------------------------PORT C
   else if (Pin >=16 && Pin <=23)
	 {
		if(Direction == PORT_PIN_IN)
		{
			CLR_BIT(GPIOC->DIR,channelpos);
		}

		else
		 {
			SET_BIT(GPIOC->DIR,channelpos );
		 }
	 }
//----------------------------------------------------------------------PORT D
   else if (Pin >=24 && Pin <=31)
	 {
		if(Direction == PORT_PIN_IN)
		{
			CLR_BIT(GPIOD->DIR,channelpos);
		}
	
		else
		 {
			SET_BIT(GPIOD->DIR,channelpos );
		 }
	 }
//----------------------------------------------------------------------
//----------------------------------------------------------------------PORT E
   else if (Pin >=32 && Pin <=37)
	 {
		if(Direction == PORT_PIN_IN)
		{
			CLR_BIT(GPIOE->DIR,(Pin-32));
		}
	
		else
		 {
			SET_BIT(GPIOE->DIR,(Pin-32));
		 }
	 }
//----------------------------------------------------------------------PORT F

  else if (Pin >=38 && Pin <=43)
		 
	 {
		if(Direction == PORT_PIN_IN)
		{
			CLR_BIT(GPIOF->DIR,(Pin-38));
		}
	
		else
		 {
			SET_BIT(GPIOF->DIR,(Pin-38) );
		 }		 
  }
}



