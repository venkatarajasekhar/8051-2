//  �ɦW:TIMER0A.C
//  �t�X"TIMER/COUNTER��ߪO"
//  �Q�έp�ɤ��_���ͭp�Ʃ���ĪG
// Homework: change to timer 1 and delay 1s
#pragma oe db pw(80) SM SB CD
#include <reg51.h>	//8051��l�]�w
char Count ;	//�w�q�r����Ƭ�Count

main()
{
 P0=Count=0 ;	//LED���t
 TMOD=0x10 ;	//�]�wTimer0��16�줸�p�ɾ�
 TH0=(0xffff-100000)/256;	//TH0=0xD8
 TL0=(0xffff-100000)%256;	//TL0=0xEF
 EA=1 ;		//�P�त�_�\��
 ET1=1 ;	//�p�ɭp�ƾ�0�P��
 TR1=1 ;	//�p�ɾ�0�}�l�p��
 for(;;) ;	//���ݭp�ɤ��_
}
 void timer1(void) interrupt 3
{
 Count++ ;	//Count=Count+1,�ּW�@
 P0=Count ;	//��X��LED���
 TH0=(0xffff-100000)/256; //TH0=0xD8,�٭�p�ɼƭ�
 TL0=(0xffff-100000)%256; //TL0=0xEF
}