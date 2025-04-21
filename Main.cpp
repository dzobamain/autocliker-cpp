/*
    Autoclicher.cpp    
*/

#include <iostream>
#include <thread>
#include <chrono>

#include "autoclikerClass.h"
#include "autoclikerMenu.h"

int main()
{
    std::cout << "Auto-clicker started" << std::endl;

    bool isActive = true;
    Autocliker autocliker;

    do
    {
        isActive = SetMenuMode(autocliker, isActive);
    } while (isActive);

    std::cout << "Auto-cliker ended\n";

    return -1;
}