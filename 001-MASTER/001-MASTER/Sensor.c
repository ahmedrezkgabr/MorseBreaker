/*
 * Sensor.c
 *
 * Created: 3/24/2021 11:35:29 PM
 *  Author: EL-talkhawy
 */ 

#include "Sensor.h"
u16 POT_VoltRead(void) 
{
	u16 adc = ADC_Read(POT_CH) ;
	/*u8 volt = (adc*5)/1024 ;
	 here does not accuarte and to avoid use float we modify it from v to mv
	 and also change from u8 to u16 */
	u16 volt = ((u32)adc*5000) / 1024 ; 
	/* if we cal adc *5000 do this op in int but it can be larger than int so truncation occuar 
	so we cast adc to u32 to cal in long  the problem ocuuar here becuase truncation occuar before division */
	return volt ;
}
u8  POT_PrecRead(void)
{ /* precantge*/
	u16 adc = ADC_Read(POT_CH) ;
	u16 volt = ((u32)adc*5000) / 1024 ; 
	return (((u32)volt *100) / 4995) ;
	
}
u16 TEMP_Read(void) 
{  // increase 10mv for every degree
	u16 adc  = ADC_Read(LM_35) ; 
	u16 volt = ((u32)adc*5000) / 1024 ; 
	u16 t = volt  ; // not volt / 10 increase zero but save accuarcy 
	return t  ;
}

u16 PRESS_Read(void)
{
	u16 adc = ADC_Read(MPX_4115) ; 
	u32 p = ((u32)adc-55)*10857 + 1500000 ; 
	p = p /10000 ; //pressure here increase zero 
	return p ;
}
