/*
 * Motors.c
 *
 * Created: 2/3/2021 2:14:23 PM
 *  Author: EL-talkhawy
 */ 
#include "Motors.h"

void MOTOR_CW (MOTOR_type motor) 
{
	switch(motor)
	{
		case MOTOR1 : 
		DIO_WritePIN(EN1 , HIGH) ;
		DIO_WritePIN(N1 , HIGH) ;
		DIO_WritePIN(N2 , LOW) ;
		break ; 
		case MOTOR2 :
		DIO_WritePIN(EN2 , HIGH) ;
		DIO_WritePIN(N3 , HIGH) ;
		DIO_WritePIN(N4 , LOW) ;
		break ;
	}
}

void MOTOR_CCW (MOTOR_type motor) 
{
	switch(motor)
	{
		case MOTOR1 :
		DIO_WritePIN(EN1 , HIGH) ;
		DIO_WritePIN(N1 , LOW) ;
		DIO_WritePIN(N2 , HIGH) ;
		break ;
		case MOTOR2 :
		DIO_WritePIN(EN2 , HIGH) ;
		DIO_WritePIN(N3 , LOW) ;
		DIO_WritePIN(N4 , HIGH) ;
		break ;
	}
	
}

void MOTOR_STOP (MOTOR_type motor) 
{
	switch(motor)
	{
		case MOTOR1 :
		DIO_WritePIN(EN1 , LOW) ;
		DIO_WritePIN(N1 , LOW) ;
		DIO_WritePIN(N2 , LOW) ;
		break ;
		case MOTOR2 :
		DIO_WritePIN(EN2 ,LOW) ;
		DIO_WritePIN(N3 , LOW) ;
		DIO_WritePIN(N4 , LOW) ;
		break ;
	}
	
}
/* here you write driver you can use it in app with a different techinique for ex  
you can write function forward () in app using 4 motor with clock wise or use reverse 
function with counter clock wise */ 

/********************************STEPPER*****************************************/
void STEEPER_CW (void) 
{
	DIO_WritePIN(B1 , HIGH) ;
	DIO_WritePIN(B2 ,  LOW) ;
	DIO_WritePIN(B3 ,  LOW) ;
	DIO_WritePIN(B4 ,  LOW) ;
	_delay_ms(STEPPER_DELAY) ;
	DIO_WritePIN(B1 ,  LOW) ;
	DIO_WritePIN(B2 , HIGH) ;
	DIO_WritePIN(B3 ,  LOW) ;
	DIO_WritePIN(B4 ,  LOW) ;
	_delay_ms(STEPPER_DELAY) ;
	DIO_WritePIN(B1 ,  LOW) ;
	DIO_WritePIN(B2 ,  LOW) ;
	DIO_WritePIN(B3 , HIGH) ;
	DIO_WritePIN(B4 ,  LOW) ;
	_delay_ms(STEPPER_DELAY) ;
	DIO_WritePIN(B1 ,  LOW) ;
	DIO_WritePIN(B2 ,  LOW) ;
	DIO_WritePIN(B3 ,  LOW) ;
	DIO_WritePIN(B4 , HIGH) ;
	_delay_ms(STEPPER_DELAY) ;
}
void STEEPER_CCW (void)
{
	DIO_WritePIN(B1 ,  LOW) ;
	DIO_WritePIN(B2 ,  LOW) ;
	DIO_WritePIN(B3 ,  LOW) ;
	DIO_WritePIN(B4 , HIGH) ;
	_delay_ms(STEPPER_DELAY) ;
	DIO_WritePIN(B1 ,  LOW) ;
	DIO_WritePIN(B2 ,  LOW) ;
	DIO_WritePIN(B3 , HIGH) ;
	DIO_WritePIN(B4 ,  LOW) ;
	_delay_ms(STEPPER_DELAY) ;
	DIO_WritePIN(B1 ,  LOW) ;
	DIO_WritePIN(B2 , HIGH) ;
	DIO_WritePIN(B3 ,  LOW) ;
	DIO_WritePIN(B4 ,  LOW) ;
	_delay_ms(STEPPER_DELAY) ;
	DIO_WritePIN(B1 ,  HIGH) ;
	DIO_WritePIN(B2 ,  LOW) ;
	DIO_WritePIN(B3 ,  LOW) ;
	DIO_WritePIN(B4 ,  LOW) ;
	_delay_ms(STEPPER_DELAY) ;
}




