#include "spi.h"
/* N3ml GPIO5 As Output 34an Nt7akm Fl Signal el Hnb3tha */
void Spi_Init(  )
{
	SYSCTL->RCGCSSI=(1<<2);                        /*  To Enable Clock Gate MOD 2               */
	SYSCTL->RCGCGPIO=(1<<1);                       /*  To Enable Clock Gate PORTB               */	
	GPIOB->AFSEL|=(1<<4)|(1<<6)|(1<<7);            /* GPIOB ALTER. FUNC.                        */
	GPIOB->AFSEL &=~(1<<5);
	GPIOB->DIR|=(1<<5);
	GPIOB->PCTL|=(2<<16)|(2<<20)|(2<<24)|(2<<28);  /* SSI Signal IN PORTB                       */
	GPIOB->DEN|=(1<<4)|(1<<5)|(1<<6)|(1<<7);       /* Dig. Enable                               */
	CLR_BIT(SSI2->CR1,SSE);                        /*  Turn Off Synchronous Serial Port Enable  */
	SSI2->CR1=0x1;                                 /*  Confg. As Master                         */
	SSI2->CC=0x0000;                               /*  System clock                             */
	SSI2->CPSR=4;                                  /*  Clock Prescale Divisor                   */
  SSI2->CR0=(0x07<<0);                            /*  8-bit data First                        */
	SET_BIT(SSI2->CR1,SSE);                        /*  Turn ON Synchronous Serial Port Enable   */
}

void  Spi_WriteIB(  Spi_DataBufferType* DataBufferPtr )
{

SSI2->DR= *DataBufferPtr;
while((SSI2->SR & (1<<0))==0);

}


uint8 Spi_ReadIB()
{
	uint8 DataBufferPointer;
while((SSI2->SR & (1<<2))==0);
DataBufferPointer=SSI2->DR;
	return DataBufferPointer;
	
}