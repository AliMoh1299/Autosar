/*
 * External_EEPROM.h
 *
 * Created: 3/12/2014 12:06:14 PM
 *  Author: Mohamed Tarek
 */ 


#ifndef EXTERNAL_EEPROM_H_
#define EXTERNAL_EEPROM_H_

#define ERROR 0
#define SUCCESS 1

#include "I2C.h"

void EEPROM_Init(void);
unsigned char EEPROM_Write_Byte(unsigned short u16addr, unsigned char u8data);
unsigned char EEPROM_Read_Byte(unsigned short u16addr, unsigned char *u8data);
 
#endif /* EXTERNAL_EEPROM_H_ */