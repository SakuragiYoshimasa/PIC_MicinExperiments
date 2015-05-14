#include<pic.h>
void main()
{

	
	int i = 0;
	int j = 0;
	int flag = 0; 
	OPTION = 0b11010111;
	TRISB = 0b11000001;
	PORTB = 0b10;
	T0IF = 0b00;
	flag = 1;
	
	while(j<20){
		if(T0IF == 0b01){
			i = i + 1;
			T0IF = 0b00;
			if(i == 76){	
				if(flag == 1){	
					PORTB = 0b00;
					j = j+1;
					flag = 0;
				}else{
					PORTB = 0b10;
					j = j+1;
					flag = 1;
				}
				i =0;
			}
		}
	}
}