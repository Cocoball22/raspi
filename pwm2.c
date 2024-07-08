#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define  wpi_Pin 3

int main(int n, char *s[])
{
    if(n < 2)
    {
        printf("usage: pwm1 [duty_rate(%%)] [period (optional)]\n\n");
        return 1;
    }
    
    int dr, drh, period = 10;  // duty rate
    sscanf(s[1], "%d", &dr);  // Read duty rate from command line argument
    
    // Check if period argument is provided
    if (n > 2)
    {
        sscanf(s[2], "%d", &period); // Read period from command line argument
    }
    
    drh = (dr * period) / 100;  // Calculate high duration
    
    
    wiringPiSetup(); // Initialize wiringPi library
    
    pinMode(wpi_Pin, OUTPUT); // Set LED pin as output
	
	pwmSetMode(PWM_MODE_MS);
	softPwmCreate(wpi_Pin,drh,period);
	
    delay(5000);
    softPwmStop(wpi_Pin);
    return 0;
 }
