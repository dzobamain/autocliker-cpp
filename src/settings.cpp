#include <string>
#include <fstream>

#include <settings.h>

void save_settings(const settings& set, const std::string& filename)
{
    std::ofstream out(filename);
    if (!out) return;

    out << set.number_of_clicks << "\n";
    out << set.delay_between_clicks << "\n";
    out << set.click_execution_time << "\n";
    out << set.time_to_start << "\n";
    out << set.language << "\n";
}

settings load_settings(const std::string& filename)
{
    settings set{10, 1000, 10, 5, "en"};

    std::ifstream in(filename);
    if (!in) return set;

    in >> set.number_of_clicks;
    in >> set.delay_between_clicks;
    in >> set.click_execution_time;
    in >> set.time_to_start;
    in >> set.language;

    return set;
}
