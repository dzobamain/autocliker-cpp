#ifndef AUTOCLIKERCLASS_H
#define AUTOCLIKERCLASS_H

#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <ApplicationServices/ApplicationServices.h> // для ClickAreaAtCursor / for ClickAreaAtCursor

class Autocliker
{
private:
    int _numberOfClicks; // кількість кліків / number of clicks
    int _delayBetweenClicks; // затримка між кліками (мс) / delay between clicks (ms)
    int _clickExecutionTime; // час виконання кліків (секунди) / click execution time (seconds)
    int _timeToStart; // час до запуску (sec) / time to start (sec)

        public : Autocliker() : _numberOfClicks(100), _delayBetweenClicks(100), _clickExecutionTime(10)
    {
    }

    void DisplaySettings()
    {
        std::cout << "Number of clicks = " << _numberOfClicks << "\n";
        std::cout << "Delay between clicks = " << _delayBetweenClicks << " ms\n";
        std::cout << "Click execution time = " << _clickExecutionTime << " seconds\n";
        std::cout << "Time to start = " << _timeToStart << " seconds\n";
    }

    void ChangeParameters(char positioNumber)
    {
        if (positioNumber != '1' && positioNumber != '2' && positioNumber != '3' && positioNumber != '4')
            return;

        initscr();
        clear();
        noecho(); // Вимикаємо автоматичне відображення введених символів / Disable automatic echoing of typed characters
        char input[10];

        if (positioNumber == '1')
        {
            printw("Enter number of clicks: ");
            getstr(input);
            _numberOfClicks = atoi(input);
        }
        else if (positioNumber == '2')
        {
            printw("Delay between clicks: ");
            getstr(input);
            _delayBetweenClicks = atoi(input);
        }
        else if (positioNumber == '3')
        {
            printw("Click execution time: ");
            ;
            getstr(input);
            _clickExecutionTime = atoi(input);
        }
        else if (positioNumber == '4')
        {
            printw("Click execution time: ");
            ;
            getstr(input);
            _timeToStart = atoi(input);
        }

        refresh(); // Оновлення екрану / Update the screen
        endwin();  // Завершення роботи ncurses / End ncurses mode
    }

    void ClickAreaAtCursor() // взято з / Taken from https://github.com/MataiMoorfield/Auto-clicker
    {
        CGEventRef ourEvent = CGEventCreate(NULL);
        CGPoint point = CGEventGetLocation(ourEvent);
        CFRelease(ourEvent);

        CGEventRef click_down = CGEventCreateMouseEvent(
            NULL, kCGEventLeftMouseDown,
            point,
            kCGMouseButtonLeft);
        CGEventRef click_up = CGEventCreateMouseEvent(
            NULL, kCGEventLeftMouseUp,
            point,
            kCGMouseButtonLeft);

        CGEventPost(kCGHIDEventTap, click_down);
        CGEventPost(kCGHIDEventTap, click_up);

        CFRelease(click_down);
        CFRelease(click_up);
    }
};

#endif // AUTOCLIKERCLASS_H
