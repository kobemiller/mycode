// =====================================================================================
//
//       Filename:  chatclnt.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/18/2014 10:29:11 AM
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
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <curses.h>

WINDOW *winfo, *wmsg;
int fd;
int r;
struct sockaddr_in dr;

int initSocket();
void initUI();
void destroy();

int main()
{
    fd = initSocket();
    if ( fd == -1 )
        exit(-1);
    printf("网络初始化成功\n");
    initUI();
    if ( fork() )
    {
        //输入，发送 
        char buf[256];
        while ( 1 )
        {
            r = mvwgetstr(wmsg, 1, 1, buf);
            buf[r]= 0;
            send(fd, buf, r, 0);
            //mvwaddstr(wmsg, 1, 1, buf);
            refresh();
            wrefresh(wmsg);
        }
    }
    else
    {
        //接收，显示 
        char buf[256];
        int line = 1;
        while ( 1 )
        {
            r = recv(fd, buf, 255, 0);
            buf[r] = 0;
            mvwaddstr(winfo, line, 1, buf);
            line++;
            if ( line >= (LINES-3) )
            {
                wclear(winfo);
                line = 1;
                box(winfo, 0, 0);
            }
            refresh();
            wrefresh(winfo);
            wmove(wmsg, 1, 1);
        }
    }

    destroy();

    return 0;
}

int initSocket()
{
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if ( fd == -1 )
        return -1;
    dr.sin_family = AF_INET;
    dr.sin_port = htons(9988);
    dr.sin_addr.s_addr = inet_addr("192.168.1.100");
    r = connect(fd, (struct sockaddr*)&dr, sizeof(dr));
    if ( r == -1 )
    {
        close(fd);
        return -1;
    }
    return fd;
}
void initUI()
{
    initscr();
    winfo = derwin(stdscr, (LINES - 3), COLS, 0, 0);
    wmsg = derwin(stdscr, 3, COLS, LINES -2, 0);
    box(winfo, 0, 0);
    box(wmsg, 0, 0);
    refresh();
    wrefresh(winfo);
    wrefresh(wmsg);
}
void destroy()
{
    close(fd);
    endwin();
}
