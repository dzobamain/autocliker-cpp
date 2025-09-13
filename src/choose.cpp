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

    while (true)
    {
        clear();
        mvprintw(0, 0, (text + " (press ENTER to confirm):").c_str());

        for (size_t i = 0; i < options.size(); i++)
        {
            if (i == choice)
            {
                attron(A_REVERSE);
                mvprintw(i + 1, 0, options[i].c_str());
                attroff(A_REVERSE);
            }
            else
            {
                mvprintw(i + 1, 0, options[i].c_str());
            }
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
