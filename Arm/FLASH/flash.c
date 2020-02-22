#include "TM4C123GH6PM.h"
#include "flash.h"

Std_ReturnType Fls_Write( Fls_AddressType TargetAddress, const uint8* SourceAddressPtr, Fls_LengthType Length )
{
    // Check the arguments.
    //ASSERT(!(TargetAddress & 3));
    //ASSERT(!(Length & 3));
	
    // Clear the flash access and error interrupts.
    FLASH_CTRL->FCMISC = (AMISC | VOLTMISC | INVDMISC | PROGMISC);
    // Loop over the words to be programmed.
    while(Length)
    {
        // Set the address of this block of words.
        FLASH_CTRL->FMA = TargetAddress & ~(0x7f);
        // Loop over the words in this 32-word block.
        while((TargetAddress & 0x7c) || ((FLASH_CTRL->FWBVAL == 0) && (Length != 0)))
        {
            // Write this word into the write buffer.
           //FLASH_CTRL->FWBN + (TargetAddress & 0x7c) = *SourceAddressPtr++ ;
            TargetAddress += 4;
            Length -= 4;
        }
      // Program the contents of the write buffer into flash.
      FLASH_CTRL->FMC2 = FMC2_WRKEY | WRBUF;
      // Wait until the write buffer has been programmed.
      while(FLASH_CTRL->FMC2 & WRBUF){}
    }
    // Return an error if an access violation occurred.
    if(FLASH_CTRL->FCRIS & (ARIS | VOLTRIS | INVDRIS | PROGRIS))
    {return(E_NOT_OK);}
    // Success.
    return(E_OK);
}
















































Std_ReturnType Fls_Erase( Fls_AddressType TargetAddress, Fls_LengthType Length )
{
	
    // Check the arguments.
   // ASSERT(!(TargetAddress & (Length - 1)));
    // Clear the flash access and error interrupts.
    FLASH_CTRL->FCMISC = (AMISC | VOLTMISC | ERMISC);
    // Erase the block.
    FLASH_CTRL->FMA = TargetAddress;
    FLASH_CTRL->FMC = FMC_WRKEY | ERASE;
    // Wait until the block has been erased.
    while(FLASH_CTRL->FMC & ERASE){}
    // Return an error if an access violation or erase error occurred.
    if(FLASH_CTRL->FCRIS & (ARIS | VOLTRIS | ERRIS))
    {return(E_NOT_OK);}
    // Success.
    return(E_OK);
}