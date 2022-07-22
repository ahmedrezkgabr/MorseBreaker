/*
 * Sensor.h
 *
 * Created: 3/24/2021 11:34:57 PM
 *  Author: EL-talkhawy
 */ 


// this file for anloag sensor for adc 


#ifndef SENSOR_H_
#define SENSOR_H_

#include "ADC.h"
#include "MemMAP.h"
#include "StdTypes.h"
/**************************PIN CONFIG ****************************/
#define  POT_CH    CH_0
#define  MPX_4115  CH_1
#define  LM_35     CH_0


/******************************************************************/
u16 POT_VoltRead(void) ; 
u8  POT_PrecRead(void) ; 
u16 PRESS_Read(void) ;

/* here i pass to it void becuase we have only one sensor if  more make enum that pass to it 
number of channel otherwise it know that sensor is where and do its operation */
u16 TEMP_Read(void) ;






#endif /* SENSOR_H_ */
