// =====================================================================================
//
//       Filename:  sig10-3.c
//
//    Description:  捕捉SIGUSR1和SIGUSR2的简单程序
//
//        Version:  1.0
//        Created:  12/24/2014 11:27:55 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include "../apue.h"
#include "../myerr.h"
int log_to_stderr = 1;

static void sig_usr(int);

int main()
{
    if ( signal(SIGUSR1, sig_usr) == SIG_ERR )
        err_sys("can't catch SIGUSR1");
    if ( signal(SIGUSR2, sig_usr) == SIG_ERR )
        err_sys("can't catch SIGUSR2");
    for ( ;; )
        pause();
    return 0;
}

static void sig_usr(int signo)
{
    if ( signo == SIGUSR1 )
        printf("received SIGUSR1\n");
    else if( signo == SIGUSR2 )
        printf("received SIGUSR2\n");
    else
        err_dump("received signal %d\n", signo);
}
