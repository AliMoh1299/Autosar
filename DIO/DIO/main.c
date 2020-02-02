#include "dio.h"
#include "STD_Types.h"
#include "dio_cfg.h"

int main()
{
	Dio_init();
	uint8 X;
		while(1)
	{ 
		    X=Dio_ReadChannel( Dio_Channel_D0);
		if(X==STD_high)
		{
			Dio_WriteChannel(Dio_Channel_D6,STD_high);
		}
		else
			Dio_WriteChannel(Dio_Channel_D6,STD_low);
	}	
	return 0 ;
}
