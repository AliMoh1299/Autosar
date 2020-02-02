#include "button.h"

STD_levelType Button_Read(uint8 Button_Num)
 {
   STD_levelType Button_Level=0;
	switch(Button_Num)
	{
	  case  Button0:
	  Button_Level=Dio_ReadChannel(Button0);
	  break;
	
	  case Button1:	
	  Button_Level=Dio_ReadChannel(Button1);
	  break;
	  
	  case Button2:
	  Button_Level=Dio_ReadChannel(Button2);
	  break;
    }

     return Button_Level;
  }
