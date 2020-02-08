#include "dio.h"

void PortF_Init(void){ 
	
	volatile unsigned long delay;

  SYSCTL->RCGC2 = 0x00000020;     // 1) activate clock for Port F

  delay = SYSCTL->RCGC2;           // allow time for clock to start

  GPIOF -> LOCK = 0x4C4F434B;   // 2) unlock GPIO Port F

  GPIOF ->CR = 0x1F;           // allow changes to PF4-0

  // only PF0 needs to be unlocked, other bits can't be locked

  GPIOF->AMSEL = 0x00;        // 3) disable analog on PF

  GPIOF->PCTL = 0x00000000;   // 4) PCTL GPIO on PF4-0

  GPIOF->DIR = 0x0E;          // 5) PF4,PF0 in, PF3-1 out

  GPIOF->AFSEL = 0x00;        // 6) disable alt funct on PF7-0

  GPIOF->PUR = 0x11;          // enable pull-up on PF0 and PF4

  GPIOF->DEN = 0x1F;  
}

int main()
{
	PortF_Init();
	
while(1)
{

Dio_FlipChannel(Dio_Channel_F2);
	for(int i =0 ; i<1000000;i++){}
		Dio_FlipChannel(Dio_Channel_F1);
	for(int i =0 ; i<1000000;i++){}
}
	return 0;
}