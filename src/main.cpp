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

    do
    {
        isActive = autoclikerMenu.menu();
    } while (isActive != -1);

    return -1;
}
