#include <reg51.h>
#include <absacc.h>
#define uchar unsigned char
void main()
{
unsigned char i;
XBYTE[0x0003]=0x82;//设置方式控制字，方式0，PA输出，PB 输入
			//控制字地址二进制为：0000 0000 0000 0011B。十六进制为：0x0003。
	    //1000 0010B
	    //选择方式控制字，D7=1。PA 为工作方式0，D6=0，D5=0。PA 为输出，D4=0。
			//PC 高4 位未使用，未使用则默认设置为0，D3=0。PB为工作方式0，D2=0。PB为输入，D1=1。PC低4位未使用，未使用则默认设置为0，D0=0。
while(1)
{
i=XBYTE[0x0001];//将PB端口数值赋给变量i
	//PB地址二进制为：0000 0000 0000 0001B。十六进制为：0x0001。
XBYTE[0x0000]=i;//将变量i 中的数值赋给PA端口
	//PA地址二进制为：0000 0000 0000 0000B。十六进制为：0x0000。
}
}