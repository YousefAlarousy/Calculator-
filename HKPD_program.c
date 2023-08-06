/******************************************************/
/******************************************************/
/******************************************************/
/************* Author : YousefAlarousy ****************/
/************* Layer  : HAL            ****************/
/************* Module : KPD            ****************/
/************* Version : 1.00          ****************/
/************* Date   : 5/8/2023       ****************/
/******************************************************/
/******************************************************/
/******************************************************/

#include "STD_TYPES.h"
#include "MACROS.h"
#include "MDIO_interface.h"
#include "HKPD_config.h"
#include "HKPD_interface.h"
#include "HKPD_private.h"
#include <util/delay.h>

u8 HKPD_u8GetPressedKey()
{
	u8 flag=0,Local_u8PinState,Local_u8PressedKey=NOT_PRESSED ;
	u8 Local_u8ColumnIterator,Local_u8RowIterator;
	u8 ColArr[COL_SIZE]={KPD_C0,KPD_C1,KPD_C2,KPD_C3};
	u8 RowArr[ROW_SIZE]={KPD_R0,KPD_R1,KPD_R2,KPD_R3};
	u8 KPD_arr[ROW_SIZE][COL_SIZE]=KPD_Arr ;


	for(Local_u8ColumnIterator=0 ; Local_u8ColumnIterator<COL_SIZE ; Local_u8ColumnIterator++)
	{
		MDIO_VoidSetPinValue(KPD_COL_PORT,ColArr[Local_u8ColumnIterator],DIO_PIN_LOW);
		for(Local_u8RowIterator=0 ; Local_u8RowIterator<ROW_SIZE ; Local_u8RowIterator++)
		{
			MDIO_VoidGetPinValue(KPD_ROW_PORT,RowArr[Local_u8RowIterator],&Local_u8PinState);
			if(Local_u8PinState == PRESSED)
			{
				Local_u8PressedKey=KPD_arr[Local_u8RowIterator][Local_u8ColumnIterator] ;
				while(PRESSED==Local_u8PinState)
				{
					MDIO_VoidGetPinValue(KPD_ROW_PORT,RowArr[Local_u8RowIterator],&Local_u8PinState) ;
				}
				flag=1;
				break ;
			}

		}
		MDIO_VoidSetPinValue(KPD_COL_PORT,ColArr[Local_u8ColumnIterator],DIO_PIN_HIGH);
		if(flag==1)
		{
			break ;
		}

	}
	return Local_u8PressedKey ;
}


