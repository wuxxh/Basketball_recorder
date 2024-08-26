#include "reg52.h"
#include "delay.h"

void delay(unsigned int a){
	unsigned int i,j;
	for(i=a;i>0;i--)
		for(j=114;j>0;j--);
}