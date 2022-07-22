/*
 * LCD.c
 *
 * Created: 2/14/2021 9:13:28 PM
 *  Author: EL-talkhawy
 */

#include "LCD.h"


/* #include "LCD.h"

#if (LCD_MODE==_8_BIT)

static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,command);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x38);// 8 bit , 2 lines font 5*7
	_delay_ms(1);
	LCD_WriteCommand(0x0c);// 0x0e,0x0f cursor
	_delay_ms(1);
	LCD_WriteCommand(0x01);// clear screen
	_delay_ms(2);
	LCD_WriteCommand(0x06);// address increase no shift
}

#elif (LCD_MODE==_4_BIT)

static void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(command,7));
	DIO_WritePin(D6,READ_BIT(command,6));
	DIO_WritePin(D5,READ_BIT(command,5));
	DIO_WritePin(D4,READ_BIT(command,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(command,3));
	DIO_WritePin(D6,READ_BIT(command,2));
	DIO_WritePin(D5,READ_BIT(command,1));
	DIO_WritePin(D4,READ_BIT(command,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x02);
	LCD_WriteCommand(0x28);// 4 bit , 2 lines font 5*7
	_delay_ms(1);
	LCD_WriteCommand(0x0c);// 0x0e,0x0f cursor
	_delay_ms(1);
	LCD_WriteCommand(0x01);// clear screen
	_delay_ms(2);
	LCD_WriteCommand(0x06);// address increase no shift
}

#endif



void LCD_WriteChar(u8 ch)
{
	
	LCD_WriteData(ch);
	
}

void LCD_WriteString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteData(str[i]);
	}
}

void LCD_WriteNumber_4D(u16 num)//55
{
	LCD_WriteData(((num%10000)/1000)+'0');
	LCD_WriteData(((num%1000)/100)+'0');
	LCD_WriteData(((num%100)/10)+'0');
	LCD_WriteData(((num%10)/1)+'0');
}

void LCD_WriteNumber(s64 num)
{
	u8 j,i=0,str[20];
	if (num==0)
	{
		LCD_WriteData('0');
		return;
	}
	else if (num<0)
	{
		num=num*(-1);
		LCD_WriteData('-');
	}
	while(num)
	{
		str[i]=num%10+'0';
		i++;
		num=num/10;
	}
	for (j=i;j>0;j--)
	{
		LCD_WriteData(str[j-1]);
	}

}

void LCD_WriteBinary(u8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteData(READ_BIT(num,i)+'0');
	}
	
}

void LCD_WriteHex(u8 num)//0x54  0b0101 0100
{
	u8 high=num>>4;//00000101
	u8 low =num&0x0f;//00000100
	u8 HEX[16]={'0','1','A','B'};
	if(high<=9)
	LCD_WriteData(high+'0');
	else
	LCD_WriteData(high-10+'A');
	
	LCD_WriteData(HEX[low]);
	
}


void LCD_GoTo(u8 line ,u8 x)//1
{
	if (line==0)
	{
		LCD_WriteCommand(0x80+x);

	}
	else if (line==1)
	{
		LCD_WriteCommand(0x80+0x40+x);
	}

}


void LCD_GoToWriteNumber(u8 line ,u8 x,s64 num)
{
	LCD_GoTo(line,x);
	LCD_WriteNumber(num);
}

void LCD_ClearLoc(u8 line ,u8 x,u8 cells)
{
	u8 i;
	LCD_GoTo(line,x);
	for (i=0;i<cells;i++)
	{
		LCD_WriteChar(' ');
	}
	LCD_GoTo(line,x);
}

void Create_Character(u8 *Pattern,u8 Location) {

	u8 iLoop=0;

	LCD_WriteCommand(0x40+(Location*8)); //Send the Address of CGRAM
	for(iLoop=0;iLoop<8;iLoop++)
	LCD_WriteData(Pattern[iLoop]); //Pass the bytes of pattern on LCD

}
void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}*/

#if(LCD_MODE == _8_BIT) 
static void LCD_WriteCommand(u8 command)
{
	DIO_WritePIN (RS,LOW) ;
	DIO_WritePort(LCD_PORT , command) ;
	DIO_WritePIN(EN , HIGH) ;
	_delay_ms(1) ;
	DIO_WritePIN(EN , LOW) ;
	_delay_ms(1) ;

}

