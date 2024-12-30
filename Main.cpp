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

    Autocliker autocliker;

    autocliker.Cliker('1');

    return -1;
}