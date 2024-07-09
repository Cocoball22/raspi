#include <stdio.h>
#include <wiringPi.h>

#define  wpi_Pin 23 //GPIO 13
#define TRIG 4 // GPIO 23
#define ECHO 5 // GPIO 24

void Trigger()
{
	// Trigger signal first low and delay 1us 0 and 200us deay brust 
		
		digitalWrite(TRIG,1);
		delayMicroseconds(10);
		digitalWrite(TRIG,0);
		delayMicroseconds(200); //  more delay time!
}

