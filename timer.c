#include "reg52.h"
#include "timer.h"
#include "display.h"

#define TIMS 45872 //��Լ50msһ��

//��ʼ����ʱ��0
void Init_timer0()
{
	TMOD = 0x01; //���ö�ʱ������ģʽ
	TL0 = TIMS;
	TH0 = TIMS >> 8;
	EA = 1;
	ET0 = 1;
	TR0 = 1;
}