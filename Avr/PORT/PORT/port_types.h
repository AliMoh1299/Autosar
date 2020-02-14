typedef uint8 Port_PinType ;

typedef struct{
uint8 Port_DirectionType;
}Port_ConfigType;

typedef enum {
	
	PORT_PIN_IN=0,
	PORT_PIN_OUT
	
}Port_PinDirectionType;

extern const Port_ConfigType Port_config [];

#define OUTPUT 255
#define INPUT   0

