#ifndef AUTOCLIKERMENU_H
#define AUTOCLIKERMENU_H

#include <iostream>
#include <ncurses.h>

char AutoclikerMenu()
{
    initscr(); // Ініціалізація ncurses / Initialize ncurses
    noecho(); // Вимкнення автоматичного виводу клавіш / Disable automatic echoing of typed characters
    cbreak(); // Мгновенне прийняття введення з клавіатури / Make terminal input available immediately
    keypad(stdscr, TRUE); // Увімкнення роботи з функціональними клавішами / Enable reading of function keys

    clear(); // Очищення екрану перед виведенням нового меню / Clear screen before displaying new menu
    printw("Menu:\n");
    printw("1. Start clicker\n");
    printw("2. Display settings\n");
    printw("3. Change number of clicks\n");
    printw("4. Change delay between clicks\n");
    printw("5. Change click execution time\n");
    printw("6. Change time to start\n");
    printw("Press 'q' key to exit...");

    char menuKey;
    do
    {
        menuKey = getch(); // Очікування введення користувача / Wait for user input

        if (menuKey == '1' || menuKey == '2' || menuKey == '3' || menuKey == '4' || menuKey == '5' || menuKey == '6')
        {
            endwin(); // Завершення роботи ncurses / End ncurses mode
            std::cout << "Your choice: " << menuKey << std::endl;
            return menuKey;
        }
        else if (menuKey == 'q' || menuKey == 'Q')
        {
            endwin(); // Завершення роботи ncurses / End ncurses mode
            return menuKey;
        }
    } while (true);
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
    do
    {
        menuKey = getch(); 

        if (menuKey == '1')
        {
            endwin(); 
            std::cout << "Your choice click mode: " << menuKey << std::endl;
            return menuKey;
        }
        else if (menuKey == 'q' || menuKey == 'Q')
        {
            endwin();
            return '\0';
        }
    } while (true);
}

#endif // AUTOCLIKERMENU_H