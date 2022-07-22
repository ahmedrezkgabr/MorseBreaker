/*
 * DIOc.c
 *
 * Created: 1/28/2021 7:09:21 AM
 *  Author: EL-talkhawy
 */ 
#include "DIO_Interface.h"
/* i need to replace it with
void DIO_InitPin (DIO_Pin_type pin , DIO_Pin_Status_Type status) ;
but with a little change in code

void DIO_InitPin (DIO_Port_type port , u8 pnum , DIO_Pin_Status_Type status)
{
	//we have 3 status and 4 port so we have 12 probabality so we use switch case
	switch(status)
	{
		case OUTPUT :
		switch(port)
		{
			case PA :
			SET_BIT(DDRA , pnum) ;
			break ;
			case PB :
			SET_BIT(DDRB , pnum) ;
			break ;
			case PC :
			SET_BIT(DDRC , pnum) ;
			break ;
			case PD :
			SET_BIT(DDRD , pnum) ;
			break ;
		}
		break ;
		
		case INFREE :
		switch(port)
		{
			case PA :
			CLEAR_BIT(DDRA , pnum) ;
			//i do not depend on initial status because may be changed in other place
			CLEAR_BIT(PORTA , pnum) ;
			break ;
			case PB :
			CLEAR_BIT(DDRB , pnum) ;
			CLEAR_BIT(PORTB , pnum) ;
			break ;
			case PC :
			CLEAR_BIT(DDRC , pnum) ;
			CLEAR_BIT(PORTC , pnum) ;
			break ;
			case PD :
	        CLEAR_BIT(DDRD , pnum) ;
			CLEAR_BIT(PORTD , pnum) ;
			break ;
		}
		break ;
		case INPULL :
		switch(port)
		{
			case PA :
			CLEAR_BIT(DDRA , pnum) ;
			SET_BIT(PORTA , pnum) ;
			break ;
			case PB :
			CLEAR_BIT(DDRB , pnum) ;
			SET_BIT(PORTB , pnum) ;
			break ;
			case PC :
			CLEAR_BIT(DDRC , pnum) ;
			SET_BIT(PORTC , pnum) ;
			break ;
			case PD :
			CLEAR_BIT(DDRD , pnum) ;
			SET_BIT(PORTD , pnum) ;
			break ;
		}
		break ;
		
	}
	

	//to test this function you need to see that it initialize pins right or not for ex
	DIO_InitPin(PA ,4 ,OUTPUT) ;
	DIO_InitPin(PB,5,INFREE) ;
	DIO_InitPin(PC,1,INPULL) ;
	DIO_InitPin(PD ,0,INPULL) ; 
	
	
}*/

static void DIO_InitPin (DIO_Pin_type pin , DIO_Pin_Status_Type status)  
{
	/*
	  i only add these two lines to change design from 
	  void DIO_InitPin (DIO_Port_type port , u8 pnum , DIO_Pin_Status_Type status) to
	  void DIO_InitPin (DIO_Pin_type pin , DIO_Pin_Status_Type status)
	  without changing implementation   */


	u8 pnum = pin %8 ;
	DIO_Port_type port = pin /8 ;
	
	switch(status)
	{
		case OUTPUT :
		switch(port)
		{
			case PA :
			SET_BIT(DDRA , pnum) ;
			break ;
			case PB :
			SET_BIT(DDRB , pnum) ;
			break ;
			case PC :
			SET_BIT(DDRC , pnum) ;
			break ;
			case PD :
			SET_BIT(DDRD , pnum) ;
			break ;
		}
		break ;
		
		case INFREE :
		switch(port)
		{
			case PA :
			CLEAR_BIT(DDRA , pnum) ;
			//i do not depend on initial status because may be changed in other place
			CLEAR_BIT(PORTA , pnum) ;
			break ;
			case PB :
			CLEAR_BIT(DDRB , pnum) ;
			CLEAR_BIT(PORTB , pnum) ;
			break ;
			case PC :
			CLEAR_BIT(DDRC , pnum) ;
			CLEAR_BIT(PORTC , pnum) ;
			break ;
			case PD :
	        CLEAR_BIT(DDRD , pnum) ;
			CLEAR_BIT(PORTD , pnum) ;
			break ;
		}
		break ;
		case INPULL :
		switch(port)
		{
			case PA :
			CLEAR_BIT(DDRA , pnum) ;
			SET_BIT(PORTA , pnum) ;
			break ;
			case PB :
			CLEAR_BIT(DDRB , pnum) ;
			SET_BIT(PORTB , pnum) ;
			break ;
			case PC :
			CLEAR_BIT(DDRC , pnum) ;
			SET_BIT(PORTC , pnum) ;
			break ;
			case PD :
			CLEAR_BIT(DDRD , pnum) ;
			SET_BIT(PORTD , pnum) ;
			break ;
		}
		break ;
		
	}
	
	/* to test this function you need to see that it initialize pins right or not for ex 
	DIO_InitPin(PA ,4 ,OUTPUT) ;
	DIO_InitPin(PB,5,INFREE) ;
	DIO_InitPin(PC,1,INPULL) ;
	DIO_InitPin(PD ,0,INPULL) ;
	old design.....       */
	
	
}




