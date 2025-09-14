#include <ncurses.h>
#include <vector>
#include <string>

#include <choose.h>

int choose(const std::vector<std::string> &options, const std::string &text)
{
    int choice = 0;
    int key;

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    std::vector<std::string> text_lines;
    size_t pos = 0, prev = 0;
    while ((pos = text.find('\n', prev)) != std::string::npos)
    {
        text_lines.push_back(text.substr(prev, pos - prev));
        prev = pos + 1;
    }
    text_lines.push_back(text.substr(prev));

    while (true)
    {
        clear();

        for (size_t i = 0; i < text_lines.size(); ++i)
        {
            mvprintw(i, 0, text_lines[i].c_str());
        }

        for (size_t i = 0; i < options.size(); ++i)
        {
            if (i == choice)
                attron(A_REVERSE);

            mvprintw(text_lines.size() + i, 0, options[i].c_str());

            if (i == choice)
                attroff(A_REVERSE);
        }

        key = getch();

        switch (key)
        {
        case KEY_UP:
            choice = (choice == 0) ? options.size() - 1 : choice - 1;
            break;
        case KEY_DOWN:
            choice = (choice == options.size() - 1) ? 0 : choice + 1;
            break;
        case 10: // Enter
            endwin();
            return choice;
        }
    }
}
