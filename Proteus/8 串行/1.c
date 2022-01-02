#include <reg51.h>
sbit P3_2=P3^2;
sbit P3_3=P3^3;
sbit P3_4=P3^4;
sbit P3_5=P3^5;
unsigned int y;
unsigned int a[8] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};//流水灯P1的值
void delay(unsigned int time)//延时函数
	{
	 unsigned int i,j;
	 for(i=0;i<time;i++)
	 for(j=0;j<1000;j++)
	 ;
	} 
void main(void)
{
SCON=0x50;//串行口通信方式1，接收允许
	//01 01 00 00b
	//工作方式1，SM1 SM0 = 01 SM2 = 0 REN = 1 TB8 = 0，RB8 = 0 TI = 0，RI = 0
PCON=0x00;//SMOD=0
	//选择不倍增，波特率倍增位SMOD = 0，
TMOD=0x20;//定时器T1 方式2
	//0 0 10 0000b。
	//GATE = 0 C/T=0 M1M0 = 10 TMOD低四位缺省为0000
TH1=0xF4; //波特率为2400bit/s，时钟频率11.0592MHz的初值
	//波特率为2400bit/s，时钟频率fosc = 11.0592MHz，SMOD=0，带入公式
  //T1的初值X = 256－fosc×2的SMOD次方 / （12×波特率×32）
TL1=0xF4;
TR1=1; //启动T1定时
//SBUF是缓冲器

if(P3_2==0) //检测按键，仿真环境下标准下降沿，无需软件消抖
{
	SBUF=0xaa;   //1010 1010
	while(TI==0);//发送中TI 为0，直到发送完毕TI 硬件置1
	TI=0; //软件清0，开始下一轮发送
}
if(P3_3==0) 
{
	SBUF=0x55; 	//0101 0101
	while(TI==0);//发送中TI 为0，直到发送完毕TI 硬件置1
	TI=0; //软件清0，开始下一轮发送
}
if(P3_4==0) 
{		
	for(y=0;y<8;y++)  //从上到下滚动一遍
		 {
		 SBUF=a[y];
		 delay(20);
		 }
	while(TI==0);//发送中TI 为0，直到发送完毕TI 硬件置1
	TI=0; //软件清0，开始下一轮发送
}
if(P3_5==0) 
{
	for(y=0;y<8;y++)  //从下到上滚动一遍
		 {
		 SBUF=a[7-y];
		 delay(20);
		 }
	while(TI==0);//发送中TI 为0，直到发送完毕TI 硬件置1
	TI=0; //软件清0，开始下一轮发送
}
else
 {
	SBUF=0xff; //灯不亮
	while(TI==0);
	TI=0;
 }
}