#include "port.h"

uint8 PINNUM=42;

void Port_Init(GPIOA_Type *GPIO,Port_PinDirectionType Direction)
{
GPIO->LOCK=0x4C4F434B;
GPIO->AFSEL = 0x00;
GPIO->PCTL  = 0x00;
GPIO->AMSEL = 0x00;
GPIO->DEN=0xFF;
GPIO->CR=0xFF;	

	
	if(GPIO==GPIOA)
	{
     SET_BIT(SYSCTL->RCGC2,0);
		if(Direction == PORT_PIN_OUT)
		{
		GPIO->DIR=0xFF;
		}
		else{		
			GPIO->DIR=0x00;		
		}		
	}
else if(GPIO==GPIOB)
{		SET_BIT(SYSCTL->RCGC2,1);
		if(Direction == PORT_PIN_OUT)
		{
		GPIO->DIR=0xFF;
		}
		else{		
			GPIO->DIR=0x00;		
		}
}
else if(GPIO==GPIOC)
{		SET_BIT(SYSCTL->RCGC2,2);
		if(Direction == PORT_PIN_OUT)
		{
		GPIO->DIR=0xFF;
		}
		else{		
			GPIO->DIR=0x00;		
		}
}
else if(GPIO==GPIOD)
{		SET_BIT(SYSCTL->RCGC2,3);
		if(Direction == PORT_PIN_OUT)
		{
		GPIO->DIR=0xFF;
		}
		else{		
			GPIO->DIR=0x00;		
		}

}
	else if(GPIO==GPIOE)
	{
SET_BIT(SYSCTL->RCGC2,4);
		if(Direction == PORT_PIN_OUT)
		{
		GPIO->DIR=0x3F;
		}	
		else{		
			GPIO->DIR=0x00;		
		}		
	}
	else if(GPIO==GPIOF)
	{	
		SET_BIT(SYSCTL->RCGC2,5);
		if(Direction == PORT_PIN_OUT)
		{
		GPIO->DIR=0x1F;		
		}	
		else{		
			GPIO->DIR=0x00;		
		}
	}



}




void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
{
	for (uint8 i =Dio_Channel_A0; i<PINNUM ;i++)
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

		}


