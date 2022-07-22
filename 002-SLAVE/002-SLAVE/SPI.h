/*
 * SPI.h
 *
 * Created: 8/30/2021 12:20:56 PM
 *  Author: EL-talkhawy
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "Utils.h" 
#include "StdTypes.h" 
#include "DIO_Interface.h"
void SPI_MasterInit() ;
void SPI_SalveInit() ;
u8 SPI_Transfer (u8 data) ;
void SPI_Send (u8 data) ;
u8 SPI_Receive(void) ;
void SPI_SendString(u8* str) ;
void SPI_ReceiveString(u8* str) ;


#endif /* SPI_H_ */