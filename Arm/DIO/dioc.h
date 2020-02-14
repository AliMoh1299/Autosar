#include "dio.h"
#include "dio_types.h"
#include "STD_Types.h"
#include "bit_math.h"


void Dio_WritePort( Dio_PortType *PortId, Dio_PortLevelType Level )
{	
	if(PortId==Dio_Port_A)
	{
		Dio_Port_A->DATA=Level;
	}	
	else if(PortId==Dio_Port_B)
	{
		Dio_Port_B->DATA=Level;
	}
	else if(PortId==Dio_Port_C)
	{
		Dio_Port_C->DATA=Level;
	}
	else if(PortId==Dio_Port_D)
	{
		Dio_Port_D->DATA=Level;
	}
	else if(PortId==Dio_Port_E)
	{
		Dio_Port_E->DATA=Level;
	}
	else if(PortId==Dio_Port_F)
	{
		Dio_Port_F->DATA=Level;
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
			CLR_BIT(Dio_Port_A->DATA,channelpos);
		}
	
		else
		 {
			SET_BIT(Dio_Port_A->DATA,channelpos );
		 }
	 }
//----------------------------------------------------------------------
   else if (ChannelId >=8 && ChannelId <=15)
	 {
		if(Level == STD_low)
		{
			CLR_BIT(Dio_Port_B->DATA,channelpos);
		}
	
		else
		 {
			SET_BIT(Dio_Port_B->DATA,channelpos );
		 }
	 }
//----------------------------------------------------------------------
   else if (ChannelId >=16 && ChannelId <=23)
	 {
		if(Level == STD_low)
		{
			CLR_BIT(Dio_Port_C->DATA,channelpos);
		}

		else
		 {
			SET_BIT(Dio_Port_C->DATA,channelpos );
		 }
	 }
//----------------------------------------------------------------------
   else if (ChannelId >=24 && ChannelId <=31)
	 {
		if(Level == STD_low)
		{
			CLR_BIT(Dio_Port_D->DATA,channelpos);
		}
	
		else
		 {
			SET_BIT(Dio_Port_D->DATA,channelpos );
		 }
	 }
//----------------------------------------------------------------------
//----------------------------------------------------------------------
   else if (ChannelId >=32 && ChannelId <=37)
	 {
		if(Level == STD_low)
		{
			CLR_BIT(Dio_Port_E->DATA,(ChannelId-32));
		}
	
		else
		 {
			SET_BIT(Dio_Port_E->DATA,(ChannelId-32));
		 }
	 }
//----------------------------------------------------------------------

  else if (ChannelId >=38 && ChannelId <=43)
		 
	 {
		if(Level == STD_low)
		{
			CLR_BIT(Dio_Port_F->DATA,(ChannelId-38));
		}
	
		else
		 {
			SET_BIT(Dio_Port_F->DATA,(ChannelId-38) );
		 }		 
  }
}


Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
{
	
Dio_PortLevelType Data ;

if(PortId==Dio_Port_A)	
{
		Data=Dio_Port_A->DATA;
}
		
else if(PortId==Dio_Port_B)	
{
		Data=Dio_Port_B->DATA;
}

else if(PortId==Dio_Port_C)	
{
		Data=Dio_Port_C->DATA;
}
else if(PortId==Dio_Port_D)	
{
		Data=Dio_Port_D->DATA;
}
else if(PortId==Dio_Port_E)	
{
		Data=Dio_Port_E->DATA;
}
else if(PortId==Dio_Port_F)	
{
		Data=Dio_Port_F->DATA;
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
		 
			Level=GET_BIT(Dio_Port_A->DATA,channelpos);
		  return Level ;

	}

//---------------------------------------------------------------------- Port B
   if (ChannelId >=8 && ChannelId <=15)
	 {
		 
			Level=GET_BIT(Dio_Port_B->DATA,channelpos);
		  return Level ;

	 }
 
//---------------------------------------------------------------------- Port C
   if (ChannelId >=16 && ChannelId <=23)
	 {
		 
			Level=GET_BIT(Dio_Port_C->DATA,channelpos);
		  return Level ;

	 }

//---------------------------------------------------------------------- Port D
   if (ChannelId >=24 && ChannelId <=31)
	 {
		 
			Level=GET_BIT(Dio_Port_D->DATA,channelpos);
		  return Level ;

	 }

 

//----------------------------------------------------------------------Port E 
   else if (ChannelId >=32 && ChannelId <=37)
	 {
		 
		 Level=GET_BIT(Dio_Port_E->DATA,(ChannelId-32));
		 return Level ;

	 }

//----------------------------------------------------------------------Port F

  else if (ChannelId >=38 && ChannelId <=43)
		 
	 {
		 
			Level=GET_BIT(Dio_Port_F->DATA,(ChannelId-38));
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
		
		 TOGGLE_BIT(Dio_Port_A->DATA,channelpos);
		 return GET_BIT(Dio_Port_A->DATA,channelpos);

	 }

//----------------------------------------------------------------------Port B
   if (ChannelId >=8 && ChannelId <=15)
	 {
		
		TOGGLE_BIT(Dio_Port_B->DATA,channelpos);
		return GET_BIT(Dio_Port_B->DATA,channelpos);
	
	 }

//---------------------------------------------------------------------- Port C
   if (ChannelId >=16 && ChannelId <=23)
	 {
		
		TOGGLE_BIT(Dio_Port_C->DATA,channelpos);
		return GET_BIT(Dio_Port_C->DATA,channelpos);

	 }

//---------------------------------------------------------------------- Port D
  
	 if (ChannelId >=24 && ChannelId <=31)
	 {
		 
		 TOGGLE_BIT(Dio_Port_D->DATA,channelpos);
		 return GET_BIT(Dio_Port_D->DATA,channelpos);

	 }

//----------------------------------------------------------------------Port E

   if (ChannelId >=32 && ChannelId <=37)
	 {
		 
	   TOGGLE_BIT(Dio_Port_E->DATA,(ChannelId-32));
		 return GET_BIT(Dio_Port_E->DATA,(ChannelId-32));

	 }

//---------------------------------------------------------------------- Port F

   if (ChannelId >=38 && ChannelId <=43)
		 
	 {
		 
		TOGGLE_BIT(Dio_Port_F->DATA,(ChannelId-38));
		return GET_BIT(Dio_Port_F->DATA,(ChannelId-38)); 
		 
	 }
		 
  }

 