#include <iostream>
#include <ncurses.h>
#include <cctype>

#include "choose.h"
#include "AutoclikerMenu.h"
#include "Autocliker.h"

AutoclikerMenu::AutoclikerMenu() : number_of_clicks(10), delay_between_clicks(1000), click_execution_time(10), time_to_start(5) {}

int AutoclikerMenu::menu()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    clear();

    std::vector<std::string> menu_items = {
        "Start clicker",
        "Display settings",
        "Change parameters",
        "Exit..."
    };

    int item = choose(menu_items, "Menu");

    switch (item)
    {
    case 0:
        select_click_mode();
        break;
    case 1:
        display_settings();
        break;
    case 2:
        change_parameters();
        break;
    default:
        return item = -1;
    }

    return item;
}

void AutoclikerMenu::select_click_mode()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    std::vector<std::string> click_menu_items = {
        "Click area at cursor",
        "Back..."
    };

    int item = choose(click_menu_items, "Select click mode");

    switch (item)
    {
        case 0:
            this->autocliker.StartClickingAtCursor(number_of_clicks, delay_between_clicks, click_execution_time, time_to_start);
            break;

        default:
            break;
    }

    endwin();
}

void AutoclikerMenu::display_settings()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    clear();

    printw("Settings:\n");
    printw("Number of clicks: %d\n", number_of_clicks);
    printw("Delay between clicks: %d ms\n", delay_between_clicks);
    printw("Click execution time: %d seconds\n", click_execution_time);
    printw("Time to start: %d seconds\n", time_to_start);
    printw("\nPress any key to return to the main menu...");

    refresh();
    getch();
    endwin();
}

void AutoclikerMenu::change_parameters()
{
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    std::vector<std::string> change_items = {
        "Change number of clicks",
        "Change delay between clicks (ms)",
        "Change click execution time (sec)",
        "Change time to start (sec)"
    };

    int item = choose(change_items, "Select what you want to change");

    if (item >= 0 && item < static_cast<int>(change_items.size()))
    {
        char input[20];
        echo();
        clear();

        int current_value = 0;
        switch (item)
        {
            case 0: current_value = number_of_clicks; break;
            case 1: current_value = delay_between_clicks; break;
            case 2: current_value = click_execution_time; break;
            case 3: current_value = time_to_start; break;
        }

        printw("%s (current: %d): ", change_items[item].c_str(), current_value);
        getstr(input);
        int value = atoi(input);

        switch (item)
        {
            case 0: number_of_clicks = value; break;
            case 1: delay_between_clicks = value; break;
            case 2: click_execution_time = value; break;
            case 3: time_to_start = value; break;
        }

        noecho();
    }

    endwin();
}
