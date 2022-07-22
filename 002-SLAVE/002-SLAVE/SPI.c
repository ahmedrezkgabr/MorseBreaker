/*
 * SPI.c
 *
 * Created: 8/30/2021 12:37:35 PM
 *  Author: EL-talkhawy
 */ 
#include "SPI.h"

static void(*SPI_STC_Fptr)(void)=NULLPTR;

void SPI_MasterInit() 
{
	/*** MSB **/ 
	CLEAR_BIT(SPCR,DORD) ;
	/* master is set */
	SET_BIT(SPCR,MSTR) ;
	/* clk idle ow | leading edge is rising */
	CLEAR_BIT(SPCR,CPOL) ;
	/* sample at leading */ 
	CLEAR_BIT(SPCR,CPHA) ;
	/* clk fosc /16 */
	SET_BIT(SPCR,SPR0) ;
	CLEAR_BIT(SPCR,SPR1) ;
	CLEAR_BIT(SPSR,SPI2X) ;
	/** SPI ENABLE **/
	SET_BIT(SPCR,SPE) ;
}
void SPI_SalveInit() 
{
	/*** MSB **/
	CLEAR_BIT(SPCR,DORD) ;
	/* salve is set */
	CLEAR_BIT(SPCR,MSTR) ;
	/* clk idle ow | leading edge is rising */
	CLEAR_BIT(SPCR,CPOL) ;
	/* sample at leading */
	CLEAR_BIT(SPCR,CPHA) ;
	/** SPI ENABLE **/
	SET_BIT(SPCR,SPE) ;
	
}
u8 SPI_Transfer (u8 data) 
{
	/* send data */
	SPDR = data ; 
	while(!READ_BIT(SPSR,SPIF)) ; 
	return SPDR ;
}
void SPI_Send (u8 data)
{
	SPDR = data ;
	while(!READ_BIT(SPSR,SPIF)) ;
}
u8 SPI_Receive(void)
{
	while(!READ_BIT(SPSR,SPIF)) ;
	return SPDR ; 
}
void SPI_SendString(u8* str)
{
	u8 i ; 
	for(i= 0 ; str[i] ; ++i)
	{
		SPI_Send(str[i]) ;
	}
	SPI_Send(13) ;
	
}
void SPI_ReceiveString(u8* str)
{
	u8 i = 0 ; 
	str[i] = SPI_Receive() ;
	for(i= 0 ; str[i] != 13 ; )
	{
		++i ;
		str[i] = SPI_Receive() ;
	}
	
}
/*u8 SPI_Send (u8 data)
{
	SPDR = data ;
	while(!READ_BIT(SPSR,SPIF)) ;
}
u8 SPI_Receive(void)
{
	while(!READ_BIT(SPSR,SPIF)) ;
	return SPDR ; 
}
void SPI_SendNoBlock(u8 data)
{
	SPDR=data;
}

u8 SPI_ReceiveNoBlock(void)
{
	return SPDR ;
}*/
/*void SPI_SendString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		SPI_Send(str[i]);
	}
	
}*/

/*void SPI_ReceiveString(u8*str)
{
	u8 i ; 
	for(i=0 ; str[i] ; ++i)
	{
		str[i] = SPI_Receive() ;
	}

}*/

/*void SPI_InterruptEnable()
{
	SET_BIT(SPCR,SPIE) ;
}
void SPI_InterruptDisable()
{
	CLEAR_BIT(SPCR,SPIE) ;
}
void SPI_STC_SetCallBack(void (*LocalFptr)(void))
{
	SPI_STC_Fptr = LocalFptr;
}
ISR (SPI_STC_vect)
{
	if (SPI_STC_Fptr!=NULLPTR)
	{
		SPI_STC_Fptr();
	}
}*/





/*


static u8* Send_Str;
static u8* Receive_Str;
static void Send_Func(void);
static void Receive_Func(void);
static u8 Send_Flag=1;

void SPI_SendString_Asynch(u8*str)
{
	if (Send_Flag==1)
	{
		Send_Flag=0;
	    SPI_STC_SetCallBack(Send_Func);
		SPI_InterruptEnable();
		SPI_SendNoBlock(str[0]);
		Send_Str=str;
	}
	
}

static void Send_Func(void)
{
	static u8 i=1;
	if (Send_Str[i]!=0)
	{
		SPI_SendNoBlock(Send_Str[i]);
		i++;
	}
	else
	{
		i=1;
		
		Send_Flag=1;
	}
	
}

void SPI_ReceiveString_Asynch(u8*str)
{
	SPI_InterruptEnable();
	SPI_STC_SetCallBack(Receive_Func);
	Receive_Str=str;
}

static void Receive_Func(void)
{
	static u8 i=0;
	Receive_Str[i]=SPI_ReceiveNoBlock();
	i++;
}

*/
