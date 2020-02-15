/*
 * External_EEPROM_I2C.c
 *
 * Created: 3/12/2014 12:05:19 PM
 *  Author: Mohamed Tarek
 */
 

#include"External_EEPROM.h"

int main(void)
{
	uint8 val = 0;
	
	DDRD  = 0xFF;
	PORTD = 0x00;

	// Init EEPROM
	EEPROM_Init();

	EEPROM_Write_Byte(0x0311, 0x0F); // Write 0xFF in the external EEPROM
	_delay_ms(10);
	EEPROM_Read_Byte(0x0311, &val); // Read 0xFF from the external EEPROM
	while(1)
	{
		PORTD = val; // out the read value from the external EEPROM
	}
	return 0;
}