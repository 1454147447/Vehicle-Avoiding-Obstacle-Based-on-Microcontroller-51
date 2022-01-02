#include <reg51.h>
void main(void)//乙机用来接收
{
SCON=0x50;//串行口通信方式1，接收允许
PCON=0x00;//SMOD=0
TMOD=0x20;//定时器T1 方式2
TH1=0xF4; //波特率为2400bit/s，时钟频率11.0592MHz的初值
TL1=0xF4;
TR1=1; //启动T1定时
while(RI==0);// 接收中RI为0，直到接收完毕RI硬件置1
RI=0; //软件清0，开始下一轮接收
P1=SBUF; //接收到的数据由缓冲器送给P1
}