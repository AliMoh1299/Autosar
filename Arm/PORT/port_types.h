#include "STD_Types.h"
#include "dio_types.h"
#include <TM4C123GH6PM.h>


typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;

typedef struct {

uint32  DIR;                               /*!< GPIO Direction                              */                                                  
uint32  AFSEL;                             /*!< GPIO Alternate Function Select              */                                             
uint32  PUR;                               /*!< GPIO Pull-Up Select                         */
uint32  PDR;                               /*!< GPIO Pull-Down Select                       */
uint32  DEN;                               /*!< GPIO Digital Enable                         */
uint32  LOCK;                              /*!< GPIO Lock                                   */
uint32  CR;                                /*!< GPIO Commit                                 */
uint32  AMSEL;                             /*!< GPIO Analog Mode Select                     */
uint32  PCTL;                              /*!< GPIO Port Control                           */



}Port_ConfigType;


typedef Dio_ChannelType Port_PinType;