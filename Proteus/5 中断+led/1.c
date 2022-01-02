#include <reg51.h>

void main()
    { 

			EX0=1;//外部中断0允许标志
			EX1=1;//外部中断1允许标志
			IT0=1;//下降沿触发
			IT1=1;//下降沿触发
			EA=1;
			while(1);
    }
void int0() interrupt 0
		{
	   P1=0x55;
    }

	 
 void int1() interrupt 2
    {
	    P1=0xaa;
    }
	