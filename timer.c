#include "reg52.h"
#include "timer.h"
#include "display.h"

//��ʼ����ʱ��0
void Init_timer0()
{
	TMOD = 0x01; //���ö�ʱ������ģʽ
	int TIM = 45872; //��Լ50msһ��
	TL0 = TIM;
	TH0 = TIM >> 8;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}