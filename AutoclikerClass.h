#ifndef AUTOCLIKERCLASS_H
#define AUTOCLIKERCLASS_H

#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <cctype>
#include <ApplicationServices/ApplicationServices.h>

class Autocliker
{
private:
    int _numberOfClicks;
    int _delayBetweenClicks; // ms
    int _clickExecutionTime; // sec
    int _timeToStart; // sec

public:
    Autocliker() : _numberOfClicks(10), _delayBetweenClicks(1000), _clickExecutionTime(10), _timeToStart(5) {} // By default

    void DisplaySettings()
    {
        initscr();
        noecho();
        cbreak();
        keypad(stdscr, TRUE);

        clear();

        printw("Settings:\n");
        printw("Number of clicks: %d\n", _numberOfClicks);
        printw("Delay between clicks: %d ms\n", _delayBetweenClicks);
        printw("Click execution time: %d seconds\n", _clickExecutionTime);
        printw("Time to start: %d seconds\n", _timeToStart);
        printw("\nPress any key to return to the main menu...");

        refresh();

        getch(); 

        endwin(); 
    }

    void ChangeParameters(char positionNumber)
    {
        if (positionNumber != '1' && positionNumber != '2' && positionNumber != '3' && positionNumber != '4')
            return;

        initscr();
        clear();
        noecho();
        char input[10];

        if (positionNumber == '1')
        {
            printw("Enter number of clicks: ");
            getstr(input);
            _numberOfClicks = atoi(input);
        }
        else if (positionNumber == '2')
        {
            printw("Delay between clicks: ");
            getstr(input);
            _delayBetweenClicks = atoi(input);
        }
        else if (positionNumber == '3')
        {
            printw("Click execution time: ");
            getstr(input);
            _clickExecutionTime = atoi(input);
        }
        else if (positionNumber == '4')
        {
            printw("Time to start: ");
            getstr(input);
            _timeToStart = atoi(input);
        }

        refresh();
        endwin();
    }

    void ClickAreaAtCursor()
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

    void Cliker(char positionNumber)
    {
        switch (tolower(positionNumber))
        {
            case '1':
            {
                std::this_thread::sleep_for(std::chrono::seconds(_timeToStart));
                auto startTime = std::chrono::steady_clock::now();
                int temp = _numberOfClicks;

                do
                {
                    if (_numberOfClicks <= 0)
                        break;
                    this->ClickAreaAtCursor(); 
                    std::this_thread::sleep_for(std::chrono::milliseconds(_delayBetweenClicks));

                    _numberOfClicks--;
                    if (_numberOfClicks == 0)
                    {
                        _numberOfClicks = temp;
                        break;
                    }
                } while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - startTime).count() < _clickExecutionTime);
                break;
            }
            case 'q':
                break;
            default:
                break;
        }
    }
};

#endif // AUTOCLIKERCLASS_H