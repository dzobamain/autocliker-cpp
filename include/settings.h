#ifndef SETTING_H
#define SETTING_H

#include <string>

struct settings
{
    int number_of_clicks;
    int delay_between_clicks; // ms
    int click_execution_time; // sec
    int time_to_start; // sec
    
    std::string language;
};

void save_settings(const settings& s, const std::string& filename);
settings load_settings(const std::string& filename);

#endif // SETTING_H
