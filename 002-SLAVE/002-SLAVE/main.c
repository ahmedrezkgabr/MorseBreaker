/*
 * atmega32 driver.c
 *
 * Created: 1/28/2021 6:47:17 AM
 * Author : EL-talkhawy
 */ 


#include "DIO_Interface.h"
#include "ADC.h"
#include "SPI.h"
#include "Sensor.h"
#include "Timers.h"
#include "servo.h"
#include "LCD.h"
#include "ADC.h"
#include "SPI.h"
#include "MOTORS.h"
#include "Sensor.h"




u8 check_equality(u8 *copy_pstring,u8 *copy_word)
{
	u8 state =0;
	u8 flag=1;
	for(u8 i=0;copy_word[i]!='\0';i++)
	{

		if(copy_word[i]!=copy_pstring[i])
		{
			flag=0;
			break;
			UART_vidsend(state+'0');
		}

	}
	/*if(flag==1)
	{
		//UART_vidsendstring(copy_pstring);
		state=1;
	}*/
	return flag ;
}
int main(void)
{
	u8 str[50] = "OK" ;
	u16 temp , press ;
	DIO_Init()   ;
	LCD_Init()   ; 
	ADC_Init(VREF_AVCC , ADC_SCALER_64) ;
	SERVO_Init() ;
	SPI_SalveInit();
	sei() ;
	while(1)
	{


		 LCD_GoTo(1,0) ;
		 LCD_WriteString(str);
		 press = PRESS_Read() ;
		 temp = TEMP_Read() ;
		 LCD_GoTo(0,0) ;
		 LCD_WriteString("P=") ;
		 LCD_GoTo(0,3) ;
		 LCD_WriteNumber(press) ;
		 LCD_GoTo(0,8) ;
		 LCD_WriteString("T=") ;
		 LCD_GoTo(0,11) ;
		 LCD_WriteNumber(temp) ;
		 if(temp >= 500)
		 {
			MOTOR_CW(MOTOR1);
		 }
		 else if(temp < 480)
		 {
			 MOTOR_STOP(MOTOR1) ;
		 }
		 if(press >= 1000)
		 {
			SERVO_SetAngle(135);
		 }
		 else if(press < 980)
		 {
			 SERVO_SetAngle(30);
		 }
		 if(!DIO_ReadPIN(PINB0))
		{
		    SPI_ReceiveString(str) ;
		    LCD_GoTo(1,0) ;
		    LCD_WriteString(str);

		 }
		 if(check_equality(str , "HELP"))
		 {
			 DIO_WritePIN(PINB2 , HIGH) ;
			 u8 i ;
			 for(i=0 ; str[i] ; ++i)
			 {
				 str[i] = 0 ;
			 }
		 }

		else if (check_equality(str , "SOS"))
		 {

			 DIO_WritePIN(PINB1 , HIGH) ;
			 u8 i ;
			 for(i=0 ; str[i] ; ++i)
			 {
			 	str[i] = 0 ;
			 }

		 }
		 else if (check_equality(str , "OK"))
		 {
			 DIO_WritePIN(PINB2 , LOW) ;
			 DIO_WritePIN(PINB1 , LOW) ;
			 u8 i ;
			 for(i=0 ; str[i] ; ++i)
			  {
			 	 str[i] = 0 ;
			  }
		 }

		 
	}

	
	
	
}
