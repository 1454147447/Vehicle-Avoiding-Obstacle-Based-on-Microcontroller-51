#include<reg51.h>

	void delay(unsigned int time)//延时函数
	{
	 unsigned int i,j;
	 for(i=0;i<time;i++)
	 for(j=0;j<1000;j++)
	 ;
	} 

	void main()
	{
	 unsigned int y,j;
	 unsigned int a[8] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};//流水灯P1的值
		
		if(P3==0xfb)//按下P3.2 P1的8个灯奇亮偶不亮 1111 1011
		{
		P1=0xaa;       //1010 1010
		}
		if(P3==0xf7)//按下P3.3 P1的8个灯偶亮奇不亮 1111 0111
		{
		P1=0x55;     //0101 0101
		}
		if(P3==0xef)//按下P3.4 P1的8个灯流水灯顺着滚动一遍 1110 1111
		{ 
		for(y=0;y<8;y++)
		 {
		 P1=a[y];
		 delay(20);
		 }
		}
		if(P3==0xdf)//按下P3.5 P1的8个灯流水灯倒着滚动一遍 1101 1111
		{ 
		for(y=0;y<8;y++)
		 {
		 P1=a[7-y];
		 delay(20);
		 }
		}
	}