// Project "autoclicher_in_the_console_cpp"
// Libraries
#include <iostream>
// Header files
#include "AutoclikerMenu.h"
#include "AutoclikerClass.h"

int main()
{
    std::cout << "Auto clicker started" << std::endl; 
    //char menu = AutoclikerMenu();

    Autocliker autocliker;

    autocliker.ChangeParameters('1');
    autocliker.DisplaySettings();
    autocliker.ChangeParameters('2');
    autocliker.DisplaySettings();
    autocliker.ChangeParameters('3');
    autocliker.DisplaySettings();
}

