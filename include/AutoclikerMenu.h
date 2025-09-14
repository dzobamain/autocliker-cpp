#ifndef AUTOCLIKERMENU_H
#define AUTOCLIKERMENU_H

#include "Autocliker.h"
#include "settings.h"

class AutoclikerMenu
{
private:
    Autocliker autocliker;
    settings set;
    
public:
    AutoclikerMenu();
    
    int menu();
    void select_click_mode();
    void display_settings();
    void change_parameters();
    void change_language();
};

#endif // AUTOCLIKERMENU_H