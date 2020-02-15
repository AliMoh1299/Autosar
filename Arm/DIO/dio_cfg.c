#include "dio_cfg.h"

void Dio_Init(GPIOA_Type *GPIO)
{
	if(GPIO==GPIOF)
	{
	 SYSCTL->RCGC2=0x20;
	 volatile uint32 delay = SYSCTL->RCGC2;
	}

GPIO->LOCK  = 0x4C4F434B;
GPIO->CR    = 0x1F;
GPIO->AMSEL = 0x00;
GPIO->PCTL  = 0x00000000;
GPIO->DIR   = 0x0E;    
GPIO->AFSEL = 0x00; 
GPIO->PUR   = 0x11;
GPIO->DEN   = 0x1F;
	
}
