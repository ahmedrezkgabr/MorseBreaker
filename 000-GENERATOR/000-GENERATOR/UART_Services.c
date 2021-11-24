#include "UART_Services.h"
#include "LCD.h"

void UART_SendString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		UART_Send(str[i]);
	}
   UART_Send(13);
}

void UART_ReceiveString(u8*str)
{
	u8 i=0;
	str[i]=UART_Receive();
	for (i=0;str[i]!=13;)
	{
		i++;
		str[i]=UART_Receive();
	}
	str[i]='\0';
}
static void IntToString (u8* str, s64 num)
{
	int i =0, j, temp, flag = 1 ;
	if(num==0)
	{
		str[i] = '0' ;
		str[++i] = '\0' ;
	}
	else
	{
		if (num < 0 )
		{
			str[i++] = '-' ;
			num *= -1 ;
			flag = 0 ;
		}
		for(  ; num > 0 ; ++i)
		{
			str[i] = (num%10) + '0' ;
			num /= 10 ;
		}
		if(flag)
		{
			for( j= 0; j < (i/2) ; ++j)
			{
				temp = str[i-j-1] ;
				str[i-j-1] = str[j] ;
				str[j] = temp ;
			}
		}
		else
		{
			for( j= 1; j <= (i/2)  ; ++j)
			{
				temp = str[i-j] ;
				str[i-j] = str[j] ;
				str[j] = temp ;
			}
		}


		str[i] = 0 ;

	}
}


void UART_SendNumber (s64 num)
{
	u8 str [30] = {0} ;
	IntToString(str , num) ;
	UART_SendString(str) ;
	
}
void UART_SendNumberU32(u32 num)
{
	//UART_Send((u8)num);
	//UART_Send((u8)(num>>8));
	//UART_Send((u8)(num>>16));
	//UART_Send((u8)(num>>24));
	u8*p=&num;
	UART_Send(p[0]);
	UART_Send(p[1]);
	UART_Send(p[2]);
	UART_Send(p[3]);
}


u32 UART_ReceiveNumberU32(void)
{
	//u8 b1=UART_Receive();
	//u8 b2=UART_Receive();	
	//u8 b3=UART_Receive();
	//u8 b4=UART_Receive();
	//u32 num=0;
	//num=b1|(u32)b2<<8|(u32)b2<<16|(u32)b3<<24;
	u32 num;
	u8*p=&num;
	p[0]=UART_Receive();
	p[1]=UART_Receive();
	p[2]=UART_Receive();
	p[3]=UART_Receive();
	return num;		
}

void UART_SendString_CheckSum(u8*str)
{
	u8 i=0,j=0;
	u16 sum=0;
	for (i=0;str[i];i++)
	{
		sum+=str[i];
	}
	UART_Send(i);
	for (j=0;str[j];j++)
	{
		UART_Send(str[j]);
	}
	UART_Send((u8)sum);
	UART_Send((u8)sum>>8);
	
}
u8 UART_ReceiveString_CheckSum(u8*str)
{
	u8 i,b1,b2,lens=UART_Receive();
	u16 sum_calc=0,sum_rece;
	for (i=0;i<lens;i++)
	{
		str[i]=UART_Receive();
		sum_calc+=str[i];
	}
	str[i]=0;
	b1=UART_Receive();
	b2=UART_Receive();
	sum_rece=(u16)b1|(((u16)b2)<<8);
	/*************************************/
	LCD_GoTo(0,4);
	LCD_WriteNumber(lens);
	LCD_WriteChar('-');
	LCD_WriteNumber(sum_calc);
	LCD_WriteChar('-');
	LCD_WriteNumber(sum_rece);
	if (sum_calc==sum_rece)
	{
		return 1;
	}
	else
	{
		str[0]=0;
		return 0;
	}
	
}

static u8* TX_Str;
static u8* RX_Str;
static void TX_Func(void);
static void RX_Func(void);
static u8 TX_Flag=1;
void UART_SendString_Asynch(u8*str)
{
	if (TX_Flag==1)
	{
	TX_Flag=0;
		UART_TX_SetCallBack(TX_Func);
		UART_TX_InterruptEnable();
		UART_SendNoBlock(str[0]);
		TX_Str=str;
		
	
	}
	
}

static void TX_Func(void)
{
	static u8 i=1;
	if (TX_Str[i]!=0)
	{
		UART_SendNoBlock(TX_Str[i]);
		i++;
	}
	else
	{
		i=1;
		
		TX_Flag=1;
	}
	
}

void UART_ReceiveString_Asynch(u8*str)
{
	UART_RX_InterruptEnable();
	UART_RX_SetCallBack(RX_Func);
	RX_Str=str;
}

static void RX_Func(void)
{
	static u8 i=0;
	RX_Str[i]=UART_ReceiveNoBlock();
	i++;
}