void DIO_WritePIN (DIO_Pin_type pin ,DIO_PinVoltage_type volt) 
{
	/*
	  i only add these two lines to change design from 
      void DIO_WritePIN (DIO_Port_type port ,u8 pnum ,DIO_PinVoltage_type volt) to
      void DIO_WritePIN (DIO_Pin_type pin ,DIO_PinVoltage_type volt)
	  without changing implementation   */

	u8 pnum = pin %8 ;
	DIO_Port_type port = pin/8 ;
	
	//when you using a pin you need a volt 
	// here i use to make volt to be a main checker because it has a less probablities and use if without switch because it has only 2 porabablitity
	if(volt == HIGH)
	{
		switch(port)
		{
			case PA :
			SET_BIT(PORTA , pnum) ;
			break ;
			case PB :
			SET_BIT(PORTB , pnum) ;
			break ;
			case PC :
			SET_BIT(PORTC , pnum) ;
			break ;
			case PD :
			SET_BIT(PORTD , pnum) ;
			break ;
		}
	}
	else if (volt == LOW)
	{
		switch(port)
		{
			case PA :
			CLEAR_BIT(PORTA , pnum) ;
			break ;
			case PB :
			CLEAR_BIT(PORTB , pnum) ;
			break ;
			case PC :
			CLEAR_BIT(PORTC , pnum) ;
			break ;
			case PD :
			CLEAR_BIT(PORTD , pnum) ;
			break ;
		}		
	}
	/* call in main  more times because of it is not initialization
	 DIO_WritePIN(PA,1,HIGH) ;
	 _delay_ms(1000) ;
	 DIO_WritePIN(PA,1,LOW) ; */
	
	/*here to turn on led you must define it is number on port and define the port 
	 #define RED_LED 3
	 #define  LED_PORT PA 
	 DIO_WritePIN(LED_PORT,RED_LED,HIGH) ;
	 old design......  */
	
	/* in new design i need to define only one thing and api know port and pin 
	   #define  RED_LED PINA5 
	    DIO_WritePIN(RED_LED,HIGH) ; */

	
}
DIO_PinVoltage_type DIO_ReadPIN (DIO_Pin_type pin) 
{
	u8 pnum = pin %8 ;
	DIO_Port_type port = pin /8 ;
	
	
	DIO_PinVoltage_type volt = LOW ; 
	switch(port)
	{
		case PA : 
		/* we can return in each case 
		   return READ_BIT(PINA , pnum) ; 
		   but it is not suitable for misra rule that state to avoid logical error and provide portabality and readability 
		   here for readability and also if we do not write return below produce warning */
		    
		volt = READ_BIT(PINA , pnum) ;
		break ;
		case PB :
		volt = READ_BIT(PINB , pnum) ;
		break ;
		case PC :
		volt = READ_BIT(PINC , pnum) ;
		break ;
		case PD :
		volt = READ_BIT(PIND , pnum) ;
		break ;
	}
	return volt ;
	/* calling in main
	   #define  GREEN_LED 1 
	   if(DIO_ReadPIN(PA,GREEN_LED))
	   {}
	    // if pin is pull up 
	   if(DIO_ReadPIN(PA,GREEN_LED)== LOW)
	   {}
	 */
	   
	
	
}

void DIO_Init (void)
{
	/*
	  here i init all pin with only one function without calling 32 function
	  and if i want to change status of pin i only change in configuration file*/
	
	DIO_Pin_type i ;
	for(i = PINA0 ; i < TOTAL_PINS ; ++i)
	{
		DIO_InitPin(i,PinsStatusArray[i]) ;
	}
	
}

void DIO_WritePort (DIO_Port_type port , u8 value) 
{
	switch(port)
	{
		case PA :
		PORTA = value ;
		break ;
		case PB :
		PORTB = value ;
		break ;
		case PC :
		PORTC = value ;
		break ;
		case PD :
		PORTD = value ;
		break ;
	}
}


void DIO_TogglePIN (DIO_Pin_type pin) 
{
	u8 pnum = pin %8 ;
	DIO_Port_type port = pin /8 ;
	switch(port)
	{
		case PA :
		TOGGLE_BIT(PORTA , pnum) ;
		break ;
		case PB :
		TOGGLE_BIT(PORTB , pnum) ;
		break ;
		case PC :
	   TOGGLE_BIT(PORTC , pnum) ;
		break ;
		case PD :
		TOGGLE_BIT(PORTD , pnum) ;
		break ;
	}
	
	
}






