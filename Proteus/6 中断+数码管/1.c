#include<reg51.h>
void delay(unsigned int m)

{
unsigned int i,j; 
for(i=m;i>0;i--)       
for(j=110;j>0;j--); /*��ʱ1ms*/
}

unsigned char code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//0~9

unsigned int y;
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
	    for(y=0;y<=9;y++)
			{
			P1=table[y];
			delay(300);
			}
 }
 
void int1() interrupt 2
 {
		for(y=10;y>0;y--)
		 {
		 P1=table[y-1];
		 delay(300);
		 }
 }