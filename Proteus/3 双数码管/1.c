#include<reg51.h>
 void delay(unsigned int time)//延时参数
 {
 unsigned int i,j;
 for(i=0;i<time;i++)
 for(j=0;j<1000;j++)
 ;
 }
void main()
{
	 unsigned char code temp[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
   unsigned int x,y;
	 while(1)
	 {
		if(P3==0xfb)//P3.2亮  1111 1011
				 {
					 P1=0x3f;
					 for(y=0;y<=1;y++)
					 {
						for(x=0;x<=9;x++)
						{
							P2=temp[x];
							delay(80);
						}
						P1=temp[y+1];
					}
					 P2=0x3f;//结束状态为20
				}
				
				 if(P3==0xf7)//P3.3亮  1111 0111
					 {
						 P1=0x5b;
						 P2=0x3f;    //初始状态为20
						 delay(80);
						 for(y=2;y>=1;y--)
						 {
							P1=temp[y-1];
							for(x=0;x<=9;x++)
							{
							P2=temp[9-x];
							delay(80);
							}
						}
					 }
		} 
}