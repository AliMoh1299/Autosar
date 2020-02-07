#include "button.h"

STD_levelType Button_Read(uint8 Button_Num)
 {
     STD_levelType Button_Level=0;
	 Button_Level=Dio_ReadChannel(Button_Num);
     return Button_Level;
  }
