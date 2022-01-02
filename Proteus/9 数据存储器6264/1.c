#include <reg51.h>
#include <absacc.h>
void delay_ms(unsigned int n)
{
unsigned int i,j;
for(i=n;i>0;i--)
for(j=123;j>0;j--);
}
void main (void)//编程实现，单片机将 0x00 到 0x0F 这 16 个数依次送到 6264 的 0x0000 到 0x000F 这 16 个地址中去，然后又依次取回送给 P1 显示。
{
unsigned int i;
while(1)
{
for(i=0;i<=15;i++)
{
XBYTE[0x0000+i]=i;//XBYTE是一个地址指针,用于外部数据存储器（即6264）
P1=XBYTE[0x0000+i];
delay_ms(1000);
}
}
}