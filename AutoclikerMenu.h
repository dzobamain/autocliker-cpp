#ifndef AUTOCLIKERMENU_H
#define AUTOCLIKERMENU_H

#include "autoclikerClass.h"
#include <iostream>
#include <ncurses.h>
#include <cctype>

char AutoclikerMenu();
char SetClickMode();
bool SetMenuMode(Autocliker autocliker, bool isActive);

#endif // AUTOCLIKERMENU_H