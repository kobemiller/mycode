#include <curses.h>

int main()
{
    initscr();
    if ( has_colors() == TRUE )
    {
        start_color();
        init_pair(1, COLOR_RED, COLOR_WHITE);
        init_pair(2, COLOR_BLUE, COLOR_GREEN);
    }
    box(stdscr, 0, 0);
    
    mvaddch(2, 10, 'A'|A_BOLD);
    mvaddch(2, 20, ACS_PI|COLOR_PAIR(1));
    mvaddch(2, 21, ACS_PI|COLOR_PAIR(2));
    mvaddstr(3, 10, "hello 靓仔!");
    attron(COLOR_PAIR(1));
    mvaddstr(4, 10, "hello 靓仔!");
    attroff(COLOR_PAIR(2));

    getch();
    endwin();
    return 0;
}
