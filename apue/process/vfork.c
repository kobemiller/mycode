// =====================================================================================
//
//       Filename:  vfork.c
//
//    Description:  vfork函数的使用
//
//        Version:  1.0
//        Created:  12/09/2014 08:27:32 PM
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

int globvar = 6;

int main()
{
    int var;
    pid_t pid;

    var = 88;
    printf("before fork\n");
    if ( (pid = fork()) < 0 )
        err_sys("vfork error");
    else if ( pid == 0 )
    {
        globvar++;
        var++;
    //    _exit(0);
    }
    printf("pid = %ld, glob = %d, var = %d\n%d\n", (long)getpid(), globvar, var, pid);
    exit(0);
}
