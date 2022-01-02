#include<reg51.h>
 void delay(unsigned int time)//ÑÓÊ±²ÎÊı
 {
 unsigned int i,j;
 for(i=0;i<time;i++)
 for(j=0;j<1000;j++)
 ;
 }
 void main()
 {
 unsigned char code table[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
 unsigned int y;
 for(y=0;y<=9;y++)
 {
 P1=table[y];
 delay(80);
 }
  }