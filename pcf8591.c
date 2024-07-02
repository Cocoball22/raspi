#include <stdio.h>
#include <wiringPi.h>
#include <pcf8591.h>

#define PCF 120

int main(){
		int value;
		// int off = 1;
		wiringPiSetup();
		
		pcf8591Setup(PCF,0x48);
		while(1){
			value = analogRead(PCF+0);
			printf("%d\n",value);
			analogWrite(PCF+0,value);
			delay(10);
			
		}
		return 0;
}
