#ifndef AUTOCLIKERCLASS_H
#define AUTOCLIKERCLASS_H

#include <iostream>
#include <ncurses.h>
#include <cstdlib>

class Autocliker
{
private:
    int _numberOfClicks;     // кількість кліків / number of clicks
    int _delayBetweenClicks; // затримка між кліками (мс) / delay between clicks (ms)
    int _clickExecutionTime; // час виконання кліків (секунди) / click execution time (seconds)

public:
    Autocliker() : _numberOfClicks(100), _delayBetweenClicks(100), _clickExecutionTime(10) {}

    void DisplaySettings()
    {
        std::cout << "Number of clicks = " << _numberOfClicks << "\n";
        std::cout << "Delay between clicks = " << _delayBetweenClicks << " ms\n";
        std::cout << "Click execution time = " << _clickExecutionTime << " seconds\n";
    }

    void ChangeParameters(char positioNumber)
    {
        if (positioNumber != '1' && positioNumber != '2' && positioNumber != '3')
            return;

        initscr();
        clear();
        noecho(); // Вимикаємо автоматичне відображення введених символів / Disable automatic echoing of typed characters

        printw("Enter number of clicks: ");
        refresh(); // Оновлення екрану / Update the screen

        char input[10];
        getstr(input);
        positioNumber == '1' ? _numberOfClicks = atoi(input) : (positioNumber == '2' ? _delayBetweenClicks = atoi(input) : (positioNumber == '3' ? _clickExecutionTime = atoi(input) : 0));

        endwin(); // Завершення роботи ncurses / End ncurses mode
    }
};

#endif // AUTOCLIKERCLASS_H
