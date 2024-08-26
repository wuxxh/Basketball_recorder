#ifndef __scale_display_H__
#define __scale_display_H__

extern unsigned char a,b,c,d;

sbit key_s1=P3^0;
sbit key_s2=P3^1;
sbit key_s3=P3^2;
sbit key_s4=P3^3;

void mode_select();
void jia_display();
void centre_display();
void yi_display();

#endif