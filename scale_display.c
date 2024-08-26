#include "reg52.h"
#include "display.h"
#include "scale_display.h"
#include "delay.h"

unsigned char a=0,b=0,c=0,d=0;
unsigned char sign=0;

//甲方分数显示
void jia_display(){
	display(1,a); //数码管第一个显示0
	display(2,b); //数码管第二个显示0
	
	if(key_s3==0){
		delay(5); //去抖
		if(key_s3==0){
			b++; //第二位
			if(b==10){
				b=0;
				a++; //进位
			}
			while(!key_s3); //确保按键完全抬起
		}
	}
	if(key_s4==0){
		delay(5);
		if(key_s4==0){
			b+=3;
			if(b>=10)
			{
				b=0;
				a++;
			}
			while(!key_s4);
		}
	}
}

//中间部分显示
void centre_display()
{
	display(3,10);
	display(4,10);
	display(5,10);
	display(6,10);
}


//乙部分显示
void yi_display()
{
	display(7,c);
	display(8,d);
	if(key_s3==0){
		delay(5);
		if(key_s3==0){
			d++;
			if(d==10){
				d=0;
				c++;
			}
			while(!key_s3);
		}
	}
	if(key_s4==0){
		delay(5);
		if(key_s4==0){
			d+=3;
			if(d>=10){
				d=0;
				c++;
			}
			while(!key_s4);
		}
	}
}

//选择加分模式
void mode_select()
{
	if(key_s2==0){
		delay(5);
		if(key_s2==0){
			sign = ~sign;
			while(!key_s2);
		}
	}
	if(sign==0)
	{
		jia_display();
		centre_display();
		display(7,c);
		display(8,d);
	}
	else{
		yi_display();
		centre_display();
		display(1,a);
		display(2,b);
	}
		
}



