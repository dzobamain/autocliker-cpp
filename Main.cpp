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

    for (int i = 0; i < 10; i++)
    {
        autocliker.ClickAreaAtCursor();
        std::this_thread::sleep_for(std::chrono::seconds(1)); 
        std::cout << "click ";
    }
    std::cout << std::endl << "all";

    return -1;
}