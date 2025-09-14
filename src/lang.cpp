#include <fstream>
#include <sstream>
#include <map>
#include <string>

#include <lang.h>

std::map<std::string, std::string> load_language(const std::string& filename)
{
    std::map<std::string, std::string> lang;
    std::ifstream file(filename);
    if (!file.is_open())
        return lang;

    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#')
            continue;

        auto pos = line.find('=');
        if (pos == std::string::npos)
            continue;

        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);

        key.erase(0, key.find_first_not_of(" \t"));
        key.erase(key.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);

        lang[key] = value;
    }

    return lang;
}

std::string get_language_file(const std::string& lang_code)
{
    auto it = languages.find(lang_code);
    if (it != languages.end())
        return it->second.file;

    return "language/lang_en.cfg"; // default fallback
}


