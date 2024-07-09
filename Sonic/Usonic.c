#include <stdio.h>
#include <wiringPi.h>

#define  wpi_Pin 23 //GPIO 13
#define TRIG 4 // GPIO 23
#define ECHO 5 // GPIO 24
#define sw_Pin   27 // GPIO 16

extern double Dist();
extern void calcRange();
extern void playSound(int um, int rthm);
extern int song[];
extern int rythm[];
int flag = 1;

void shutdown()
{
	pinMode(wpi_Pin, OUTPUT);   
	digitalWrite(wpi_Pin, LOW); 
	
	flag =!flag;
}

int main(int argc, char **argv)
{
	//int Pitch[] = {262,277,294,311,330,349,370,392,415,440,466,494};
	//int range[12]; // Range Register values

               
	wiringPiSetup(); // Pin numbering method : Wpi
	pinMode(wpi_Pin, PWM_OUTPUT); // Set 
	calcRange();
	pwmSetMode(PWM_MODE_MS);
	pinMode(TRIG,OUTPUT); // sonic balsin
	pinMode(ECHO,INPUT);  // sonic susin
	pinMode(sw_Pin,INPUT);	  // switch
	wiringPiISR(sw_Pin,INT_EDGE_FALLING,shutdown);
	
	while(flag)
	{
		printf("Distance : %.2f(cm)\n",Dist());
			
			for(int i =0; song[i]!= -1;i++)
			{
				playSound(song[i],rythm[i]);
				
			}	
			
	}
	return 0;
}

