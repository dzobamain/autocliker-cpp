#include "autoclikerMenu.h"
#include "autoclikerClass.h"

#include <iostream>
#include <ncurses.h>
#include <cctype>

char AutoclikerMenu()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    clear();
    printw("Menu:\n");
    printw("1. Start clicker\n");
    printw("2. Display settings\n");
    printw("3. Change number of clicks\n");
    printw("4. Change delay between clicks\n");
    printw("5. Change click execution time\n");
    printw("6. Change time to start\n");
    printw("Press 'q' key to exit...");

    char menuKey;
    do {
        menuKey = getch();

        switch (menuKey) {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6': {
            endwin();
            std::cout << "Your choice: " << menuKey << std::endl;
            return menuKey;
        }
        case 'q':
        case 'Q': {
            endwin();
            return menuKey;
        }
        default:
            break;
        }
    } while (true);
}

bool SetMenuMode(Autocliker autocliker, bool isActive)
{
    char positioNumber = AutoclikerMenu();

    switch (positioNumber)
    {
        case '1':
        {
            char positioClickMode = SetClickMode();
            autocliker.Cliker(positioClickMode);
            break;
        }
        case '2':
            autocliker.DisplaySettings();
            break;
        case '3':
            autocliker.ChangeParameters('1');
            break;
        case '4':
            autocliker.ChangeParameters('2');
            break;
        case '5':
            autocliker.ChangeParameters('3');
            break;
        case '6':
            autocliker.ChangeParameters('4');
            break;
        case 'q':
        case 'Q':
            return isActive = false;
        default:
            break;
    }

    return true;
}

char SetClickMode()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    clear();
    printw("Menu:\n");
    printw("1. Click area at cursor\n");
    printw("Press 'q' key to back...");

    char menuKey;
    do {
        menuKey = getch();

        if (menuKey == '1') {
            endwin();
            std::cout << "Your choice click mode: " << menuKey << std::endl;
            return menuKey;
        }
        else if (tolower(menuKey) == 'q') {
            endwin();
            return '\0';
        }
    } while (true);
}