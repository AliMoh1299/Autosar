#include <avr/io.h>
#include "EEPROM.h"
#include <util/delay.h>

int main(void)
{
 uint8 val = 0;
	DDRD  = 0xFF;
	    Eep_Init();
		Eep_Write(1,0xE0,1);
		_delay_ms(10);
		Eep_Read(1,&val ,1);
		_delay_ms(10);
	while(1)
	{
		PORTD=val;
	}
	return 0;
}