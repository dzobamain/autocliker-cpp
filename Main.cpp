// Project "autoclicher_in_the_console_cpp"
// Libraries
#include <iostream>
#include <thread>
#include <chrono>
// Header files
#include "AutoclikerMenu.h"
#include "AutoclikerClass.h"

int main()
{
    std::cout << "Auto-clicker started" << std::endl;

    bool isActive = true;
    Autocliker autocliker;

    do // Menu
    {
        char positioNumber = AutoclikerMenu();
        switch (positioNumber)
        {
        case '1':
        {
            char positioClickMode = SetClickMode();
            autocliker.Cliker(positioClickMode);
            break;
        }
        case '2':
            autocliker.DisplaySettings();
            break;
        case '3':
            autocliker.ChangeParameters('1');
            break;
        case '4':
            autocliker.ChangeParameters('2');
            break;
        case '5':
            autocliker.ChangeParameters('3');
            break;
        case '6':
            autocliker.ChangeParameters('4');
            break;
        case 'q':
        case 'Q':
            isActive = false;
            break;
        default:
            std::cout << "Invalid option. Try again." << std::endl; 
            break;
        }
    } while (isActive);

    std::cout << "Auto-cliker ended\n";

    return -1;
}