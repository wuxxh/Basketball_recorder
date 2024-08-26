#include "reg52.h"
#include "timer.h"
#include "display.h"

void Init_timer()
{
	TMOD = 0x01;
}