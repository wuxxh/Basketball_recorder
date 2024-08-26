#include "reg52.h"
#include "timer.h"
#include "display.h"

//初始化定时器0
void Init_timer0()
{
	TMOD = 0x01; //设置定时器基础模式
	int TIM = 45872; //大约50ms一次
	TL0 = TIM;
	TH0 = TIM >> 8;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}