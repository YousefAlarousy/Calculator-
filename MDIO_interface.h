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


#ifndef _MDIO_INTERFACE
#define _MDIO_INTERFACE

typedef enum{
	Return_Ok,
	Return_Nok,
	Return_NullPointer,

}Error_state_t;


#define DIO_PIN_OUTPUT     1
#define DIO_PIN_INPUT      2


#define DIO_PORTA          1
#define DIO_PORTB          2
#define DIO_PORTC          3
#define DIO_PORTD          4

#define DIO_PIN_HIGH       1
#define DIO_PIN_LOW        2

#define DIO_PIN0           0
#define DIO_PIN1           1
#define DIO_PIN2           2
#define DIO_PIN3           3
#define DIO_PIN4           4
#define DIO_PIN5           5
#define DIO_PIN6           6
#define DIO_PIN7           7

#define DIO_PORT_LOW       0x00
#define DIO_PORT_HIGH      0xff



Error_state_t MDIO_VoidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode);
Error_state_t MDIO_VoidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Mode);
Error_state_t MDIO_VoidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);
Error_state_t MDIO_VoidGetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *P_u8Value);
void Port_voidInit();

#endif
