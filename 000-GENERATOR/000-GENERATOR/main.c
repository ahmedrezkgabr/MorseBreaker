#include "DIO_Interface.h"
#include "LCD.h"
#include "ADC.h"
#include "EX_Interrupt.h"

//#include "UART/UART_interface.h"
#include "UART.h"
#include "UART_Services.h"





void EX0_Flag(void);

void EX1_Flag(void);

void EX2_Flag(void);

void Timer_MORSE_VidSignalRead(void);



volatile u8 flag0 = 0, flag1 = 0 ,flag2 = 0 , signal = 0 ;

u8 strzeros[50] = {0} ;
u8 strones[50]  = {0} ;
u8 counter = 0;




int main (void)
{
	u8 j ;
	u8 str[50] = {0};	//it will contain the signals and will be send when calling EX2_Flag back

	DIO_Init() ;
	DIO_WritePIN(PINA7 , HIGH);
	LCD_Init() ;


	//for initializing ADC and choosing the mode and prescaller
	ADC_Init(VREF_AVCC , ADC_SCALER_64) ;

	UART_Init() ;
	sei() ;
	//UART_vidinit();

	//for external interrupt 0 initializing and enabling and calling EX0_Flag back
	EXI_TriggerEdge(EX_INT0 ,FALLING_EDGE) ;
	EXI_SetCallBack(EX_INT0 ,EX0_Flag ) ;
	EXI_Enable(EX_INT0) ;

	//for external interrupt 1 initializing and enabling and calling EX1_Flag back
	EXI_TriggerEdge(EX_INT1 ,FALLING_EDGE) ;
	EXI_SetCallBack(EX_INT1 ,EX1_Flag ) ;
	EXI_Enable(EX_INT1) ;

	//for external interrupt 2 initializing and enabling and calling EX2_Flag back
	EXI_TriggerEdge(EX_INT2 ,FALLING_EDGE) ;
	EXI_SetCallBack(EX_INT2 ,EX2_Flag ) ;
	EXI_Enable(EX_INT2) ;


	while(1)
	{
		if(flag0 == 1)
		{
			//if flag0 is set that means that now start reading the value on ADC
			Timer_MORSE_VidSignalRead() ;
			//reclear the flag
			flag0 = 0 ;
		}	
		
		
		if(flag1 == 1)
		{
			//here when flag1 is set that mean but the signal in the next array element
			if(signal == 0)
			{
				//here if signal is 0 we will represent it with 33 (ASCII of '!')
				str[counter++] = '!' ;
				LCD_GoTo(1,0) ;
				LCD_WriteChar('0') ;
			}
			else
			{
				str[counter++] = signal;
				LCD_GoTo(1,0) ;
				LCD_WriteChar('0' + str[counter-1]) ;
			}
			
			//reclear the flag and signal
			signal = 0;
			flag1 = 0;
			LCD_GoTo(0,0) ;
			LCD_WriteString("                    ");
			LCD_GoTo(0,0) ;
		
		}
		
		for(j=0 ; j< counter ; j++)
		{
			//here if number of zeros or ones is 0 we will represent it with 33 (ASCII of '!')
			if(strones[j] == 0)
			{
				strones[j] = '!';
			}
			if(strzeros[j] == 0)
			{
				strzeros[j] = '!';
			}
		}

		if(flag2 == 1)
		{
			//if flag2 is set send (strzeros , strones) and send str with checksum with UART
			u8 i ;

		    UART_SendString(strzeros) ;
			UART_SendString(strones)  ;
			UART_SendString_CheckSum(str) ;

			/*UART_u8sendAsynch (strzeros);
			UART_u8sendAsynch (strones);
			UART_u8sendAsynch (str);*/
			//reclear everything
			for(i=0 ; i < counter ; ++i)
			{
				str[i] = 0 ;
				strones[i] = 0 ;
				strzeros[i] = 0 ;	
			}
			counter = 0 ;
			flag2 = 0 ;
			LCD_GoTo(0,0) ;
			DIO_WritePIN(PINA7 , LOW);
			_delay_ms(500);
			DIO_WritePIN(PINA7 , HIGH);

		}
	}
}




void EX0_Flag(void)
{
	//this function will set the flag0 which will call external interrupt 0
	flag0 = 1;
}



void EX1_Flag(void)
{
	//this function will set the flag1 which will call external interrupt 1
	flag1 = 1;
}


void EX2_Flag(void)
{
	//this function will set the flag2 which will call external interrupt 2
	flag2 = 1;
}



void Timer_MORSE_VidSignalRead(void)
{
	//this function will read the value of ADC0 and convert it to signal
	u16 adc , volt ;
	adc = ADC_Read(CH_0) ;
	volt = ((u32)adc*5000) /1023 ;		//mapping
	//if reads logical 0 it will be represented in signal by one and ('.')
	if(volt >= 0 && volt <= 2500)
	{
		signal = (signal<<1) | 0 ;
		strzeros[counter]++ ;
		LCD_WriteChar('.') ;
	}
	//if reads logical 1 it will be represented in signal by zero and ('-')
	else if(volt >2500 && volt <= 5000)
	{
		strones[counter]++ ;
		signal = (signal<<1) | 1 ;
		LCD_WriteChar('-') ;
	}
}




