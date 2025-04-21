#include "autoclikerClass.h"

#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <cctype>

// Default
Autocliker::Autocliker() : _numberOfClicks(10), _delayBetweenClicks(1000), _clickExecutionTime(10), _timeToStart(5) {}

void Autocliker::DisplaySettings() 
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

void Autocliker::ChangeParameters(char positionNumber) 
{
    initscr();
    clear();
    noecho();

    char input[10];

    switch (positionNumber) {
        case '1':
            printw("Enter number of clicks: ");
            getstr(input);
            _numberOfClicks = atoi(input);
            break;
        case '2':
            printw("Delay between clicks: ");
            getstr(input);
            _delayBetweenClicks = atoi(input);
            break;
        case '3':
            printw("Click execution time: ");
            getstr(input);
            _clickExecutionTime = atoi(input);
            break;
        case '4':
            printw("Time to start: ");
            getstr(input);
            _timeToStart = atoi(input);
            break;
        default:
            break;
    }

    refresh();
    endwin();
}

#ifdef WIN32
#include <windows.h>

void Autocliker::ClickAreaAtCursor() 
{
    POINT p;
    if (GetCursorPos(&p)) {
        mouse_event(MOUSEEVENTF_LEFTDOWN, p.x, p.y, 0, 0);

        mouse_event(MOUSEEVENTF_LEFTUP, p.x, p.y, 0, 0);
    }
}

#else
#include <ApplicationServices/ApplicationServices.h>

void Autocliker::ClickAreaAtCursor() 
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

#endif

void Autocliker::Cliker(char positionNumber) 
{
    switch (tolower(positionNumber)) {
        case '1': {
            std::this_thread::sleep_for(std::chrono::seconds(_timeToStart));
            auto startTime = std::chrono::steady_clock::now();
            int temp = _numberOfClicks;

            do {
                if (_numberOfClicks <= 0)
                    break;
                this->ClickAreaAtCursor();
                std::this_thread::sleep_for(std::chrono::milliseconds(_delayBetweenClicks));

                _numberOfClicks--;
                if (_numberOfClicks == 0) {
                    _numberOfClicks = temp;
                    break;
                }
            } while (std::chrono::duration_cast<std::chrono::seconds>(
                         std::chrono::steady_clock::now() - startTime)
                         .count() < _clickExecutionTime);
            break;
        }
        case 'q':
            break;
        default:
            break;
    }
}
