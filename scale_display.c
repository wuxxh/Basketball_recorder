#include "reg52.h"
#include "display.h"
#include "scale_display.h"
#include "delay.h"

unsigned char a=0,b=0,c=0,d=0;
unsigned char sign=0;

//�׷�������ʾ
void jia_display(){
	display(1,a); //����ܵ�һ����ʾ0
	display(2,b); //����ܵڶ�����ʾ0
	
	if(key_s3==0){
		delay(5); //ȥ��
		if(key_s3==0){
			b++; //�ڶ�λ
			if(b==10){
				b=0;
				a++; //��λ
			}
			while(!key_s3); //ȷ��������ȫ̧��
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

//�м䲿����ʾ
void centre_display()
{
	display(3,10);
	display(4,10);
	display(5,10);
	display(6,10);
}


//�Ҳ�����ʾ
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

//ѡ��ӷ�ģʽ
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



