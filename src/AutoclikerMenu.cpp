#include <ncurses.h>
#include <vector>
#include <string>

#include <choose.h>
#include <settings.h>
#include <AutoclikerMenu.h>
#include <Autocliker.h>
#include <config.h>

AutoclikerMenu::AutoclikerMenu() 
{
    set = load_settings(config::SETTINGS_FILE);
}

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

    int item = choose(menu_items, "Menu:");

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

    int item = choose(click_menu_items, "Select click mode:");

    switch (item)
    {
        case 0:
            this->autocliker.StartClickingAtCursor(set.number_of_clicks, set.delay_between_clicks, set.click_execution_time, set.time_to_start);
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

    std::vector<std::string> display_set_items = {
        "Back..."
    };

    std::string settings_text = 
        "Settings:\n"
        "Number of clicks: " + std::to_string(set.number_of_clicks) + "\n"
        "Delay between clicks: " + std::to_string(set.delay_between_clicks) + " ms\n"
        "Click execution time: " + std::to_string(set.click_execution_time) + " seconds\n"
        "Time to start: " + std::to_string(set.time_to_start) + " seconds\n"
        "Language: " + set.language;

    int item = choose(display_set_items, settings_text);

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
        "Change time to start (sec)",
        "Change language",
        "Back..."
    };

    int item = choose(change_items, "Select what you want to change:");

    if (item >= 0 && item < static_cast<int>(change_items.size()))
    {
        char input[20];
        echo();
        clear();

        switch (item)
        {
            case 0:
            {
                printw("%s (current: %d): ", change_items[item].c_str(), set.number_of_clicks);
                getstr(input);
                set.number_of_clicks = atoi(input);
                break;
            }
            case 1:
            {
                printw("%s (current: %d): ", change_items[item].c_str(), set.delay_between_clicks);
                getstr(input);
                set.delay_between_clicks = atoi(input);
                break;
            }
            case 2:
            {
                printw("%s (current: %d): ", change_items[item].c_str(), set.click_execution_time);
                getstr(input);
                set.click_execution_time = atoi(input);
                break;
            }
            case 3:
            {
                printw("%s (current: %d): ", change_items[item].c_str(), set.time_to_start);
                getstr(input);
                set.time_to_start = atoi(input);
                break;
            }
            case 4:
            {
                endwin();
                change_language();
                return;
            }
            default:
                break;
        }

        save_settings(set, config::SETTINGS_FILE);
        noecho();
    }

    endwin();
}

void AutoclikerMenu::change_language()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    clear();

    std::vector<std::string> languages = {
        "English (en)",
        "Українська (ua)"
    };

    int lang_item = choose(languages, "Select language:");

    switch (lang_item)
    {
        case 0: set.language = "en"; break;
        case 1: set.language = "ua"; break;
        default: break;
    }

    save_settings(set, config::SETTINGS_FILE);

    endwin();
}

