#include<pic.h>

void charge(){
    
    OPTION=0b11011000;		//PTION_REGレジスタ 比1:1
    T0IF=0;
    TMR0=0b10000000;			//タイマ0を25.6μsの状態にする
    while(T0IF != 1){}

}

void main(){
    
    //initialize
    int rightCycle,leftCycle;
    double rate = 160/110;
    
    //RA0,RA1,RA3 input
    TRISA = 0b11011111;
    //RC1,RC2 output
    TRISC = 0b10000000;
    
    //PWMmode
    CCP2CON = 0b1100;
    CCP1CON = 0b1100;
    
    //timer initialize
    T2CON = 0b110;
    PR2 = 0xff;
    CCPR2L = 0;
    CCPR1L = 0;
    
    
    while (1) {
        ADCON1 = 0b00000100; //A/D結果をADRESHの7-0bit:ADRESLの7-6bitへ 下位2bit無視
        
        //right
        ADCON0 = 0b11000001; //RA0 右　強ければ左が強い
        charge();
        ADGO = 1;
        while (ADGO != 0) {}; //変換
        if(ADRESH > 0b00111100){ //60以上の時
            left = 60;
        }else{
            left = ADRESH;
        }
        CCPR1L = left; //左
        
        //left
        ADCON0 = 0b11001001; //RA1 左
        charge();
        ADGO = 1;
        while (ADGO != 0) {}; //変換
        if(ADRESH > 0b00111100){
            right = 60 * rate;
        }else{
            right = ADRESH * rate;
        }
        CCPR2L = right;
        
    }
    
}
