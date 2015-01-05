// =====================================================================================
//
//       Filename:  wait.c
//
//    Description:  i
//
//        Version:  1.0
//        Created:  12/09/2014 10:36:20 AM
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
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <sched.h>

int idx = 0;
int fddata;
void handle(int sig)
{
    int status;
    if ( sig == SIGCHLD )
    {
        wait(&status);
        idx++;
        if ( idx == 2 )
        {
            close(fddata);
            printf("mission complete!\n");
            exit(-1);
        }
    }
}
int isprimer(int ta)
{
    int i = 2;
    for ( ; i < ta; i++ )
    {
        if ( ta % i == 0 )
            return 0;
    }
    return 1;
}

int main()
{
    int a, b;
    int id = 1;
    int fd[2];
    signal(SIGCHLD, handle);
    pipe(fd);
    while ( 1 )
    {
        if ( id == 1 )
            a = 2, b = 50000;
        if ( id == 2 )
            a = 50001, b = 100000;
        if ( fork() )
        {
            id++;
            if ( id > 2 )
                break;
            continue;
        }
        else
        {
            int i;
            close(fd[0]);
            for ( i = a; i <= b; i++ )
            {
                if ( isprimer(i) )
                    write(fd[1], &i, sizeof(int));
                sched_yield();
            }
            printf("%d mission complete!\n", getpid());
            exit(0);
        }
    }
    int re;
    char buf[20];
    close(fd[1]);
    fddata = open("result.txt", O_RDWR|O_CREAT, 0666);
    while ( 1 )
    {
        read(fd[0], &re, sizeof(int));
        sprintf(buf, "%d\n", re);
        write(fddata, buf, strlen(buf));
        sched_yield();
    }
    return 0;
}
