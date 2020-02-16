#include "EEPROM.h"


void Eep_Init( /*const Eep_ConfigType* ConfigPtr*/void )
{
	TWI_Init(FastMode,0,0,1);
}



Std_ReturnType Eep_Write( Eep_AddressType EepromAddress, const uint8* DataBufferPtr, Eep_LengthType Length )
{
	    TWI_Start();
	    if (TWI_GetStatus() != TW_START)
	    return E_NOT_OK;
	    
	    //write the device address and so we need to get A8 A9 A10 address bits and R/W=0 (write)
	    TWI_Write((uint8)(0xA0 | ((EepromAddress & 0x0700)>>7)));
	    if (TWI_GetStatus() != TW_MT_SLA_W_ACK)
	    return E_NOT_OK;
	    
	    //send the required location address
	    TWI_Write((uint8)(EepromAddress));
	    if (TWI_GetStatus() != TW_MT_DATA_ACK)
	    return E_NOT_OK;
	    
	    //write byte to eeprom
		
			while( Length!=0)
			{
	      TWI_Write(*DataBufferPtr);
		  if (TWI_GetStatus() != TW_MT_DATA_ACK)
		  return E_NOT_OK;
		  
				_delay_ms(10);
				++EepromAddress;
				--Length;
			}
		
	
	    if (TWI_GetStatus() != TW_MT_DATA_ACK)
	    return E_NOT_OK;
	    
	    TWI_Stop();
	    
	    return E_OK;
	
}


Std_ReturnType Eep_Read( Eep_AddressType EepromAddress, uint8* DataBufferPtr, Eep_LengthType Length )
{
	 TWI_Start();
	 if (TWI_GetStatus() != TW_START)
	 return E_NOT_OK;
	 
	 //write the device address and so we need to get A8 A9 A10 address bits and R/W=0 (write)
	 TWI_Write((uint8)((0xA0) | ((EepromAddress & 0x0700)>>7)));
	 if (TWI_GetStatus() != TW_MT_SLA_W_ACK)
	 return E_NOT_OK;
	 
	 //send the required location address
	 TWI_Write((uint8)(EepromAddress));
	 if (TWI_GetStatus() != TW_MT_DATA_ACK)
	 return E_NOT_OK;
	 
	 //send a repeated start
	 TWI_Start();
	 if (TWI_GetStatus() != TW_REP_START)
	 return E_NOT_OK;
	 
	 //write the device address and so we need to get A8 A9 A10 address bits and R/W=1 (Read)
	 TWI_Write((uint8)((0xA0) | ((EepromAddress & 0x0700)>>7) | 1));
	 if (TWI_GetStatus() != TW_MT_SLA_R_ACK)
	 return E_NOT_OK;
	 
			while( Length!=0)
	 			{
		 			_delay_ms(10);
	         *DataBufferPtr= TWI_ReadWithNACK();
		 			_delay_ms(10);
	         if (TWI_GetStatus() != TW_MR_DATA_NACK)
	          return E_NOT_OK;	
			  ++EepromAddress;				 
		 			--Length;
	 			}
	 		

	 
	 TWI_Stop();
	 return E_OK;
}