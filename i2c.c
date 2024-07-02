#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

int main()
{
	int fd = wiringPiI2CSetup(0x48);
	
	while(1)
	{
		wiringPiI2CWrite(fd,0); // ch00
		wiringPiI2CRead(fd); // clear
		int v1 = wiringPiI2CRead(fd);  // ch0 jodo
		float f1 = (float)((v1/255.0) *5.0);
		delay(100);
		
		 // ch1 ondo
		wiringPiI2CWrite(fd,1); // ch01
		wiringPiI2CRead(fd); // clear
		int v2 = wiringPiI2CRead(fd);  // ch1 ondo
		float f2 = (float)((v2/255.0) *5.0);
		delay(100);
		
		 // ch3 resis
		wiringPiI2CWrite(fd,3); // ch03
		wiringPiI2CRead(fd); // clear
		int v3 = wiringPiI2CRead(fd);  // ch3 resis
		float f3 = (float)((v3/255.0) *5.0);
		delay(100);
		
		printf("jodo : %d Volt: %4.1f, ondo : %d , Volt: %4.1f resis : %d Volt: %4.1f \n", v1,f1, v2,f2, v3,f3);
		
	}
	return 0;
}
