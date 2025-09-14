/*
 *  main.cpp
 */

#include <config.h>
#include <choose.h>
#include <lang.h>
#include <AutoclikerMenu.h>

#include <iostream>

int main()
{
    setlocale(LC_ALL, "");

    int isActive;
    settings set = load_settings(config::SETTINGS_FILE);
    std::map<std::string, std::string> lang = load_language(get_language_file(set.language));
    AutoclikerMenu autoclikerMenu(set, lang);

    do
    {
        isActive = autoclikerMenu.menu();
    } while (isActive != -1);

    return -1;
}
