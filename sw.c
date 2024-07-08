#include <stdio.h>
#include <wiringPi.h>

#define BUTTON_PIN 3  // Connected to GPIO 23 for button signal

int main() {
    if (wiringPiSetup() == -1) {
        printf("Failed to initialize wiringPi.\n");
        return 1;
    }

    pinMode(BUTTON_PIN, INPUT);  // Set button pin as input

    while (1) {
        int button_state = digitalRead(BUTTON_PIN);  // Read button state
        if (button_state == HIGH) {
            printf("Button pressed.\n");
            // Perform desired action
        }
        delay(100);  // Delay to debounce button reading
    }

    return 0;
}
