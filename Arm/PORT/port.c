#include "port.h"

#define UNLOCK_CODE 0x4C4F434B

#define DEN_ON   1
#define UNLOCKED 1
#define CR_ON    1

#define ADCCTL_ON  1
#define ADCCTL_OFF 0

#define AFSEL_ON  1
#define AFSEL_OFF 0

#define AMSEL_OFF 0 

#define PCTL_OFF  0

#define DIR_OUTPUT 1
#define DIR_INPUT 0

#define PINNUM   43

#define PORTA_START 0
#define PORTB_START 8
#define PORTC_START 16
#define PORTD_START 24
#define PORTE_START 32
#define PORTF_START 38

uint32 Delay;
 Port_ConfigType const Config[] = {
	/*----------------------------------------------------------------------------------------------------*/
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PA0
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PA1 
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PA2
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PA3
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PA4
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PA5
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PA6
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PA7
/*----------------------------------------------------------------------------------------------------*/
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PB0
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PB1
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PB2
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PB3
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PB4
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PB5
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PB6
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PB7
/*----------------------------------------------------------------------------------------------------*/
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PC0
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PC1
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PC2
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PC3
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PC4
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PC5
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PC6
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PC7
/*----------------------------------------------------------------------------------------------------*/
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PD0
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PD1
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PD2
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PD3
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PD4
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PD5
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PD6
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PD7
/*----------------------------------------------------------------------------------------------------*/
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PE0
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PE1
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PE2
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PE3
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PE4
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PE5
/*----------------------------------------------------------------------------------------------------*/
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PF0
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PF1
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PF2
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}, // PF3
{DEN_ON,UNLOCKED,CR_ON,AFSEL_OFF,AMSEL_OFF,PCTL_OFF,DIR_OUTPUT}  // PF4
/*----------------------------------------------------------------------------------------------------*/
};



