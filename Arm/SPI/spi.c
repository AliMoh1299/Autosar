#include "TM4C123GH6PM.h"
#include "spi_types.h"
void Spi_InitAsMaster( void )
{
	SYSCTL->RCGCSSI|=(1<<0);                                          /*	 SSI0 Enable       */
	SYSCTL->RCGCGPIO|=(1<<0);                                        /*	  GPIOA Enable      */ 
	GPIOA->AFSEL|=(1<<2)|(1<<3)|(1<<4)|(1<<5);                      /*	 ALTER. FUN        */
	GPIOA->PCTL|=(1<<2)|(1<<3)|(1<<4)|(1<<5);                      /*	  P.Contro          */
	GPIOA->DEN|=(1<<2)|(1<<3)|(1<<4)|(1<<5);                      /*	 D.Enable          */
	GPIOA->PUR|=(1<<2)|(1<<3)|(1<<4)|(1<<5);                     /*	  Pull UP           */
 	GPIOA->DIR|=(1<<3);                                         /*   FSS DIR           */
	SSI0->CR1&=~(1<<SSE);                                      /*	  Disable  SSE      */                  
	SSI0->CR1&=~(1<<2);  														 		      /*	 Work As Master    */
	SSI0->CC=0x0;     															         /*	  SYSTEM CLOCK      */
	SSI0->CPSR=4;   													 			        /*	 PRESCALER         */
	SSI0->CR0&=0x00FF; 																     /*	  SCR               */
	SSI0->CR0&=(1<<7);    															  /*	 SPH               */
	SSI0->CR0&=(1<<6); 																   /*	  SPO               */
  SSI0->CR0&=(1<<4);                                  /*	 SPI ON            */
	SSI0->CR0&=(1<<5);                                 /*	  SPI ON            */
	SSI0->CR0|=0x7;                                   /*	 Data Size 8       */
	SSI0->CR1|=(1<<0);	                             /*  LOOP BACK          */
	SSI0->CR1|=(1<<SSE);                            /*  Enable  SSE        */ 
	//  END OF TRANS. & LOOP BACK   IN CR1  
}

void Spi_WriteIB(  Spi_DataBufferType* DataBufferPtr )
{
GPIOA->DATA|=(1<<3);  //Make FSS Pulse
for(int i = 0 ; i<60 ; i++){}		
GPIOA->DATA&=~(1<<3);	 //Make FSS Pulse
SSI0->DR=*DataBufferPtr;
while(!(SSI0->SR & (1<<0))){}	
GPIOA->DATA|=(1<<3); //Make FSS Pulse	
for(int i = 0 ; i<60 ; i++){}			
GPIOA->DATA&=~(1<<3);	//Make FSS Pulse	
}