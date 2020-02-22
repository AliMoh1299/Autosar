#include "flash_types.h"
#include "bit_math.h"


void Fls_Init( const Fls_ConfigType* ConfigPtr );
Std_ReturnType Fls_Erase( Fls_AddressType TargetAddress, Fls_LengthType Length );
Std_ReturnType Fls_Write( Fls_AddressType TargetAddress, const uint8* SourceAddressPtr, Fls_LengthType Length );
Std_ReturnType Fls_Read ( Fls_AddressType SourceAddress, uint8* TargetAddressPtr, Fls_LengthType Length );


/* 
¦ FMPRE0: 0 to 64 KB
¦ FMPRE1: 65 to 128 KB
¦ FMPRE2: 129 to 192 KB
¦ FMPRE3: 193 to 256 KB
*/
/*
¦ FMPPE0:   0 to  64 KB
¦ FMPPE1:  65 to 128 KB
¦ FMPPE2: 129 to 192 KB
¦ FMPPE3: 193 to 256 KB
*/


//*******************************************
//FCRIS
#define ARIS     0
#define PRIS     1
#define ERIS     2
#define VOLTRIS  9
#define INVDRIS  10 
#define ERRIS    11
#define PROGRIS  13

//*******************************************
//FMC
#define WRITE     0
#define ERASE     1
#define MERASE    2
#define COMT      9
#define FMC_WRKEY 111111111
//*******************************************
//FCMISC

#define AMISC     0
#define PMISC     1
#define EMISC     2
#define VOLTMISC  9
#define INVDMISC  10 
#define ERMISC    11
#define PROGMISC  13
//*******************************************
// FMC2
#define WRBUF 0
#define FMC2_WRKEY 111111111