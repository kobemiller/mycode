// =====================================================================================
//
//       Filename:  guerzu.c
//
//    Description:  创建一个孤儿进城组
//
//        Version:  1.0
//        Created:  12/24/2014 10:27:34 AM
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

static void sig_hup(int signo)
{
    printf("SIGHUP received, pid = %ld\n", (long)getpid());
}

static void pr_ids(char *name)
{
    printf("%s:pid = %ld, ppid = %ld, pgrp = %ld, tpgrp = %ld\n",
            name, (long)getpid(), (long)getppid(), (long)getpgrp(), (long)tcgetpgrp(STDIN_FILENO));
    fflush(stdout);
}

int main()
{
    char    c;
    pid_t   pid;

    pr_ids("parent");
    if ( (pid = fork()) < 0 )
        err_sys("fork error");
    else if ( pid > 0 )
        sleep(5);
    else 
    {
        pr_ids("child");
        signal(SIGHUP, sig_hup);
        kill(getpid(), SIGTSTP);
        pr_ids("child");
        if ( read(STDIN_FILENO, &c, 1) != 1 )
            printf("read error %d on controlling TTY\n", errno);
    }
    return 0;
}
