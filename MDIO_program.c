/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : YousefAlarousy ****************/
/************* Layer  : MCAL           ****************/
/************* Module : DIO            ****************/
/************* Version : 1.00          ****************/
/************* Date   : 2/8/2023       ****************/
/******************************************************/
/******************************************************/
/******************************************************/

#include "STD_TYPES.h"
#include "MACROS.h"
#include "MDIO_register.h"
#include "MDIO_private.h"
#include "MDIO_interface.h"
#include "MDIO_config.h"




Error_state_t MDIO_VoidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode)
{
	Error_state_t Error_state=Return_Ok ;
	if(Copy_u8Pin<=7)
	{
		if(Copy_u8Mode==DIO_PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA : CLR_BIT(DDRA,Copy_u8Pin); break ;
			case DIO_PORTB : CLR_BIT(DDRB,Copy_u8Pin); break ;
			case DIO_PORTC : CLR_BIT(DDRC,Copy_u8Pin); break ;
			case DIO_PORTD : CLR_BIT(DDRD,Copy_u8Pin); break ;
			default : Error_state=Return_Nok ; break ;

			}
		}
		else if(Copy_u8Mode==DIO_PIN_OUTPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA : SET_BIT(DDRA,Copy_u8Pin); break ;
			case DIO_PORTB : SET_BIT(DDRB,Copy_u8Pin); break ;
			case DIO_PORTC : SET_BIT(DDRC,Copy_u8Pin); break ;
			case DIO_PORTD : SET_BIT(DDRD,Copy_u8Pin); break ;
			default :Error_state=Return_Nok ;  break ;

			}
		}
	}
	else
	{
		Error_state=Return_Nok ;
	}
	return Error_state ;

}
Error_state_t MDIO_VoidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode)
{
	Error_state_t Error_state=Return_Ok ;
	if(Copy_u8Pin<=7)
	{
		if(Copy_u8Mode==DIO_PIN_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA : CLR_BIT(PORTA,Copy_u8Pin); break ;
			case DIO_PORTB : CLR_BIT(PORTB,Copy_u8Pin); break ;
			case DIO_PORTC : CLR_BIT(PORTC,Copy_u8Pin); break ;
			case DIO_PORTD : CLR_BIT(PORTD,Copy_u8Pin); break ;
			default :Error_state = Return_Nok ; break ;

			}
		}
		else if(Copy_u8Mode==DIO_PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA : SET_BIT(PORTA,Copy_u8Pin); break ;
			case DIO_PORTB : SET_BIT(PORTB,Copy_u8Pin); break ;
			case DIO_PORTC : SET_BIT(PORTC,Copy_u8Pin); break ;
			case DIO_PORTD : SET_BIT(PORTD,Copy_u8Pin); break ;
			default :Error_state = Return_Nok ; break ;

			}
		}
	}
	else
	{
		Error_state = Return_Nok ;
	}
	return Error_state ;

}
Error_state_t MDIO_VoidGetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *P_u8Value)
{
	Error_state_t Error_State=Return_Ok ;
	if(P_u8Value != NULL)
	{
		if(Copy_u8Pin<=7)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA :*P_u8Value= GET_BIT(PINA,Copy_u8Pin); break ;
			case DIO_PORTB :*P_u8Value= GET_BIT(PINB,Copy_u8Pin); break ;
			case DIO_PORTC :*P_u8Value= GET_BIT(PINC,Copy_u8Pin); break ;
			case DIO_PORTD :*P_u8Value= GET_BIT(PIND,Copy_u8Pin); break ;
			default :Error_State=Return_Nok ;  break ;
			}
		}
		else
		{
			Error_State=Return_Nok ;
		}
	}
	else
	{
		Error_State=Return_NullPointer ;
	}



	return Error_State ;

}

Error_state_t MDIO_VoidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
	Error_state_t Error_State=Return_Ok ;
	switch(Copy_u8Port)
	{
	case DIO_PORTA : PORTA=Copy_u8Value ;break ;
	case DIO_PORTB : PORTB=Copy_u8Value ;break ;
	case DIO_PORTC : PORTC=Copy_u8Value ;break ;
	case DIO_PORTD : PORTD=Copy_u8Value ;break ;
	default : Error_State=Return_Nok ;break ;
	}
	return Error_State=Return_Nok ;
}
void Port_voidInit()
{
	DDRA = PORTA_DIR ;
	DDRB = PORTB_DIR ;
	DDRC = PORTC_DIR ;
	DDRD = PORTD_DIR ;


	PORTA = PORTA_Value ;
	PORTB = PORTB_Value ;
	PORTC = PORTC_Value ;
	PORTD = PORTD_Value ;

}






