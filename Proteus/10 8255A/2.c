#include <reg51.h>
#include <absacc.h>
#define uchar unsigned char
void delay_ms(unsigned int n)
{
unsigned int i,j;
for(i=n;i>0;i--)
for(j=123;j>0;j--);
}
void main(void)
{
unsigned int i;
for(i=0;i<8;i++)
{
XBYTE[i]=0x00;
delay_ms(100);
P1=XBYTE[i];
}
}