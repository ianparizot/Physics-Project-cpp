#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "findTime.h"

using namespace std;

int main() {
    float result;
    int choice;
    float displacement;
    float vi;
    float g;
    cout << "Welcome to freeFall a physics simulation of a free fall of an object somewhere where the drag forces don't exist.\nDo you want to use:\n    1. A negative g value\n    2. A positive g value\n    3. A personalized g value (ideal for simulations that are not on Earth or to use a more accurate value of g)\n    4. Exit\nChoice: ";
    cin >> choice;
    if (choice == 3) {
        cout << "Enter g: ";
        cin >> g;
    }
    else if (choice == 4) {
        return 1;
    }
    else if (choice == 1) {
        g = -9.81;
    }
    else if (choice == 2) {
        g = 9.81;
    }
    else {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "We didn't understand your input, try again.\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        main();
    }
    cout << "Enter the displacement: ";
    cin >> displacement;
    cout << "Enter the initial velocity (not the speed!): ";
    cin >> vi;
    result = time(displacement, vi, g);
    if (isnan(result)) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "ERROR! The values are incorrect, please try  again!\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        main();
    }
    cout << "The time is: " << result << "seconds.";
    return 0;
}
