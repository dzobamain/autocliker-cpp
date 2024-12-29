#include <iostream>
#include <ncurses.h>
#include <thread>
#include <chrono>

char AutoclikerMenu()
{
    initscr(); // Ініціалізація ncurses / Initialize ncurses
    noecho(); // Вимкнення автоматичного виводу клавіш / Disable automatic echoing of typed characters
    cbreak(); // Мгновенне прийняття введення з клавіатури / Make terminal input available immediately
    keypad(stdscr, TRUE); // Увімкнення роботи з функціональними клавішами / Enable reading of function keys

    clear(); // Очищення екрану перед виведенням нового меню / Clear screen before displaying new menu
    printw("Menu:\n");
    printw("1. Change number of clicks\n");
    printw("2. Change delay between clicks\n");
    printw("3. Change click execution time\n");
    printw("4. Change click area\n");
    printw("5. Start clicker\n\n");
    printw("Press 'q' key to exit...");

    char menuKey;
    do
    {
        menuKey = getch(); // Очікування введення користувача / Wait for user input

        if (menuKey == '1' || menuKey == '2' || menuKey == '3' || menuKey == '4' || menuKey == '5')
        {
            endwin(); // Завершення роботи ncurses / End ncurses mode
            std::cout << "Your choice: " << menuKey;
            return menuKey; // Повернення вибору користувача / Return user choice
        }
        else if (menuKey == 'q')
        {
            endwin(); // Завершення роботи ncurses / End ncurses mode
            std::cout << "The program has ended";
            return '\0';
        }
    } while (true);
}