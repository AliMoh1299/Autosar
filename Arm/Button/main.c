#include "dio.h"
#include "button.h"
#include "dio_cfg.h"

int main()
{
Dio_Init(GPIOF);
	STD_levelType X,Y;
while(1)	
{

X=Button_Read(Button0);
Y=Button_Read(Button1);
for(uint16 i =0 ; i<1000;i++){}
if(X==STD_low)
{
	Dio_WriteChannel(Dio_Channel_F1,STD_high);
}
else if(Y==STD_low)
{
	Dio_WriteChannel(Dio_Channel_F2,STD_high);
}
else if((X==STD_high)&&(Y==STD_high))
{	Dio_WriteChannel(Dio_Channel_F2,STD_low);
	Dio_WriteChannel(Dio_Channel_F1,STD_low);
}

}
return 0;
}