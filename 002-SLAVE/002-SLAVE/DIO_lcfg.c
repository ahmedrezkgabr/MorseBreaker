/*
 * DIO_lcfg.c
 *
 * Created: 1/28/2021 7:10:04 AM
 *  Author: EL-talkhawy
 */ 

/* configuration file does not out this 3 cases #define used in compile setting and array in configuration of  
   same type and struct for different type */ 



#include "DIO_Interface.h"

 /*
  here i want to set configuration of initialization of  DIO 
   index of array represent pin type and data is DIO_Pin_Status_Type */

 const DIO_Pin_Status_Type PinsStatusArray[TOTAL_PINS]={
	INFREE,      /* Port A Pin 0 ADC0*/
    INFREE,      /* Port A Pin 1 ADC1*/
	OUTPUT,      /* Port A Pin 2 */
	OUTPUT,      /* Port A Pin 3 */
	OUTPUT,      /* Port A Pin 4 */
	OUTPUT,      /* Port A Pin 5 */
	OUTPUT,      /* Port A Pin 6 */
	OUTPUT,      /* Port A Pin 7 ADC7*/
	INPULL,      /* Port B Pin 0   / */
	OUTPUT,      /* Port B Pin 1   /*/
	OUTPUT,		 /* Port B Pin 2 / INT2*/
	OUTPUT,		 /* Port B Pin 3   /OC0*/
	INFREE,		 /* Port B Pin 4 /ss*/
	INFREE,		 /* Port B Pin 5 //mosi*/
	OUTPUT,		 /* Port B Pin 6 /miso*/
	INFREE,		 /* Port B Pin 7 clk*/
	INPULL,		 /* Port C Pin 0 */
	OUTPUT,		 /* Port C Pin 1 */
	OUTPUT,		 /* Port C Pin 2 */
	OUTPUT,		 /* Port C Pin 3 */
    OUTPUT,		 /* Port C Pin 4 */
    OUTPUT,		 /* Port C Pin 5 */
    OUTPUT,	     /* Port C Pin 6 */
    OUTPUT,		 /* Port C Pin 7 */
	INFREE,		 /* Port D Pin 0 */
	OUTPUT,		 /* Port D Pin 1 */
    INPULL,      /* Port D Pin 2 /INT0*/
	INPULL,      /* Port D Pin 3 / INT1 */
	OUTPUT,		 /* Port D Pin 4  OC1B*/
	OUTPUT,		 /* Port D Pin 5 OC1A*/
	OUTPUT,		 /* Port D Pin 6 /   ICP*/
	OUTPUT		 /* Port D Pin 7 */	
};	


