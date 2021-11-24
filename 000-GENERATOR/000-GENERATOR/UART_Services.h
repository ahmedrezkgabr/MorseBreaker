#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "UART.h"


void UART_SendString(u8*str);
void UART_ReceiveString(u8*str);
void UART_SendNumberU32(u32 num);
u32 UART_ReceiveNumberU32(void);

void UART_SendString_CheckSum(u8*str);
u8 UART_ReceiveString_CheckSum(u8*str);

void UART_SendString_Asynch(u8*str);
void UART_ReceiveString_Asynch(u8*str);

void UART_SendNumber (s64 num) ;

#endif /* UART_SERVICES_H_ */