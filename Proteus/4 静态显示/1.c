#include <reg51.h>

unsigned char code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};//0~9

sbit P20=P2^0;//�������������ʮλ��
sbit P21=P2^1;//�����ұ���������λ��

unsigned char a,b,c,i;

void delay(unsigned int);

void main()

	{
			while(1)  
				{

					//��ʾ00~19
					for(a=0;a<2;a++)  //ʮλ
	
					for(b=0;b<10;b++)		//��λ

					for(c=0;c<=120;c++)   //ѭ����ʾ126��

								{

									P2=0xff;

									P20=0;

									P1=table[a];

									delay(4);

									P20=1;

									P21=0;

									P1=table[b];

									delay(4);

								};
								//��ʾ"20"		
								for(i=120;i>=1;i--) 

								{

									P2=0xff;

									P20=0;

									P1=table[2];

									delay(4);

									P20=1;

									P21=0;

									P1=table[0];

									delay(4);

								};
														
							};   

					}

void delay(unsigned int m)

{

unsigned int i,j; 

for(i=m;i>0;i--)       

for(j=110;j>0;j--); /*��ʱ1ms*/

}