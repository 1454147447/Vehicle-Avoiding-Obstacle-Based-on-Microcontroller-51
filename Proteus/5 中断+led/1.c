#include <reg51.h>

void main()
    { 

			EX0=1;//�ⲿ�ж�0�����־
			EX1=1;//�ⲿ�ж�1�����־
			IT0=1;//�½��ش���
			IT1=1;//�½��ش���
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
	