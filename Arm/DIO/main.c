#include "dio.h"
#include "dio_cfg.h"
	
	

int main()
{
	
	Dio_Init(GPIOF);
	
	
while(1)

{
	Dio_WriteChannel(Dio_Channel_F2,STD_high);
	for(int i =0 ; i<100000;i++){}
	Dio_WriteChannel(Dio_Channel_F2,STD_low);
	for(int i =0 ; i<100000;i++){}


}
	return 0;
}