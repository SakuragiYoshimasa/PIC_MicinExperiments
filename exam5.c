#include<pic.h>


int i = 0;
int flag = 0;
void sw(){	

	if(T0IF == 0b01){
		i = i + 1;
		T0IF = 0b00;
		if(i == 5){	
			if(flag == 1){	
				PORTA = 0;
				flag = 0;
			}else{
				PORTA = 0b00100000;
				flag = 1;
			}
			i =0;
		}
	}
}

int main(){
 
	OPTION = 0b11010000;
	TRISA = 0b11000001;
	PORTA = 0b00100000;
	T0IF = 0b00;
	while(1){
		sw();
	}
}

