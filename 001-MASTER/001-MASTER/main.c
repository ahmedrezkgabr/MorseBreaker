/*
 * atmega32 driver.c
 *
 * Created: 1/28/2021 6:47:17 AM
 * Author : EL-talkhawy
 */ 


#include "DIO_Interface.h"
#include "LCD.h"
#include "UART.h"
#include "UART_Services.h"
#include "SPI.h"



#include <avr/delay.h>



u8 STR [50]  = {0};			//the array that we will receive signals on it using UART
u8 newstr[50]  = {0} ;		//the array that we will use it to contain the string after mapping
u8 strzeros[50] ;			//the array that we will receive the number of zeros on it using UART
u8 strones [50] ;			//the array that we will receive the number of ones on it using UART
u8 ss_counter = 0 ;			//the index of the newstr[] array

//enum for the alphabet
typedef enum 
{
//char  its signal  	value   	Morse code
	A = 0b01   ,		//1			.-
	B = 0b1000 ,   		//8			-...
	C = 0b1010 ,		//10		-.-.
	D = 0b100  ,		//4			-..
	E = 0b0    ,		//0			.
	F = 0b0010 ,		//2			..-.
	G = 0b110  ,		//6			--.
	H = 0b0000 ,		//0			....
	I = 0b00   ,		//0			..
	J = 0b0111 ,		//7			.---
	K = 0b101  ,		//5			-.-
	L = 0b0100 ,		//4			.-..
	M = 0b11   ,		//3			--
	N = 0b10   ,    	//2			-.
	O = 0b111  ,		//7			---
	P = 0b0110 ,		//6			.--.
	Q = 0b1101 ,		//13		--.-
	R = 0b010  ,		//2			.-.
	S = 0b000  ,		//0			...
	T = 0b1    ,		//1			-
	U = 0b001  ,		//1			..-
	V = 0b0001 ,		//1			...-
	W = 0b011  ,		//3			.--
	X = 0b1001 ,		//9			-..-
	Y = 0b1011 ,		//11		-.--
	Z = 0b1100			//12		--..
}Morse_t;

void func (void)
{
	;
}


int main(void)
{
	DIO_Init() ;
	LCD_Init() ;
	UART_Init() ;
	sei() ;
	SPI_MasterInit();

	


    while (1) 
    {

		UART_ReceiveString(strzeros) ;				//receiving the array that contain the number of zeros for each element
		UART_ReceiveString(strones)  ;				//receiving the array that contain the number of ones for each element
		//check if the sending and receiving are done well
		if(!UART_ReceiveString_CheckSum(STR))		//receiving the array of the elements each one is a signal that represents a character
		{
			//if they are not done well the LCD will print "wrong !!"
			LCD_GoTo(1 ,0) ; 
			LCD_WriteString((u8*)"wrong !!") ;
		}
		else
		{

    	/*UART_u8RecAsynch(func ,strzeros);
    	UART_u8RecAsynch(func ,strones);
    	UART_u8RecAsynch(func ,STR);*/
			//if they are done well the for loop will iterate on every element in the array
			for(u8 i= 0 ; STR[i] ; ++i)
			{
				//we will represent every signal with its own character
				switch(STR[i])
				{
				//some signals has the same values of others so we will check at these cases the number of dots and dashes
					case 1 :		//A, T, U, V
						if((strones[i] == 1) && (strzeros[i] == 1))
						{
							newstr[ss_counter++] ='A' ;
						} 
						else if((strones[i] == 1) && (strzeros[i] == '!' ))
						{
							newstr[ss_counter++] ='T' ;
						}
						else if((strones[i] == 1) && (strzeros[i] == 2))
						{
							newstr[ss_counter++] ='U' ;
						}
						else if((strones[i] ==1 ) && (strzeros[i] ==3 ))
						{
							newstr[ss_counter++] ='V' ;
						}
						break ;
					 
					case B :
						newstr[ss_counter++] ='B' ;
						break ;
					
					case C :
						newstr[ss_counter++] ='C' ;
						break ;
					
					case 4 :		//D, L
						if((strones[i] == 1) && (strzeros[i] == 2))
						{
							newstr[ss_counter++] ='D' ;
						}
						else if((strones[i] == 1) && (strzeros[i] ==3 ))
						{
							newstr[ss_counter++] ='L' ;
						}
						break ;
					
						//here we used '!' to represent 0 in sending because 0 will stop the array (null character)
					case '!' :		//E, H, I, S
						if((strzeros[i] == 1))
						{
							newstr[ss_counter++] ='E' ;
						}
						else if( (strzeros[i] == 4 ))
						{
							newstr[ss_counter++] ='H' ;
						}
						else if((strzeros[i] == 2))
						{
							newstr[ss_counter++] ='I' ;
						}
						else if(  (strzeros[i] ==3 ))
						{
							newstr[ss_counter++] ='S' ;
						}
					
						break ;
					
					case 2 :		//F, N, R
						if((strones[i] == 1) && (strzeros[i] == 3))
						{
							newstr[ss_counter++] ='F' ;
						}
						else if((strones[i] == 1) && (strzeros[i] == 1))
						{
							newstr[ss_counter++] ='N' ;
						}
						else if((strones[i] == 1) && (strzeros[i] == 2))
						{
							newstr[ss_counter++] ='R' ;
						}
						break ;
					
					case 6 :		//G, P
						if((strones[i] == 2) && (strzeros[i] == 1))
						{
							newstr[ss_counter++] ='G' ;
						}
						else if((strones[i] == 2) && (strzeros[i] == 2))
						{
							newstr[ss_counter++] ='P' ;
						}
						break ;
					
						case 7 :		//J, O
						if((strones[i] == 3) && (strzeros[i] == 1))
						{
							newstr[ss_counter++] ='J' ;
						}
						else if( (strzeros[i] == '!'))
						{
							newstr[ss_counter++] ='O' ;
						}
						break;
					
					case K :
						newstr[ss_counter++] ='K' ;
						break ;
					
					case 3 :		//M, W
						if((strones[i] == 2) && (strzeros[i] == '!'))
						{
							newstr[ss_counter++] ='M' ;
						}	
						else if((strones[i] == 2) && (strzeros[i] == 1))
						{
							newstr[ss_counter++] ='W' ;
						}
						break ;
					
					case Q :
						newstr[ss_counter++] ='Q' ;
						break ;
			
					case X :
						newstr[ss_counter++] ='X' ;
						break ;
					
					case Y :
						newstr[ss_counter++] ='Y' ;
						break ;
					
					case Z :
						newstr[ss_counter++] ='Z' ;
						break ;
				}
			}
			


		}
		//print the array after mapping
		LCD_GoTo(1,0) ;
		LCD_WriteString(newstr) ;
		if(!DIO_ReadPIN(PIND7))
		{
			SPI_SendString(newstr) ;

		}

	}
}
