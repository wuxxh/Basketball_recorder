#include "reg52.h"
#include "display.h"
#include "delay.h"
#include "scale_display.h"
#include "timer.h"

bit mode = 0;
unsigned char sec=0,min=10,num=0,flag=0,q,w,mq,mw,fq,fw;
//µπº∆ ±œ‘ æ
void count_down_display()
{
	display(1,mw);
	display(2,mq);
	display(3,10);
	display(4,w);
	display(5,q);
	display(7,fw);
	display(8,fq);
}

void main()
{
	Init_timer0();
	while(1){
		if(key_s1==0)
			delay(5);
		if(key_s1==0)
		{
			mode=~mode;
			while(!key_s1);
		}
		if(mode)
		{
			count_down_display();
		}
		else
		{
			mode_select();
		}
	}
}


void time() interrupt 1
{
	TH0=(65535-45872)/256;
	TL0=(65536-45872)%256;
	num++;
	if(num==20)
	{
		num=0;
		flag++;
		sec--;
		q = sec%10;
	    w = sec/10;
		fw=flag/10;
		fq=flag%10;

	}
	if(sec==0)
	{
		sec=60;
		min--;
		mq=min%10;
		mw=min/10;
	}
	if(flag==24)
		flag=0;
}





