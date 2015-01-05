// =====================================================================================
//
//       Filename:  twofork.c
//
//    Description:  fork两次以避免僵死进程
//
//        Version:  1.0
//        Created:  12/10/2014 05:14:56 PM
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

#include <sys/wait.h>

int main()
{
    pid_t pid;
    if ( (pid = fork()) < 0 )
        err_sys("fork error");
    else if ( pid == 0 )
    {
        if ( (pid = fork()) < 0 )
            err_sys("fork error");
        else if ( pid > 0 )
            exit(0);
        sleep(2);
        printf("second child, parent pid = %ld\n", (long)getppid());
        exit(0);
    }

    //if ( waitpid(pid, NULL, 0) != pid )
    //    err_sys("waitpid error");
    exit(0);
}
