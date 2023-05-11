#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cmath>
#include <chrono>

#define PI 3.14159265

int main() {
    int duration;
    std::cout << "Enter the duration in minutes for the mouse to move: ";
    std::cin >> duration;

    // Convert duration to milliseconds
    auto end_time = std::chrono::system_clock::now() + std::chrono::minutes(duration);

    // Get the current mouse position
    POINT cursorPos;
    GetCursorPos(&cursorPos);

    int radius = 50;  // radius of the circle
    double angle = 0; // angle for moving the mouse in a circle

    while (std::chrono::system_clock::now() < end_time) {
        if (_kbhit()) {
            if (_getch() == 27) //27 is the ASCII value for the ESC key
                break;
        }
        SetCursorPos(cursorPos.x + radius * cos(angle), cursorPos.y + radius * sin(angle));
        angle += 0.1; // Increase the angle to move the mouse in a circle
        if (angle > 2 * PI) {
            angle -= 2 * PI;
        }
        Sleep(100); // Adding a small delay to prevent excessive CPU usage
    }
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
