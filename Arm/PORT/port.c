#include "port.h"

#define UNLOCKED 0x4C4F434B
#define PINNUM   42
#define PNUM   5
#define OUTPUT 255
#define INPUT  0
#define ON     1
#define OFF    0



//----------------------------------------------------------------------
 const Port_ConfigType PortCfg_All []={
//AFSEL,PCTL,AMSEL,DEN,CR,LOCK,DIR,CLOCK		 
{0,0,0,255,255,UNLOCKED,OUTPUT,OFF},	//GPIOA
{0,0,0,255,255,UNLOCKED,OUTPUT,OFF},	//GPIOB
{0,0,0,255,255,UNLOCKED,OUTPUT,OFF},	//GPIOC
{0,0,0,255,255,UNLOCKED,OUTPUT,OFF}, //GPIOD
{0,0,0,255,255,UNLOCKED,OUTPUT,OFF}, //GPIOE
{0,0,0,255,255,UNLOCKED,OUTPUT,ON }, //GPIOF
	// Da Kda Linktime Confg ?
};

void Port_Init( const Port_ConfigType* ConfigPtr )
{
for (uint8 i=0;i<PNUM;i++)
{
	if (ConfigPtr[i].CLOCK==ON)
 {
	switch(i)
	{
		case 0://PORTA
     SET_BIT(SYSCTL->RCGC2,0);	
		break;
		
		case 1://PORTB
     SET_BIT(SYSCTL->RCGC2,1);	
		break;		
		
		case 2://PORTC
     SET_BIT(SYSCTL->RCGC2,2);	
		break;		
		
		case 3://PORTD
     SET_BIT(SYSCTL->RCGC2,3);	
		break;		
		
		case 4://PORTE
     SET_BIT(SYSCTL->RCGC2,4);	
		break;		
		
		case 5://PORTF
     SET_BIT(SYSCTL->RCGC2,5);	
		break;		
		
		
	}
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


