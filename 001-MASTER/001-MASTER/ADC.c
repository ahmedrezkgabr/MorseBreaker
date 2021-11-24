
#include "ADC.h"

static u8 Read_Flag = 1 ;

void ADC_Init(ADC_Vref_type vref ,ADC_Scaler_type scaler) 
{
	switch(vref)
	{
		case VREF_AREF :
		CLEAR_BIT(ADMUX , REFS0) ;
		CLEAR_BIT(ADMUX , REFS1) ; 
		break ;
		case VREF_AVCC :
        SET_BIT(ADMUX , REFS0) ;
		CLEAR_BIT(ADMUX , REFS1) ;
		break ;
		case VREF_256 :
		SET_BIT(ADMUX , REFS0) ;
		SET_BIT(ADMUX , REFS1) ;
		break ;
		
	}
	// prescaler 
	/* if we use switch case we have 8 probablities  and every one take  3 instruction so make 24 instruction
	  we can replace it for  speed  */ 
	ADCSRA &= 0xf8 ; // here we clear first 3 bits that responsible for prescaler to avoid or with one 
	ADCSRA |= scaler ;
	
	//READING ADJUST 
	CLEAR_BIT(ADMUX ,ADLAR) ;  // ordinary way
	//enable
	SET_BIT(ADCSRA , ADEN) ;
	
	
}

u16 ADC_Read(ADC_Channel_type channel ) 
{
	//select channel 
	ADMUX &= 0xe0 ; //0b111
	ADMUX |= channel ;
	// start conversion 
	SET_BIT(ADCSRA , ADSC) ;
	while(READ_BIT(ADCSRA , ADSC)) ; //busy wait polling
	//reading 
	return ADC ;
}

void ADC_StartConversion (ADC_Channel_type channel)
{
	if(Read_Flag == 1)
	{
		//select channel
		ADMUX &= 0xe0 ; //0b111
		ADMUX |= channel ;
		// start conversion
		SET_BIT(ADCSRA , ADSC) ;
		Read_Flag = 0 ;
	}
	
}  
u16 ADC_GetRead (void)
{
	while(READ_BIT(ADCSRA ,ADSC)) ;
	return ADC ;
}

u8 ADC_GetRead_NOBLOCK (u16 *pdata)
{
	u8 status = 0 ; 
	if(READ_BIT(ADCSRA ,ADSC)==0)
	{
		*pdata = ADC ; 
		status = 1 ; 
		Read_Flag = 1 ; //to repeat start conversion 
	}
	return status ;
}