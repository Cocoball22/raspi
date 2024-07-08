#include <stdio.h>
#include <wiringPi.h>

#define  wpi_Pin 23 //GPIO 13
// end july-02
int PSC =19;
int RANGE = 100;
// int DUTY = RANGE /2;

enum { DO, Do, RE, Re, MI, FA, Fa, SL, Sl, LA, La, CI}; // Do DO# sign to interger
int Pitch[] = {262,277,294,311,330,349,370,392,415,440,466,494};
int range[12];
int song[] = {SL,SL,LA,LA,SL,SL,MI,SL,SL,MI,MI,RE,
	      SL,SL,LA,LA,SL,SL,MI,SL,MI,RE,MI,DO,-1};
int rythm[] = {4,4,4,4,4,4,8,4,4,4,4,16,
               4,4,4,4,4,4,8,4,4,4,4,16};

void calcRange() // Calc Range values using Pitch data
{
	
	for(int i = 0; i<12; i++)
	{
		range[i] = 19200000 / (PSC * Pitch[i]);
	}
	
	
}

void playSound(int um, int rthm) // um : pitch, rythm
{
	pwmSetClock(PSC); // prescaler : ~ 1MHz
	pwmSetRange(range[um]); // Range
	pwmWrite(wpi_Pin, range[um]/2);
	delay(rthm*125);
	
}

int main(void)
{
	
	wiringPiSetup(); // Initialize wiringPi library
    
	pinMode(wpi_Pin, PWM_OUTPUT); // Set 
	pwmSetMode(PWM_MODE_MS);
	calcRange();
	
	for(int i =0; song[i]!= -1;i++)
	{
	    playSound(song[i],rythm[i]);
	}
	pwmWrite(wpi_Pin, LOW);
	pinMode(wpi_Pin, OUTPUT);
	
	return 0;
}
