#include<pic.h>

void main(){

    ADCON1 = 0b100;
    TRISA = 0b111111;
    
    while (1) {
        if(RA2 == 0){
            while (RA2 == 0) {}
            
            TRISC = 0b10000000;
            
            CCP2CON = 0b1100;
            CCP1CON = 0b1100;
            
            T2CON = 0b110;
            PR2 = 0xff;
            
            CCPR2L =160;
            CCPR1L =110;
        }
        
        if(RA4 == 0){
            while (RA4 == 0) {}
			TRISC = 0b00000000;
            CCP2CON = 0b0000;
            CCP1CON = 0b0000;
        }
    }
}