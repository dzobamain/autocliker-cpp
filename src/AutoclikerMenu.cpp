#include <ncurses.h>
#include <vector>
#include <string>

#include <choose.h>
#include <settings.h>
#include <AutoclikerMenu.h>
#include <Autocliker.h>
#include <config.h>
#include <lang.h>

AutoclikerMenu::AutoclikerMenu(const settings& s, const std::map<std::string, std::string>& lang)
    : set{s}, lang(lang) {}

int AutoclikerMenu::menu()
{
    
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    clear();

    std::vector<std::string> menu_items = {
        lang.at("MENU_OPTION_START"),
        lang.at("MENU_OPTION_DISPLAY"),
        lang.at("MENU_OPTION_CHANGE"),
        lang.at("MENU_OPTION_EXIT")
    };

    int item = choose(menu_items, lang.at("MENU_TITLE"));

    switch (item)
    {
    case 0: select_click_mode(); break;
    case 1: display_settings(); break;
    case 2: change_parameters(); break;
    default: return -1;
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
        lang.at("CLICK_MODE_CURSOR"),
        lang.at("CLICK_MODE_BACK")
    };

    int item = choose(click_menu_items, lang.at("CLICK_MODE_TITLE"));

    if (item == 0)
    {
        autocliker.StartClickingAtCursor(
            set.number_of_clicks,
            set.delay_between_clicks,
            set.click_execution_time,
            set.time_to_start
        );
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
        lang.at("SETTINGS_BACK")
    };

    char buffer[512];
    snprintf(buffer, sizeof(buffer),
        "%s\n"
        "%s\n"
        "%s\n"
        "%s\n"
        "%s\n"
        "%s",
        lang.at("SETTINGS_TITLE").c_str(),
        (lang.at("SETTINGS_NUMBER") + "\n").c_str(),
        (lang.at("SETTINGS_DELAY") + "\n").c_str(),
        (lang.at("SETTINGS_EXEC_TIME") + "\n").c_str(),
        (lang.at("SETTINGS_START_TIME") + "\n").c_str(),
        (lang.at("SETTINGS_LANGUAGE") + "\n").c_str()
    );

    // Формуємо з форматами
    std::string settings_text = lang.at("SETTINGS_TITLE") + "\n" +
        (lang.at("SETTINGS_NUMBER").find("%d") != std::string::npos ? 
            (lang.at("SETTINGS_NUMBER").substr(0, lang.at("SETTINGS_NUMBER").find("%d")) + std::to_string(set.number_of_clicks)) : lang.at("SETTINGS_NUMBER")) + "\n" +
        (lang.at("SETTINGS_DELAY").substr(0, lang.at("SETTINGS_DELAY").find("%d")) + std::to_string(set.delay_between_clicks) + " ms\n") +
        (lang.at("SETTINGS_EXEC_TIME").substr(0, lang.at("SETTINGS_EXEC_TIME").find("%d")) + std::to_string(set.click_execution_time) + " seconds\n") +
        (lang.at("SETTINGS_START_TIME").substr(0, lang.at("SETTINGS_START_TIME").find("%d")) + std::to_string(set.time_to_start) + " seconds\n") +
        (lang.at("SETTINGS_LANGUAGE").substr(0, lang.at("SETTINGS_LANGUAGE").find("%s")) + set.language);

    choose(display_set_items, settings_text);

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
        lang.at("CHANGE_NUMBER"),
        lang.at("CHANGE_DELAY"),
        lang.at("CHANGE_EXEC_TIME"),
        lang.at("CHANGE_START_TIME"),
        lang.at("CHANGE_LANGUAGE"),
        lang.at("CHANGE_BACK")
    };

    int item = choose(change_items, lang.at("CHANGE_TITLE"));

    if (item >= 0 && item < static_cast<int>(change_items.size()))
    {
        char input[20];
        echo();
        clear();

        switch (item)
        {
            case 0:
                printw(lang.at("CHANGE_INPUT").c_str(), change_items[item].c_str(), set.number_of_clicks);
                getstr(input);
                set.number_of_clicks = atoi(input);
                break;
            case 1:
                printw(lang.at("CHANGE_INPUT").c_str(), change_items[item].c_str(), set.delay_between_clicks);
                getstr(input);
                set.delay_between_clicks = atoi(input);
                break;
            case 2:
                printw(lang.at("CHANGE_INPUT").c_str(), change_items[item].c_str(), set.click_execution_time);
                getstr(input);
                set.click_execution_time = atoi(input);
                break;
            case 3:
                printw(lang.at("CHANGE_INPUT").c_str(), change_items[item].c_str(), set.time_to_start);
                getstr(input);
                set.time_to_start = atoi(input);
                break;
            case 4:
                endwin();
                change_language();
                return;
            default: break;
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

    std::vector<std::string> language_menu;
    for (const auto& [code, info] : ::languages) {
        language_menu.push_back(info.name + " (" + code + ")");
    }

    int lang_item = choose(language_menu, lang.at("LANG_SELECT_TITLE"));


    switch (lang_item)
    {
        case 0: set.language = "en"; break;
        case 1: set.language = "ua"; break;
        default: break;
    }

    lang = load_language(get_language_file(set.language));

    save_settings(set, config::SETTINGS_FILE);

    endwin();
}
