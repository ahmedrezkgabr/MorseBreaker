/*
 * Motors.h
 *
 * Created: 2/3/2021 2:13:52 PM
 *  Author: EL-talkhawy
 */ 



#ifndef MOTORS_H_
#define MOTORS_H_

#include "DIO_Interface.h"
#define  F_CPU  8000000
#include <util/delay.h>

#define   STEPPER_DELAY   200


/*********************** PIN CONFIG OF DC *************************/

/* these pins exist in H bridge */

/* you must define them  in dio config as output */

#define  N1 PINC0 
#define  N2 PINC1
#define EN1 PINC2 

#define EN2 PINC3
#define  N3 PINC4
#define  N4 PINC5

/*********************** PIN CONFIG OF SERVO *************************/

/* these pins exist in ULN 2003 */

/* you must define them  in dio config as output */
#define  B1   PIND0
#define  B2   PIND1
#define  B3   PIND2
#define  B4   PIND3

/*********************************************************************/


typedef enum 
{
	MOTOR1 , 
	MOTOR2 , 
	MOTOR3 , 
	MOTOR4 
	}MOTOR_type;
	
	
	
/* if i have more motor i can make a function for every motor or i can pass argument for function 
to select which motor we work */

/*************************************** DC MOTOR ************************************/

void MOTOR_CW (MOTOR_type motor) ;

void MOTOR_CCW (MOTOR_type motor) ;

void MOTOR_STOP (MOTOR_type motor) ;

/******************************************STEPPER**********************************/

void STEEPER_CW (void) ;
void STEEPER_CCW (void) ;
void STEEPER_STOP( void) ;

/**********************************************************************************/







#endif /* MOTORS_H_ */