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
    int _numberOfClicks;     // кількість кліків / number of clicks
    int _delayBetweenClicks; // затримка між кліками (мс) / delay between clicks (ms)
    int _clickExecutionTime; // час виконання кліків (секунди) / click execution time (seconds)
    int _timeToStart;        // час до запуску (sec) / time to start (sec)

public:
    Autocliker() : _numberOfClicks(10), _delayBetweenClicks(1000), _clickExecutionTime(10), _timeToStart(5) {}

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

    void Cliker(char positioNumber)
    {
        switch (positioNumber)
        {
        case '1':
        {
            std::this_thread::sleep_for(std::chrono::seconds(_timeToStart)); // час до запуску / Time to start
            auto startTime = std::chrono::steady_clock::now();
            int temp = _numberOfClicks; // збереження даних / Save date

            do
            {
                if (_numberOfClicks == 0) break;
                this->ClickAreaAtCursor(); // кліки на курсор / click area at cursor
                std::this_thread::sleep_for(std::chrono::milliseconds(_delayBetweenClicks)); // затримка між клаками / Delay between clicks

                // якщо кліків вказано менше ніж часу програма закінчится раніше часу / If the number of clicks specified is less than the execution time, the program will finish earlier than the specified time
                _numberOfClicks--;
                if (_numberOfClicks <= 0)
                {
                    _numberOfClicks = temp;
                    break;
                }
            } while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - startTime).count() < _clickExecutionTime); // таймер виконання / Execution timer
        }
        case 'q':
        case 'Q':
            break;
        default:
            break;
        }
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
