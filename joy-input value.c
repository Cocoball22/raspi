#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

#define BUTTON_PIN 22

int main()
{
	wiringPiSetup();
	
	int fd = wiringPiI2CSetup(0x48);
	pinMode(BUTTON_PIN, INPUT);  // Set button pin as input
	
	while(1)
	{
		// ch 0 x-value
		wiringPiI2CWrite(fd,0); 
		wiringPiI2CRead(fd); // clear
		int v1 = (wiringPiI2CRead(fd) / 255.0) * 80;  // ch0 x-value
		float f1 = (float)((v1/80.0) *5.0);
		delay(100);
		
		 // ch1 y-value
		wiringPiI2CWrite(fd,1); // ch01
		wiringPiI2CRead(fd); // clear
		int v2 = (wiringPiI2CRead(fd) / 255.0) * 24;  // ch1 y-value
		float f2 = (float)((v2/24.0) *5.0);
		delay(100);
		
		
		int button_state = digitalRead(BUTTON_PIN);  // Read button state
        delay(100);  // Delay to debounce button reading
		
		printf("X : %d Volt: %4.1f, Y : %d , Volt: %4.1f button : %d \n", v1,f1, v2,f2, button_state);
		
		
	}
	return 0;
}
