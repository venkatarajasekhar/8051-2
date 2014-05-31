//�ɦW:TCount.C
//�t�X"TIMER/COUNTER��ߪO"
//Timer0���p�ɾ�,Timer1���p�ƾ�,
//INT0�����k�{�{,INT1�����j�{�{
//�@�~: �令 �@ T0 ���p�ɾ� �C0.5s �N�[�@
// �G T1 ���p�ƾ�(���@��T1�}�� timer0 �Ȱ��p�� �A���@���~��
// �T T1 �����_�u������T0
#pragma oe db pw(80) SM SB CD
#include <reg51.h>
#include "sdelay.h"
void timer() ;

main()
{
 P0=0 ;       //LED���t
 TMOD=0x051 ; //T1���p�ƾ�,T0���p�ɾ�
 TH1=0xff ;   //TH1��ȳ]�w
 TL1=0xff ;   //TL1��� ,�]���n�@���NĲ�o�ҥH�令ff
 TH0=(0xffff-500000)/256 ; //TH0=0xD8
 TL0=(0xffff-500000)%256 ; 

 //IT0=1 ; //�~�����_0,�]���t�tĲ�o
 //IT1=1 ; //�~�����_1,�]���t�tĲ�o
 //EX0=1 ; //�~�����_0�P��
 //EX1=1 ; //�~�����_1�P��
 ET0=1 ; //�p�ɭp�ƾ�0�P��
 ET1=1 ; //�p�ɭp�ƾ�1�P��
 TR0=1 ; //�p�ɾ�0�}�l�p��
 TR1=1 ; //�p�ɾ�1�}�l�p��
 PT1=1; // Timer1 has higher priority
 //PT0=0;
 EA=1 ;  //�P�त�_�\��

 for(;;) ; //���d��a���ݤ��_
}

void timer0(void) interrupt 1
{
 char i,j=3,savep0 ;
 savep0=P0;	//�x�sP0��
 for(i=0;i<9;i++)
 {
 P0=j ;		//��X��LED���
 j<<=1 ;	//j �����@��
 Delay100ms() ;	//����100�@��
 }
 TH0=(0xffff-500000)/256 ; //TH0=0xD8
 TL0=(0xffff-500000)%256 ;
 P0=savep0;	//�٭�P0��        
}

void timer1(void) interrupt 3
{
 unsigned int savep0 ;
 savep0=P0;	//�x�sP0��
 if(TR0==1){
 	TR0=0;
}else{
	TR0=1;
}

 TH1=0xff ;	//��_TH1��
 TL1=0xff ;	//��_TL1��
 P0=savep0;	//�٭�P0��
}

/*void external0(void) interrupt 0
{
 unsigned savep0 ;
 savep0=P0;	//�x�sP0��
 P0=0x0f ;	//�k�b��G
 Delay100ms() ;	//����10�@��
 P0=0xf0 ;	//���b��G
 Delay100ms() ;	//����10�@��
 P0=savep0;	//�٭�P0��
}

void external1(void) interrupt 2
{
 unsigned savep0 ;
 savep0=P0;	//�x�sP0��
 P0=0x55 ;	//�a�k���j�G
 Delay100ms() ;	//����10�@��
 P0=0xaa ;	//�a�����j�G
 Delay100ms() ;	//����10�@��
 P0=savep0;	//�٭�P0��
}*/
