#include "STD_Types.h"

typedef struct
{
  volatile uint32  CR0;                               /*!< SSI Control 0                                                         */
  volatile uint32  CR1;                               /*!< SSI Control 1                                                         */
  volatile uint32  DR;                                /*!< SSI Data                                                              */
  volatile uint32  SR;                                /*!< SSI Status                                                            */
  volatile uint32  CPSR;                              /*!< SSI Clock Prescale                                                    */
  volatile uint32  IM;                                /*!< SSI Interrupt Mask                                                    */
  volatile uint32  RIS;                               /*!< SSI Raw Interrupt Status                                              */
  volatile uint32  MIS;                               /*!< SSI Masked Interrupt Status                                           */
  volatile  uint32  ICR;                               /*!< SSI Interrupt Clear                                                   */
  volatile uint32  DMACTL;                            /*!< SSI DMA Control                                                       */
  volatile uint32  CC; 
}Spi_ConfigType;

typedef uint16 Spi_DataBufferType;
typedef uint16 Spi_NumberOfDataType;
typedef uint8 Spi_ChannelType;

#define SSE    1
