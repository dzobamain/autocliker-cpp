#ifndef AUTOCLIKER_H
#define AUTOCLIKER_H

class Autocliker
{
public:
    void StartClickingAtCursor(int number_of_clicks, const int &delay_between_clicks, const int &click_execution_time, const int &time_to_start);
    void ClickAreaAtCursor();
};

#endif // AUTOCLIKER_H