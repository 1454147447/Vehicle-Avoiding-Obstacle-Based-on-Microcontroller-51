#include<reg51.h>

	void delay(unsigned int time)//��ʱ����
	{
	 unsigned int i,j;
	 for(i=0;i<time;i++)
	 for(j=0;j<1000;j++)
	 ;
	} 

	void main()
	{
	 unsigned int y,j;
	 unsigned int a[8] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};//��ˮ��P1��ֵ
		
		if(P3==0xfb)//����P3.2 P1��8��������ż���� 1111 1011
		{
		P1=0xaa;       //1010 1010
		}
		if(P3==0xf7)//����P3.3 P1��8����ż���治�� 1111 0111
		{
		P1=0x55;     //0101 0101
		}
		if(P3==0xef)//����P3.4 P1��8������ˮ��˳�Ź���һ�� 1110 1111
		{ 
		for(y=0;y<8;y++)
		 {
		 P1=a[y];
		 delay(20);
		 }
		}
		if(P3==0xdf)//����P3.5 P1��8������ˮ�Ƶ��Ź���һ�� 1101 1111
		{ 
		for(y=0;y<8;y++)
		 {
		 P1=a[7-y];
		 delay(20);
		 }
		}
	}