#include<pic.h>


//////////
#define B0 20	//シ
#define C  19	//ド
#define Cs 18	//ド#
#define D  17	//レ
#define Ds 16	//レ#
#define E  15	//ミ
#define F  14	//ファ
#define G  12	//ソ
#define A  11	//ラ
#define B  10	//シ
/////////////////////////

//////////////////
#define HACHI	9766		//	8/16
#define ROKU	7324		//	6/16
#define YON		4882		//	4/16
#define SAN		3662		//	3/16
#define NI		2441        //	2/16
#define ICHI	1221		//	1/16
////////////////////////////////////////////////////////

void onpu(int onkai, int time){
	int i = 0;
	int j = 0;
	int flag = 0;
	
	for(j=0;j<time;j++){
		while(1){				
			if(T0IF == 1){
				i++;
				T0IF = 0;						
				if(i >= onkai){	
					if(flag == 1){	
						PORTA = 0;
						flag = 0;
					}else{
						PORTA = 0b00100000;
						flag = 1;
					}
					i =0;
				}
			break;
			}
		}
	}
}

void main(){
	
		OPTION = 0b11010000;
		TRISA = 0b11000001;
		PORTA = 0b00100000;
		T0IF = 0;
 	
 	while(1){

		
		onpu(Ds, YON);
		onpu(Cs, YON);
		onpu(B0, ROKU);
		onpu(Ds, NI);
		
		onpu(Cs, SAN);
		onpu(B0, ICHI);
		onpu(B0, NI);
		onpu(B0, HACHI);
		onpu(B0, ICHI);
		onpu(Cs, ICHI);
		
		onpu(Ds, SAN);
		onpu(Ds, ICHI);
		onpu(Ds, NI);
		onpu(E, NI);
		onpu(Ds, SAN);
		onpu(B0, ICHI);
		onpu(B0, NI);
		onpu(Ds, NI);
		
		onpu(Ds, SAN);
		onpu(Cs, ICHI);
		onpu(Cs, NI);
		onpu(B0, NI);
		onpu(B0, HACHI);
		
	}
}

