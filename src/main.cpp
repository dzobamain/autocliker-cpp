/*
 *  main.cpp
 */

#include <choose.h>
#include <AutoclikerMenu.h>

int main()
{
    setlocale(LC_ALL, "");

    int isActive;
    AutoclikerMenu autoclikerMenu;

    //std::vector<std::string> languages = {"English (en)", "Українська (ua)"};
    //int lang = choose(languages, "Select language");

    do
    {
        isActive = autoclikerMenu.menu();
    } while (isActive != -1);

    return -1;
}
