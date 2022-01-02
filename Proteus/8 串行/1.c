#include <reg51.h>
sbit P3_2=P3^2;
sbit P3_3=P3^3;
sbit P3_4=P3^4;
sbit P3_5=P3^5;
unsigned int y;
unsigned int a[8] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};//��ˮ��P1��ֵ
void delay(unsigned int time)//��ʱ����
	{
	 unsigned int i,j;
	 for(i=0;i<time;i++)
	 for(j=0;j<1000;j++)
	 ;
	} 
void main(void)
{
SCON=0x50;//���п�ͨ�ŷ�ʽ1����������
	//01 01 00 00b
	//������ʽ1��SM1 SM0 = 01 SM2 = 0 REN = 1 TB8 = 0��RB8 = 0 TI = 0��RI = 0
PCON=0x00;//SMOD=0
	//ѡ�񲻱����������ʱ���λSMOD = 0��
TMOD=0x20;//��ʱ��T1 ��ʽ2
	//0 0 10 0000b��
	//GATE = 0 C/T=0 M1M0 = 10 TMOD����λȱʡΪ0000
TH1=0xF4; //������Ϊ2400bit/s��ʱ��Ƶ��11.0592MHz�ĳ�ֵ
	//������Ϊ2400bit/s��ʱ��Ƶ��fosc = 11.0592MHz��SMOD=0�����빫ʽ
  //T1�ĳ�ֵX = 256��fosc��2��SMOD�η� / ��12�������ʡ�32��
TL1=0xF4;
TR1=1; //����T1��ʱ
//SBUF�ǻ�����

if(P3_2==0) //��ⰴ�������滷���±�׼�½��أ������������
{
	SBUF=0xaa;   //1010 1010
	while(TI==0);//������TI Ϊ0��ֱ���������TI Ӳ����1
	TI=0; //�����0����ʼ��һ�ַ���
}
if(P3_3==0) 
{
	SBUF=0x55; 	//0101 0101
	while(TI==0);//������TI Ϊ0��ֱ���������TI Ӳ����1
	TI=0; //�����0����ʼ��һ�ַ���
}
if(P3_4==0) 
{		
	for(y=0;y<8;y++)  //���ϵ��¹���һ��
		 {
		 SBUF=a[y];
		 delay(20);
		 }
	while(TI==0);//������TI Ϊ0��ֱ���������TI Ӳ����1
	TI=0; //�����0����ʼ��һ�ַ���
}
if(P3_5==0) 
{
	for(y=0;y<8;y++)  //���µ��Ϲ���һ��
		 {
		 SBUF=a[7-y];
		 delay(20);
		 }
	while(TI==0);//������TI Ϊ0��ֱ���������TI Ӳ����1
	TI=0; //�����0����ʼ��һ�ַ���
}
else
 {
	SBUF=0xff; //�Ʋ���
	while(TI==0);
	TI=0;
 }
}