#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define RED 8
#define Yellow 9
#define Blue 7
#define Sw  2
#define Sw1 3

int mode =1;
//int cnt = 200;
int intv = 0;	// 0 ~ 8
int tim;		// delay time interval (ms)
int ps[40]; // pin number : 40, pin status : default 0
int flag = 1;

void Toggle(int pin)
{
	 ps[pin] = !ps[pin];	//  change the pin state 0 -> 1
	 digitalWrite(pin,ps[pin]);
}

void gpioisr()
{
	// already button pushed so plus intv
			  if(++intv > 8) intv = 0;
			  printf("GPIO interrupt Occuered.... intv: %d tim: %d \n",intv,tim);
			
}

void shutdown()
{
	 digitalWrite(RED,0);
	 digitalWrite(Yellow,0);
	 digitalWrite(Blue,0);
	 
	 flag = !flag;
}

int main()
{
	wiringPiSetup();	// Pin number use case (wPi)
	pinMode(RED, OUTPUT);// 8,9,7 : OUT 2: IN
	pinMode(Yellow, OUTPUT);
	pinMode(Blue, OUTPUT);
	pinMode(Sw, INPUT);
	pinMode(Sw1, INPUT);
	wiringPiISR(Sw,INT_EDGE_FALLING,gpioisr); // registration GPIO ISR
	wiringPiISR(Sw1,INT_EDGE_FALLING,shutdown); 
	while(flag)
	{
		    tim  = (9-intv)*100;
			
			
				Toggle(RED); delay(tim);
				Toggle(Yellow); delay(tim);
				Toggle(Blue); delay(tim);
			
			
			/*if(digitalRead(Sw1) == 0)
			{
			   shutdown(Blue); delay(tim);
			   Toggle(Yellow); delay(tim);
			   Toggle(RED); delay(tim);
			}*/
	
	}
	return 0;
}
