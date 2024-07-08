#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <unistd.h>

void gotoxy(int x, int y) 
{
    printf("\033[%d;%dH", y, x);
}

int main()
{
    // Set up I2C device (0x48)
    int fd = wiringPiI2CSetup(0x48);

    // Check if initialization is successful
    if (fd == -1) {
        printf("Failed to initialize I2C communication.\n");
        return -1;
    }
    
    printf("I2C communication successfully set up.\n");

    while(1)
    {
        // Clear the screen and move the cursor to the top-left corner
        printf("\033[2J"); 
        printf("\033[1;1H");

        // ch 0 x-value
        wiringPiI2CWrite(fd, 0); 
        wiringPiI2CRead(fd); // clear
        int raw_x = wiringPiI2CRead(fd);  // ch0 x-value (0-255)
        int v1 = (raw_x / 255.0) * 80;  // Scale 0-255 value to 0-80
        delay(100);

        // ch 1 y-value
        wiringPiI2CWrite(fd, 1); // ch1
        wiringPiI2CRead(fd); // clear
        int raw_y = wiringPiI2CRead(fd);  // ch1 y-value (0-255)
        int v2 = (raw_y / 255.0) * 24;  // Scale 0-255 value to 0-24
        delay(100);

        // Move the cursor and print
        gotoxy(v1, v2);
        printf("0");  // Character to display
        fflush(stdout);  // Force the output buffer to flush

        // Short delay
        usleep(50000);  // Wait for 50ms
    }

    return 0;
}