static void LCD_WriteData (u8 data)
{
	DIO_WritePIN(RS , HIGH) ;
	DIO_WritePort(LCD_PORT , data) ;
	DIO_WritePIN(EN ,HIGH) ;
	_delay_ms(1) ;
	DIO_WritePIN(EN ,LOW) ;
	_delay_ms(1) ;
}
void  LCD_Init ()
{
	_delay_ms(50) ; // becuase of if lcd_init () call first
	LCD_WriteCommand(0x38) ;  // 8 bit ,, 2 line ,, 5*7 font
	_delay_ms(1) ;
	LCD_WriteCommand(0x0c) ;  // 0x0e ,, 0x0f cursor
	_delay_ms(1) ;
	LCD_WriteCommand(0x01) ; // clear screen
	_delay_ms(2) ;
	LCD_WriteCommand(0x06) ; // Address increase no shift
}
#elif (LCD_MODE==_4_BIT)
static void LCD_WriteCommand(u8 command)
{
	DIO_WritePIN (RS,LOW) ;
	DIO_WritePIN(D7 , READ_BIT(command , 7)) ;
	DIO_WritePIN(D6 , READ_BIT(command , 6)) ;
	DIO_WritePIN(D5 , READ_BIT(command , 5)) ;
	DIO_WritePIN(D4 , READ_BIT(command , 4)) ;
	DIO_WritePIN(EN , HIGH) ;
	_delay_ms(1) ;
	DIO_WritePIN(EN , LOW) ;
	_delay_ms(1) ;
	DIO_WritePIN(D7 , READ_BIT(command , 3)) ;
	DIO_WritePIN(D6 , READ_BIT(command , 2)) ;
	DIO_WritePIN(D5 , READ_BIT(command , 1)) ;
	DIO_WritePIN(D4 , READ_BIT(command , 0)) ;
	DIO_WritePIN(EN , HIGH) ;
	_delay_ms(1) ;
	DIO_WritePIN(EN , LOW) ;
	_delay_ms(1) ;
	

}

static void LCD_WriteData (u8 data)
{
	DIO_WritePIN(RS , HIGH) ;
	DIO_WritePIN(D7 , READ_BIT(data , 7)) ;
	DIO_WritePIN(D6 , READ_BIT(data , 6)) ;
	DIO_WritePIN(D5 , READ_BIT(data , 5)) ;
	DIO_WritePIN(D4 , READ_BIT(data , 4)) ;
	DIO_WritePIN(EN , HIGH) ;
	_delay_ms(1) ;
	DIO_WritePIN(EN , LOW) ;
	_delay_ms(1) ;
	DIO_WritePIN(D7 , READ_BIT(data , 3)) ;
	DIO_WritePIN(D6 , READ_BIT(data , 2)) ;
	DIO_WritePIN(D5 , READ_BIT(data , 1)) ;
	DIO_WritePIN(D4 , READ_BIT(data , 0)) ;
	DIO_WritePIN(EN , HIGH) ;
	_delay_ms(1) ;
	DIO_WritePIN(EN , LOW) ;
	_delay_ms(1) ;

}
void  LCD_Init ()
{
	_delay_ms(50) ; // becuase of if lcd_init () call first
	LCD_WriteCommand(0x02) ;
	LCD_WriteCommand(0x28) ;  // 4 bit ,, 2 line ,, 5*7 font
	_delay_ms(1) ;
	LCD_WriteCommand(0x0c) ;  // 0x0e ,, 0x0f cursor
	_delay_ms(1) ;
	LCD_WriteCommand(0x01) ; // clear screen
	_delay_ms(2) ;
	LCD_WriteCommand(0x06) ; // Address increase no shift
	
}

#endif


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



void LCD_WriteChar (u8 ch)   
{
	LCD_WriteData(ch) ;
}
void LCD_WriteString(u8* str)
{
	int i ; 
	for(i=0 ; str[i] ; ++i)
	{
		LCD_WriteData(str[i]) ;
	}
}

void LCD_WriteNumber (s64 num) 
{
	u8 inttostring_arr [32] = {0} ;
	IntToString(inttostring_arr , num) ;
	LCD_WriteString(inttostring_arr) ;
}
void LCD_ClearDisplay (void) 
{
	LCD_WriteCommand(0x01) ; // clear screen
	_delay_ms(2) ;
}
void LCD_WriteBin (s8 num) 
{
	u8 arr [8] = {0}  , j = 0 , flag = 0 ;
	int i ; 
	for(i= 7 ; i >= 0 ; --i)
	{
		if(num & (1<<i))
		{
			flag = 1 ;
		}
		if(flag == 1)
		{
			if(num & (1<<i))
			{
				arr[j++] = '1' ;
			}
			else
			    arr[j++] = '0' ;
			
			
		}
	}
	LCD_WriteString(arr) ;
	
}
/*void LCD_WriteStringcon (u8* str) ;
{
	
}*/
void LCD_WriteHex(u8 num)//0x54  0b0101 0100
{
	u8 high=num>>4;//00000101
	u8 low =num&0x0f;//00000100
	u8 HEX[16]={'0','1','2','3' , '4' , '5' , '6' ,'7','8' , '9' , 'A','B' ,'C' , 'D' ,'E' ,'F'}; // using looK up table
	if(high<=9)
	LCD_WriteData(high+'0');
	else
	LCD_WriteData(high-10+'A');
	
	LCD_WriteData(HEX[low]);
}
void LCD_WriteNumber_4Digit (u16 num) 
{
	LCD_WriteData(((num %10000)/1000) + '0') ;
	LCD_WriteData(((num %1000)/100) + '0') ;
	LCD_WriteData(((num %100)/10) + '0') ;
	LCD_WriteData(((num %10)/1) + '0') ;
}
void LCD_GoTo(u8 line ,u8 x)//1
{
	if (line==0)
	{
		LCD_WriteCommand(0x80+x);

	}
	else if (line==1)
	{
		LCD_WriteCommand(0x80+0x40+x);
	}

}