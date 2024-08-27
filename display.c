#include "reg52.h"
#include "delay.h"
#include "display.h"

sbit WE = P2^7; //led
sbit DU = P2^6; //led

sbit lsc = P2^4;
sbit lsb = P2^3;
sbit lsa = P2^2;

#define SMG_PORT P0 //定义数码管段码口

void display(unsigned char location,unsigned char number){
	unsigned char code locate[] = 
		{
			0xfe, 
			0xfd, 
			0xfb, 
			0xf7, 
			0xef, 
			0xdF, 
			0xbF, 
			0x7F
		};
	unsigned char code tablel[] =
		{
			0x3F, //"0"
			0x06, //"1"
			0x5B, //"2"
			0x4F, //"3"
			0x66, //"4"
			0x6D, //"5"
			0x7D, //"6"
			0x07, //"7"
			0x7F, //"8"
			0x6F, //"9"
			0x40  //"-"
		}; //数码管显示数字和符号
		
	
	P0 = 0x00; //初始化P0
	WE = 1;
	P0 = locate[location - 1];
		
	DU = 1;
	P0 = tablel[number];
	DU = 0;
	delay(1);
		
}