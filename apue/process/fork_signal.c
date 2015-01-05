// =====================================================================================
//
//       Filename:  fork_signal.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/08/2014 04:53:51 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <math.h>
#include <curses.h>

WINDOW *w;
int num;
int isstop = 0;
void handle(int sig)
{
    if ( sig == SIGUSR1 )
        if ( isstop == 1 )
            isstop = 0;
        else
            isstop = 1;
}

int main()
{
    initscr();
    curs_set(0);
    noecho();
    w = derwin(stdscr, 3, 11, (LINES - 3)/2, (COLS - 11)/2);
    box(w, 0, 0);
    refresh();
    wrefresh(w);
    if ( fork() )
    {
        signal(SIGUSR1, handle);
        while ( 1 )
        {
            if ( isstop == 1 )
                pause();
            num = rand() % 1000000;
            mvwprintw(w, 1, 2, "%07d", num);
            refresh();
            wrefresh(w);
            usleep(10000);
        }
    }
    else
        while ( 1 )
        {
            getch();
            kill(getppid(), SIGUSR1);
        }
    endwin();

    return 0;
}
