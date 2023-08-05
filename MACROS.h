#define SET_BIT(reg,Bit_num)     reg|=(1<<Bit_num)
#define CLR_BIT(reg,Bit_num)     reg&=~(1<<Bit_num)
#define TOGGLE_BIT(reg,Bit_num)  reg^=(1<<Bit_num)
#define GET_BIT(reg,Bit_num)     (reg>>Bit_num)&1
