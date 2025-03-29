#ifndef AUTOCLIKERCLASS_H
#define AUTOCLIKERCLASS_H

#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <cctype>
#include <ApplicationServices/ApplicationServices.h>

class Autocliker // Повне оголошення класу
{
private:
    int _numberOfClicks;
    int _delayBetweenClicks; // ms
    int _clickExecutionTime; // sec
    int _timeToStart; // sec

public:
    Autocliker();
    void DisplaySettings();
    void ChangeParameters(char positionNumber);
    void ClickAreaAtCursor();
    void Cliker(char positionNumber);
};

#endif // AUTOCLIKERCLASS_H