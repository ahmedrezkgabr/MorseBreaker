#ifndef LCD_H_
#define LCD_H_
#include "DIO_Interface.h"

#include <util/delay.h>

#define  _4_BIT  0 
#define  _8_BIT  1


/******************* PIN CONFIG *******************************/

#define LCD_MODE _4_BIT



#define  RS  PINC2
#define  EN  PINC3

#define  D7  PINC7
#define  D6  PINC6
#define  D5  PINC5
#define  D4  PINC4

#define  LCD_PORT PC


/***************************************************************/

/* to do linking config 
typedef struct 
{
	DIO_Pin_type RS ; 
	DIO_Pin_type EN 
	DIO_Port_type LCD_PORT ; 
	}LCD_LConfig_type ;
	
LCD_LConfig_type lcd_config = {PINB0 , PINB1 , LCD_PORT} ; */
	

	



void LCD_Init (void)  ;
void LCD_WriteChar (u8 ch)   ;
void LCD_WriteString (u8 *str) ; //	LCD_WriteString((u8*)"mom") ; to prevent warning
void LCD_WriteNumber (s64 num) ;
void LCD_ClearDisplay (void) ;
void LCD_WriteBin (s8 num) ; 
void LCD_WriteHex (u8 num) ;
void LCD_GoTo(u8 line ,u8 x) ;
void LCD_WriteHex(u8 num) ;
void LCD_WriteNumber_4Digit (u16) ;






#endif /* LCD_H_ */