void Port_Init(  Port_ConfigType* ConfigPtr )
{
	
	
	for (uint8 PinCounter=Dio_Channel_A0 ; PinCounter<PINNUM ; PinCounter++,ConfigPtr++)
{
	
 if( PinCounter >=0  && PinCounter <=7  )
	{
			 SET_BIT(SYSCTL->RCGC2,0);	
		if(ConfigPtr->DEN_R==DEN_ON)				{SET_BIT(GPIOA->DEN,(PinCounter-PORTA_START));}
		else																{CLR_BIT(GPIOA->DEN,(PinCounter-PORTA_START));}
				
	  if(ConfigPtr->LOCK_R==UNLOCKED)			{GPIOA->LOCK=UNLOCK_CODE;}
				
		if(ConfigPtr->CR_R==CR_ON)					{SET_BIT(GPIOA->CR,(PinCounter-PORTA_START));}
		else 																{CLR_BIT(GPIOA->CR,(PinCounter-PORTA_START));}
		
		
		if(ConfigPtr->AFSEL_R==AFSEL_OFF)		{CLR_BIT(GPIOA->AFSEL,(PinCounter-PORTA_START));}
		else                                {SET_BIT(GPIOA->AFSEL,(PinCounter-PORTA_START));}		
		
		if(ConfigPtr->AMSEL_R==AMSEL_OFF)		{CLR_BIT(GPIOA->AMSEL,(PinCounter-PORTA_START));}
		else                                {SET_BIT(GPIOA->AMSEL,(PinCounter-PORTA_START));}
				
		if(ConfigPtr->PCTL_R==PCTL_OFF)     {CLR_BIT(GPIOA->PCTL,(PinCounter-PORTA_START));}
		else                                {SET_BIT(GPIOA->PCTL,(PinCounter-PORTA_START));}

		if(ConfigPtr->DIR_R==DIR_INPUT)     {CLR_BIT(GPIOA->DIR,(PinCounter-PORTA_START));}
		else                                {SET_BIT(GPIOA->DIR,(PinCounter-PORTA_START));}		
	}	
	
	else if( PinCounter >=8  && PinCounter <=15  )
	{
			 			 SET_BIT(SYSCTL->RCGC2,1);	

		if(ConfigPtr->DEN_R==DEN_ON)				{SET_BIT(GPIOB->DEN,(PinCounter-PORTB_START));}
		else																{CLR_BIT(GPIOB->DEN,(PinCounter-PORTB_START));}
				
	  if(ConfigPtr->LOCK_R==UNLOCKED)			{GPIOB->LOCK=UNLOCK_CODE;}
				
		if(ConfigPtr->CR_R==CR_ON)					{SET_BIT(GPIOB->CR,(PinCounter-PORTB_START));}
		else 																{CLR_BIT(GPIOB->CR,(PinCounter-PORTB_START));}
		
		
		if(ConfigPtr->AFSEL_R==AFSEL_OFF)		{CLR_BIT(GPIOB->AFSEL,(PinCounter-PORTB_START));}
		else                                {SET_BIT(GPIOB->AFSEL,(PinCounter-PORTB_START));}		
		
		if(ConfigPtr->AMSEL_R==AMSEL_OFF)		{CLR_BIT(GPIOB->AMSEL,(PinCounter-PORTB_START));}
		else                                {SET_BIT(GPIOB->AMSEL,(PinCounter-PORTB_START));}
				
		if(ConfigPtr->PCTL_R==PCTL_OFF)     {CLR_BIT(GPIOB->PCTL,(PinCounter-PORTB_START));}
		else                                {SET_BIT(GPIOB->PCTL,(PinCounter-PORTB_START));}

		if(ConfigPtr->DIR_R==DIR_INPUT)     {CLR_BIT(GPIOB->DIR,(PinCounter-PORTB_START));}
		else                                {SET_BIT(GPIOB->DIR,(PinCounter-PORTB_START));}			
	}  
	
	//else if( PinCounter >=16  && PinCounter <=23  )
	
	/*		{ 			 SET_BIT(SYSCTL->RCGC2,2);	

		if(ConfigPtr->DEN_R==DEN_ON)				{SET_BIT(GPIOC->DEN,(PinCounter-PORTC_START));}
		else																{CLR_BIT(GPIOC->DEN,(PinCounter-PORTC_START));}
				
	  if(ConfigPtr->LOCK_R==UNLOCKED)			{GPIOC->LOCK=UNLOCK_CODE;}
				
		if(ConfigPtr->CR_R==CR_ON)					{SET_BIT(GPIOC->CR,(PinCounter-PORTC_START));}
		else 																{CLR_BIT(GPIOC->CR,(PinCounter-PORTC_START));}
		
		
		if(ConfigPtr->AFSEL_R==AFSEL_OFF)		{CLR_BIT(GPIOC->AFSEL,(PinCounter-PORTC_START));}
		else                                {SET_BIT(GPIOC->AFSEL,(PinCounter-PORTC_START));}		
		
		if(ConfigPtr->AMSEL_R==AMSEL_OFF)		{CLR_BIT(GPIOC->AMSEL,(PinCounter-PORTC_START));}
		else                                {SET_BIT(GPIOC->AMSEL,(PinCounter-PORTC_START));}
				
		if(ConfigPtr->PCTL_R==PCTL_OFF)     {CLR_BIT(GPIOC->PCTL,(PinCounter-PORTC_START));}
		else                                {SET_BIT(GPIOC->PCTL,(PinCounter-PORTC_START));}
		if(ConfigPtr->DIR_R==DIR_INPUT)     {CLR_BIT(GPIOC->DIR,(PinCounter-PORTC_START));}
		else                                {SET_BIT(GPIOC->DIR,(PinCounter-PORTC_START));}					
	}	
	*/
	else if( PinCounter >=24  && PinCounter <=31  )
	{
			 			 SET_BIT(SYSCTL->RCGC2,3);	

		if(ConfigPtr->DEN_R==DEN_ON)				{SET_BIT(GPIOD->DEN,(PinCounter-PORTD_START));}
		else																{CLR_BIT(GPIOD->DEN,(PinCounter-PORTD_START));}
				
	  if(ConfigPtr->LOCK_R==UNLOCKED)			{GPIOD->LOCK=UNLOCK_CODE;}
				
		if(ConfigPtr->CR_R==CR_ON)					{SET_BIT(GPIOD->CR,(PinCounter-PORTD_START));}
		else 																{CLR_BIT(GPIOD->CR,(PinCounter-PORTD_START));}
		
		
		if(ConfigPtr->AFSEL_R==AFSEL_OFF)		{CLR_BIT(GPIOD->AFSEL,(PinCounter-PORTD_START));}
		else                                {SET_BIT(GPIOD->AFSEL,(PinCounter-PORTD_START));}		
		
		if(ConfigPtr->AMSEL_R==AMSEL_OFF)		{CLR_BIT(GPIOD->AMSEL,(PinCounter-PORTD_START));}
		else                                {SET_BIT(GPIOD->AMSEL,(PinCounter-PORTD_START));}
				
		if(ConfigPtr->PCTL_R==PCTL_OFF)     {CLR_BIT(GPIOD->PCTL,(PinCounter-PORTD_START));}
		else                                {SET_BIT(GPIOD->PCTL,(PinCounter-PORTD_START));}

		if(ConfigPtr->DIR_R==DIR_INPUT)     {CLR_BIT(GPIOD->DIR,(PinCounter-PORTD_START));}
		else                                {SET_BIT(GPIOD->DIR,(PinCounter-PORTD_START));}	
		
	}	
	
	
	else if( PinCounter >=32  && PinCounter <=37  )
	{
			 			 SET_BIT(SYSCTL->RCGC2,4);	

		if(ConfigPtr->DEN_R==DEN_ON)				{SET_BIT(GPIOE->DEN,(PinCounter-PORTE_START));}
		else																{CLR_BIT(GPIOE->DEN,(PinCounter-PORTE_START));}
				
	  if(ConfigPtr->LOCK_R==UNLOCKED)			{GPIOE->LOCK=UNLOCK_CODE;}
				
		if(ConfigPtr->CR_R==CR_ON)					{SET_BIT(GPIOE->CR,(PinCounter-PORTE_START));}
		else 																{CLR_BIT(GPIOE->CR,(PinCounter-PORTE_START));}
		
		
		if(ConfigPtr->AFSEL_R==AFSEL_OFF)		{CLR_BIT(GPIOE->AFSEL,(PinCounter-PORTE_START));}
		else                                {SET_BIT(GPIOE->AFSEL,(PinCounter-PORTE_START));}		
		
		if(ConfigPtr->AMSEL_R==AMSEL_OFF)		{CLR_BIT(GPIOE->AMSEL,(PinCounter-PORTE_START));}
		else                                {SET_BIT(GPIOE->AMSEL,(PinCounter-PORTE_START));}
				
		if(ConfigPtr->PCTL_R==PCTL_OFF)     {CLR_BIT(GPIOE->PCTL,(PinCounter-PORTE_START));}
		else                                {SET_BIT(GPIOE->PCTL,(PinCounter-PORTE_START));}

		if(ConfigPtr->DIR_R==DIR_INPUT)     {CLR_BIT(GPIOE->DIR,(PinCounter-PORTE_START));}
		else                                {SET_BIT(GPIOE->DIR,(PinCounter-PORTE_START));}	
		
	}
	
  else if( PinCounter >=38  && PinCounter <=43  )
	{
			 			 SET_BIT(SYSCTL->RCGC2,5);	

		if(ConfigPtr->DEN_R==DEN_ON)				{SET_BIT(GPIOF->DEN,(PinCounter-PORTF_START));}
		else																{CLR_BIT(GPIOF->DEN,(PinCounter-PORTF_START));}
				
	  if(ConfigPtr->LOCK_R==UNLOCKED)			{GPIOF->LOCK=UNLOCK_CODE;}
				
		if(ConfigPtr->CR_R==CR_ON)					{SET_BIT(GPIOF->CR,(PinCounter-PORTF_START));}
		else 																{CLR_BIT(GPIOF->CR,(PinCounter-PORTF_START));}
		
		
		if(ConfigPtr->AFSEL_R==AFSEL_OFF)		{CLR_BIT(GPIOF->AFSEL,(PinCounter-PORTF_START));}
		else                                {SET_BIT(GPIOF->AFSEL,(PinCounter-PORTF_START));}		
		
		if(ConfigPtr->AMSEL_R==AMSEL_OFF)		{CLR_BIT(GPIOF->AMSEL,(PinCounter-PORTF_START));}
		else                                {SET_BIT(GPIOF->AMSEL,(PinCounter-PORTF_START));}
				
		if(ConfigPtr->PCTL_R==PCTL_OFF)     {CLR_BIT(GPIOF->PCTL,(PinCounter-PORTF_START));}
		else                                {SET_BIT(GPIOF->PCTL,(PinCounter-PORTF_START));}
		
		if(ConfigPtr->DIR_R==DIR_INPUT)     {CLR_BIT(GPIOF->DIR,(PinCounter-PORTF_START));}
		else                                {SET_BIT(GPIOF->DIR,(PinCounter-PORTF_START));}					
	}
	
 }	
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