#include "dio.h"
#include "dio_types.h"
#include "button.h"

int main()
{  
	STD_levelType x,y,z ;
	Dio_init();
	while(1)
	{
		x=Button_Read(Button0);
			Dio_WriteChannel(Dio_Channel_D5,x);
		y=Button_Read(Button1);
			Dio_WriteChannel(Dio_Channel_D6,y);
		z=Button_Read(Button2);
			Dio_WriteChannel(Dio_Channel_D7,z);
	}
	return 0;
}