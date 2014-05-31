//  �ɦW:E93C462.C
//  �t�X"EEPROM 93C46��ߪO"
//  �g�J�@�ƭ�(5678h)��93C46����}00
// �@�~�令��}01
#pragma oe db pw(80) SM SB CD
#include	<reg51.h>
sbit EEPROMCS=P0 ^0 ;
sbit EEPROMSK=P0 ^1 ;
sbit EEPROMDI=P0 ^2 ;
sbit EEPROMDO=P0 ^3 ;
#define CLOCK  EEPROMSK=0; EEPROMSK=1;
#define SEND(DI)  EEPROMDI=DI; CLOCK;
main()
{
 unsigned int Data ;
 unsigned char i ;
 P0=0xff ;
 EEPROMCS=0 ;	// �]�w CS,SK ����	
 EEPROMSK=0 ;
 EEPROMCS=1 ;	//�ϼg�J�P��	
 SEND(1) ;	//�ҩl�줸	
 SEND(0);SEND(0);	//���O00
 SEND(1);SEND(1);	//�����O11
 for(i=0;i<4;i++) {	//4-'X' Bit 
 SEND(0) ;
 }	
 EEPROMCS=0 ;
 // �g�J�@�ƭ�(5678h)��93C46����}(00) 
 EEPROMCS=1 ;
 SEND(1) ;		// �ҩl�줸	
 SEND(0) ; SEND(1) ;	// ���O01
 for(i=0;i<5;i++){	// ��}000000
	    SEND(0) ;
	}
 SEND(1);
 Data=0x5678 ;		// �e�X���
 for(i=0 ; i < 16 ; i++){
    if(Data & 0x8000){
	SEND(1) ;
    }
    else {
	SEND(0) ;
    }
    Data <<=1 ;
 }
 EEPROMCS=0 ;	//����READY 
 EEPROMCS=1 ;
 while(!EEPROMDO){
    CLOCK ;
 }
 
 EEPROMCS=1 ;	// �ϼg�J����
 SEND(1) ;	// �ҩl�줸	
 SEND(0);SEND(0); //���O00	
 SEND(0) ; SEND(0) ;//�����O00
 for(i=0 ; i < 4 ; i++){
    SEND(0) ;
 }
 EEPROMCS=0 ;
 for(;;) ;
}