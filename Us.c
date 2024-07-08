#include <stdio.h>
#include <wiringPi.h>

#define TRIG 4 // GPIO 23
#define ECHO 5 // GPIO 24

double Dist()
{
	// Trigger signal first low and delay 1us 0 and 200us deay brust 
		
		digitalWrite(TRIG,1);
		delayMicroseconds(10);
		digitalWrite(TRIG,0);
		delayMicroseconds(200); //  more delay time
		
		// Wait for ECHO signal
		
		while(digitalRead(ECHO) != 0); // first wait for burst start low power in clear
		
		
		// I control the burst delay
		while(digitalRead(ECHO) != 1); // wait for ECHO HIGH first edge start
		
		int t1 = micros(); // get the start time (in micro-second)


		while(digitalRead(ECHO) != 0); // wait for ECHO LOW faling edge
		
		int t2 = micros();
		
		
		// double dist = (t2-t1) *(340 / 1000000 / 2 * 100);
		double dist = (t2 - t1) * 0.017;  // it means half time 0.0343 / 2 = 0.01715
		
		return dist;
}


