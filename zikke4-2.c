#include<pic.h>
void main()
{
	int i = 0;
	int j = 0;
	int flag = 0; 
	int k = 2;
	OPTION = 0b11010111;
	TRISB = 0b11000001;
	PORTB = 0b10;
	T0IF = 0b00;
	flag = 1;
	
	while(flag < 5){
		if(T0IF == 0b01){
			i = i + 1;
			T0IF = 0b00;
			if(i == 76){	
				PORTB = PORTB * 2;
				i = 0;
				flag = flag + 1;
			
			}
		}
	}
	
	T0IF = 0b00;
	while(flag > -2){
		if(T0IF == 0b01){
			i = i + 1;
			T0IF = 0b00;
			if(i == 76){	
				PORTB = 64 - k;
				k = k * 2;
				i = 0;
				flag = flag -1;
			}
		}
	}
}