#include<pic.h>
void accel(int time){
    int a;
    for(a = 0; a < time; a++){
        CCPR2L++;
        CCPR1L++;
        flat(2);
    }
}

void flat(int time){
    int b;
    for(b = 0; b<time; b++){
        while (1) {
            if(T0IF == 1){
                break;
            }
        }
        T0IF = 0;
    }
}

void brake(int time){
    int c;
    for(c = 0; c < time; c++){
        CCPR1L--;
        CCPR2L--;
        flat(2);
    }
}

void move(int acceTime, int evalTime){
    TRISC = 0b10000000;
    CCP2CON = 0b1100;
    CCP1CON = 0b1100;
    T2CON = 0b110;
    PR2 = 0xff;
    CCPR2L =0;
    CCPR1L =0;
    accel(acceTime);
    flat(evalTime);
    brake(acceTime);
    CCPR1L = 0;
    CCPR2L = 0;
}

void main(){
    TRISA = 0b11011111;
    OPTION =0b11010111;
    ADCON1 = 0b100;
    TRISA = 0b111111;
    while (1) {
        if(RA2 == 0){
            while (RA2 == 0) {}
            move(400,100);
        }
    }
}
