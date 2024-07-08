#include <stdio.h>
#include <wiringPi.h>

#define LED_pin 3 // GPIO pin number to control the LED

int main(int n, char *s[])
{
    if(n < 2)
    {
        printf("usage: pwm1 [duty_rate(%%)] [period (optional)]\n\n");
        return 1;
    }
    
    int dr, drh, drl, period = 10;  // duty rate
    sscanf(s[1], "%d", &dr);  // Read duty rate from command line argument
    
    // Check if period argument is provided
    if (n > 2)
    {
        sscanf(s[2], "%d", &period); // Read period from command line argument
    }
    
    drh = (dr * period) / 100;  // Calculate high duration
    drl = period - drh; // Calculate low duration
    
    wiringPiSetup(); // Initialize wiringPi library
    
    pinMode(LED_pin, OUTPUT); // Set LED pin as output
    
    // Toggle the LED on and off
    for (int i = 0; i < 500; i++)
    {
        digitalWrite(LED_pin, HIGH); // Turn on the LED (HIGH state applies voltage)
        delay(drh); // Delay for drh milliseconds
        
        digitalWrite(LED_pin, LOW); // Turn off the LED (LOW state removes voltage)
        delay(drl); // Delay for drl milliseconds
    }
    
    return 0;
}
