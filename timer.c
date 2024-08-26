#include "reg52.h"
#include "timer.h"
#include "display.h"

#define TIMS 45872 //大约50ms一次

//初始化定时器0
void Init_timer0()
{
	TMOD = 0x01; //设置定时器基础模式
	TL0 = TIMS;
	TH0 = TIMS >> 8;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}