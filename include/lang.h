#ifndef LANG_H
#define LANG_H

#include <map>
#include <string>

struct language_info 
{
    std::string file;
    std::string name;
};

static const std::map<std::string, language_info> languages = {
    {"en", {"language/lang_en.cfg", "English"}},
    {"ua", {"language/lang_ua.cfg", "Українська"}}
};

std::map<std::string, std::string> load_language(const std::string& filename);
std::string get_language_file(const std::string& lang_code);

#endif // LANG_H
