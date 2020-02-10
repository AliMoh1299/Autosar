#include "dio.h"
#include "dio_cfg.h"
	
	

int main()
{
	
	Dio_Init(GPIOF);
	
	
while(1)

{
	
Dio_FlipChannel(Dio_Channel_F3);
	for(int i =0 ; i<1000000;i++){}
		Dio_FlipChannel(Dio_Channel_F1);
	for(int i =0 ; i<1000000;i++){}

}
	return 0;
}