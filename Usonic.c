#include <stdio.h>
#include <wiringPi.h>

#define TRIG 4 // GPIO 23
#define ECHO 5 // GPIO 24

extern double Dist();


int main(int argc, char **argv)
{
	wiringPiSetup(); // Pin numbering method : Wpi
	pinMode(TRIG,OUTPUT); // sonic balsin
	pinMode(ECHO,INPUT);  // sonic susin
	
	for(;;)
	{
		
		printf("Distance : %f(cm)\n",Dist());
		delay(500);
	}
	return 0;
}

