#include <reg51.h>
#include <absacc.h>
void delay_ms(unsigned int n)
{
unsigned int i,j;
for(i=n;i>0;i--)
for(j=123;j>0;j--);
}
void main (void)//���ʵ�֣���Ƭ���� 0x00 �� 0x0F �� 16 ���������͵� 6264 �� 0x0000 �� 0x000F �� 16 ����ַ��ȥ��Ȼ��������ȡ���͸� P1 ��ʾ��
{
unsigned int i;
while(1)
{
for(i=0;i<=15;i++)
{
XBYTE[0x0000+i]=i;//XBYTE��һ����ַָ��,�����ⲿ���ݴ洢������6264��
P1=XBYTE[0x0000+i];
delay_ms(1000);
}
}
}