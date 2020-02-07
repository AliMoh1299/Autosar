#ifndef DIO_HW_H_
#define DIO_HW_H_
#include "STD_Types.h"

#define GPIOA_BASE                      0x40004000UL
#define GPIOB_BASE                      0x40005000UL
#define GPIOC_BASE                      0x40006000UL
#define GPIOD_BASE                      0x40007000UL
#define GPIOE_BASE                      0x40024000UL
#define GPIOF_BASE                      0x40025000UL
// To Determine Reg. In Data Sheet
 
typedef struct {                                    /*!< GPIOA Structure                                                       */
   uint32  RESERVED[255];
   uint32  DATA;                              /*!< GPIO Data                                                             */
   uint32  DIR;                               /*!< GPIO Direction                                                        */
   uint32  IS;                                /*!< GPIO Interrupt Sense                                                  */
   uint32  IBE;                               /*!< GPIO Interrupt Both Edges                                             */
   uint32  IEV;                               /*!< GPIO Interrupt Event                                                  */
   uint32  IM;                                /*!< GPIO Interrupt Mask                                                   */
   uint32  RIS;                               /*!< GPIO Raw Interrupt Status                                             */
   uint32  MIS;                               /*!< GPIO Masked Interrupt Status                                          */
   uint32  ICR;                               /*!< GPIO Interrupt Clear                                                  */
   uint32  AFSEL;                             /*!< GPIO Alternate Function Select                                        */
   uint32  RESERVED1[55];
   uint32  DR2R;                              /*!< GPIO 2-mA Drive Select                                                */
   uint32  DR4R;                              /*!< GPIO 4-mA Drive Select                                                */
   uint32  DR8R;                              /*!< GPIO 8-mA Drive Select                                                */
   uint32  ODR;                               /*!< GPIO Open Drain Select                                                */
   uint32  PUR;                               /*!< GPIO Pull-Up Select                                                   */
   uint32  PDR;                               /*!< GPIO Pull-Down Select                                                 */
   uint32  SLR;                               /*!< GPIO Slew Rate Control Select                                         */
   uint32  DEN;                               /*!< GPIO Digital Enable                                                   */
   uint32  LOCK;                              /*!< GPIO Lock                                                             */
   uint32  CR;                                /*!< GPIO Commit                                                           */
   uint32  AMSEL;                             /*!< GPIO Analog Mode Select                                               */
   uint32  PCTL;                              /*!< GPIO Port Control                                                     */
   uint32  ADCCTL;                            /*!< GPIO ADC Control                                                      */
   uint32  DMACTL;                            /*!< GPIO DMA Control                                                      */
} GPIOA_Type;

#define GPIOA                           ((GPIOA_Type              *) GPIOA_BASE)
#define GPIOB                           ((GPIOA_Type              *) GPIOB_BASE)
#define GPIOC                           ((GPIOA_Type              *) GPIOC_BASE)
#define GPIOD                           ((GPIOA_Type              *) GPIOD_BASE)
#define GPIOE                           ((GPIOA_Type              *) GPIOE_BASE)
#define GPIOF                           ((GPIOA_Type              *) GPIOF_BASE)

#endif /* DIO_HW_H_ */