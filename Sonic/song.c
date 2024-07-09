#include <stdio.h>
#include <wiringPi.h>

#define  wpi_Pin 23 //GPIO 13
// end july-02
extern double Dist();

int PSC =19;
int RANGE = 100;
// int DUTY = RANGE /2;

enum { DO=0, Do, RE, Re, MI, FA, Fa, SL, Sl, LA, La, CI}; // Do DO# sign to interger
int Pitch[] = {262,277,294,311,330,349,370,392,415,440,466,494};
int range[12]; // Range Register values
int song[] = {SL,SL,LA,LA,SL,SL,MI,SL,SL,MI,MI,RE,
	      SL,SL,LA,LA,SL,SL,MI,SL,MI,RE,MI,DO,-1}; // -1 is end
int rythm[] = {4,4,4,4,4,4,8,4,4,4,4,16,
               4,4,4,4,4,4,8,4,4,4,4,16};

void calcRange() // Calc Range values using Pitch data
{
	
	for(int i = 0; i<12; i++)
	{
		range[i] = 19200000 / (PSC * Pitch[i]);
	}
	
	
}
double rate = 1;
void playSound(int um, int rthm) // um : pitch, rythm
{
	pwmSetClock(PSC); // prescaler : ~ 1MHz
	pwmSetRange(range[um]); // Range
	pwmWrite(wpi_Pin, range[um]/2);
	
	if(Dist()>100) delay(2000 / (rthm*rate));
	else if(Dist()<100 && Dist()>50) delay(1000 / (rthm*rate));
	else delay(500 / (rthm*rate));
}
