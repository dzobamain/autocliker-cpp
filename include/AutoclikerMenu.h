#ifndef AUTOCLIKERMENU_H
#define AUTOCLIKERMENU_H

#include <map>
#include "Autocliker.h"
#include "settings.h"

class AutoclikerMenu
{
private:
    Autocliker autocliker;
    settings set;
    std::map<std::string, std::string> lang;
    
public:
    AutoclikerMenu(const settings& s, const std::map<std::string, std::string>& lang);

    int menu();
    void select_click_mode();
    void display_settings();
    void change_parameters();
    void change_language();
};

#endif // AUTOCLIKERMENU_H