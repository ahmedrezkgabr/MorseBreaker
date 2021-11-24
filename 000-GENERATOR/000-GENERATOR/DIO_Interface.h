

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "MemMAP.h"
#include "Utils.h"
#include "StdTypes.h"

/*
  declartion of array of configuration of dio initialization */


typedef enum
{
	 OUTPUT , 
	 INFREE ,
	 INPULL 
	 
} DIO_Pin_Status_Type;

typedef enum 
{
	PA , 
	PB ,
	PC ,
	PD
}DIO_Port_type;
typedef enum 
 {
	LOW , 
	HIGH
	}DIO_PinVoltage_type;
typedef enum 
{
	PINA0 ,
	PINA1 ,
	PINA2 ,
	PINA3 ,
	PINA4 ,
	PINA5 ,
	PINA6 ,
	PINA7 ,
	
	PINB0 ,
	PINB1 ,
	PINB2 ,
	PINB3 ,
	PINB4 ,
	PINB5 ,
	PINB6 ,
	PINB7 ,
	
    PINC0 ,
    PINC1 ,
    PINC2 ,
    PINC3 ,
    PINC4 ,
    PINC5,
    PINC6 ,
    PINC7 ,
	
    PIND0 ,
	PIND1 ,
    PIND2 ,
    PIND3 ,
    PIND4 ,
    PIND5 ,
    PIND6 ,
    PIND7 ,
    
	TOTAL_PINS 
	
}DIO_Pin_type;
extern const DIO_Pin_Status_Type PinsStatusArray[TOTAL_PINS] ;

/*
every time i use it i need to pass to it the port of thing and the number of pin so it is a hard so i try to pass only one
thing express about the pin & the port so i replace it with :

void DIO_InitPin (DIO_Port_type port , u8 pnum , DIO_Pin_Status_Type status) ;

void DIO_InitPin (DIO_Pin_type pin , DIO_Pin_Status_Type status) ;

*/
/*
  i remove it from interface becuase i make it static in .c */

//void DIO_InitPin (DIO_Pin_type pin , DIO_Pin_Status_Type status) ;

/* i replace i also 
void DIO_WritePIN (DIO_Port_type port ,u8 pnum ,DIO_PinVoltage_type volt) ; */

void DIO_WritePIN (DIO_Pin_type pin ,DIO_PinVoltage_type volt) ;

/* i replace it also
DIO_PinVoltage_type DIO_ReadPIN (DIO_Port_type port , u8 pnum) ; */

DIO_PinVoltage_type DIO_ReadPIN (DIO_Pin_type pin) ;

void DIO_TogglePIN (DIO_Pin_type pin) ;

void DIO_WritePort (DIO_Port_type port , u8 value) ;

u8 DIO_ReadPORT (DIO_Port_type port) ;

void DIO_Init (void) ;




#endif /* DIO_INTERFACE_H_ */