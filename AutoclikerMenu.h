#ifndef AUTOCLIKERMENU_H
#define AUTOCLIKERMENU_H

#include "Autocliker.h"

class AutoclikerMenu
{
private:
    Autocliker autocliker;

    int number_of_clicks;
    int delay_between_clicks; // ms
    int click_execution_time; // sec
    int time_to_start; // sec

public:
    AutoclikerMenu();
    int menu();
    void select_click_mode();
    void display_settings();
    void change_parameters();
};

/*
bool SetMenuMode(Autocliker autocliker, bool isActive);
*/

#endif // AUTOCLIKERMENU_H