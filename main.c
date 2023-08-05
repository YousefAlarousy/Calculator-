#include "STD_TYPES.h"
#include "MACROS.h"
#include <util/delay.h>
#include "HLCD_interface.h"
#include "HKPD_interface.h"

int main()
{
	u32 x,r ,op1=0,op2=0;
	f32 f;
	u8 operation,flag=0 ;
	Port_voidInit();
	HLCD_voidInit();
	while(1)
	{
		x=HKPD_u8GetPressedKey();
		if(x!=NOT_PRESSED)
		{
			if( (x!='/') && (x!='*') && (x!='+') && (x!='-') && (x!='=') && (x!='#') )
			{
				HLCD_voidSendDigit(x);
				if(flag==0)
				{
					op1=(op1*10) + x ;
				}
				else
				{
					op2=(op2*10) + x ;
				}

			}
			else if( (x=='/') || (x=='*') || (x=='+') || (x=='-') )
			{
				HLCD_voidSendData(x);
				operation=x ;
				flag=1 ;
			}
			else if ( x=='=' )
			{
				switch(operation)
				{
				case '+':r=op1+op2 ; break ;
				case '-':r=op1-op2 ; break ;
				case '*':r=op1*op2 ; break ;
				case '/':f=(f32)op1/(f32)op2 ; break ;
				default : break ;
				}
				HLCD_voidSendGoTo(1,0);
				HLCD_voidSendString("Result=");
				if(operation=='/')
				{
					HLCD_voidSendFloat(f,1,7);
				}
				else
				{
					HLCD_voidSendInt(r,1,7);
				}

			}
			else
			{
				HLCD_voidClearLcd();
				op1=0;
				op2=0;
				flag=0;
			}
		}


	}
}

