#include "dio.h"
//#include "dio_hw.h"
#include "dio_types.h"
#include "STD_Types.h"
#include "bit_math.h"


void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level ){
	switch (PortId)
	{
		case Dio_Port_A :
		GPIOA->DATA=Level;
		break;
		
		case Dio_Port_B :
		GPIOB->DATA=Level;
		break;
		
		case Dio_Port_C :
		GPIOC->DATA=Level;
		break;
		
		case Dio_Port_D :
		GPIOD->DATA=Level;
		break;
		
    case Dio_Port_E :
		GPIOE->DATA=Level;
		break;

    case Dio_Port_F :
		GPIOF->DATA=Level;
		break;		
		
	}
}


void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
	uint32 channelpos;

	 channelpos =ChannelId%8;
   if (ChannelId >=0 && ChannelId <=7)
	 {
		if(Level == STD_low)
		{
			CLR_BIT(GPIOA->DATA,channelpos);
		}
	
		else
		 {
			SET_BIT(GPIOA->DATA,channelpos );
		 }
	 }
//----------------------------------------------------------------------
   else if (ChannelId >=8 && ChannelId <=15)
	 {
		if(Level == STD_low)
		{
			CLR_BIT(GPIOB->DATA,channelpos);
		}
	
		else
		 {
			SET_BIT(GPIOB->DATA,channelpos );
		 }
	 }
//----------------------------------------------------------------------
   else if (ChannelId >=16 && ChannelId <=23)
	 {
		if(Level == STD_low)
		{
			CLR_BIT(GPIOC->DATA,channelpos);
		}

		else
		 {
			SET_BIT(GPIOC->DATA,channelpos );
		 }
	 }
//----------------------------------------------------------------------
   else if (ChannelId >=24 && ChannelId <=31)
	 {
		if(Level == STD_low)
		{
			CLR_BIT(GPIOD->DATA,channelpos);
		}
	
		else
		 {
			SET_BIT(GPIOD->DATA,channelpos );
		 }
	 }
//----------------------------------------------------------------------
//----------------------------------------------------------------------
   else if (ChannelId >=32 && ChannelId <=37)
	 {
		if(Level == STD_low)
		{
			CLR_BIT(GPIOE->DATA,(ChannelId-32));
		}
	
		else
		 {
			SET_BIT(GPIOE->DATA,(ChannelId-32));
		 }
	 }
//----------------------------------------------------------------------

  else if (ChannelId >=38 && ChannelId <=43)
		 
	 {
		if(Level == STD_low)
		{
			CLR_BIT(GPIOF->DATA,(ChannelId-38));
		}
	
		else
		 {
			SET_BIT(GPIOF->DATA,(ChannelId-38) );
		 }		 
  }
}


Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
{
Dio_PortLevelType Data ;
	switch(PortId)
	{
		case Dio_Port_A:
		Data=GPIOA->DATA;
		break;
		
		case Dio_Port_B:
		Data=GPIOB->DATA;
		break;
		case Dio_Port_C:
		Data=GPIOC->DATA;
		break;
		
		case Dio_Port_D:
		Data=GPIOD->DATA;
		break;
		
		case Dio_Port_E:
		Data=GPIOE->DATA;
		break;	
    
		case Dio_Port_F:
		Data=GPIOF->DATA;
		break;		
		
	}
	return Data;
	
}

Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
	uint8 channelpos;
	Dio_LevelType Level;

//---------------------------------------------------------------------- Port A	
	 channelpos =ChannelId%8;
   if (ChannelId >=0 && ChannelId <=7)
	 {
		 
			Level=GET_BIT(GPIOA->DATA,channelpos);
		  return Level ;

	}

//---------------------------------------------------------------------- Port B
   if (ChannelId >=8 && ChannelId <=15)
	 {
		 
			Level=GET_BIT(GPIOB->DATA,channelpos);
		  return Level ;

	 }
 
//---------------------------------------------------------------------- Port C
   if (ChannelId >=16 && ChannelId <=23)
	 {
		 
			Level=GET_BIT(GPIOC->DATA,channelpos);
		  return Level ;

	 }

//---------------------------------------------------------------------- Port D
   if (ChannelId >=24 && ChannelId <=31)
	 {
		 
			Level=GET_BIT(GPIOD->DATA,channelpos);
		  return Level ;

	 }

 

//----------------------------------------------------------------------Port E 
   else if (ChannelId >=32 && ChannelId <=37)
	 {
		 
		 Level=GET_BIT(GPIOE->DATA,(ChannelId-32));
		 return Level ;

	 }

//----------------------------------------------------------------------Port F

  else if (ChannelId >=38 && ChannelId <=43)
		 
	 {
		 
			Level=GET_BIT(GPIOF->DATA,(ChannelId-38));
		  return Level ;

	 }
		 
 }



Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId)
{
uint8 channelpos;

	 channelpos =ChannelId%8;
//----------------------------------------------------------------------Port A
   if (ChannelId >=0 && ChannelId <=7)
	 {
		
		 TOGGLE_BIT(GPIOA->DATA,channelpos);
		 return GET_BIT(GPIOA->DATA,channelpos);

	 }

//----------------------------------------------------------------------Port B
   if (ChannelId >=8 && ChannelId <=15)
	 {
		
		TOGGLE_BIT(GPIOB->DATA,channelpos);
		return GET_BIT(GPIOB->DATA,channelpos);
	
	 }

//---------------------------------------------------------------------- Port C
   if (ChannelId >=16 && ChannelId <=23)
	 {
		
		TOGGLE_BIT(GPIOC->DATA,channelpos);
		return GET_BIT(GPIOC->DATA,channelpos);

	 }

//---------------------------------------------------------------------- Port D
   if (ChannelId >=24 && ChannelId <=31)
	 {
		 
		 TOGGLE_BIT(GPIOD->DATA,channelpos);
		 return GET_BIT(GPIOD->DATA,channelpos);

	 }

 
//----------------------------------------------------------------------
//----------------------------------------------------------------------Port E

   if (ChannelId >=32 && ChannelId <=37)
	 {
		 
	   TOGGLE_BIT(GPIOE->DATA,(ChannelId-32));
		 return GET_BIT(GPIOE->DATA,(ChannelId-32));

	 }

//---------------------------------------------------------------------- Port F

   if (ChannelId >=38 && ChannelId <=43)
		 
	 {
		 
		TOGGLE_BIT(GPIOF->DATA,(ChannelId-38));
		return GET_BIT(GPIOF->DATA,(ChannelId-38)); 
		 
	 }
		 
  }

 