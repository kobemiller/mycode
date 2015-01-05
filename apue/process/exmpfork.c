// =====================================================================================
//
//       Filename:  exmpfork.c
//
//    Description:  fork函数实例
//
//        Version:  1.0
//        Created:  12/09/2014 07:47:44 PM
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
char buf[] = "a write to stdout\n";

int main()
{
    int var;
    pid_t pid;

    var = 88;
    if ( write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1 )
        err_sys("write error");
    printf("before fork\n");
    fflush(stdout);

    if ( (pid = fork()) < 0 )
        err_sys("fork error");
    else if ( pid == 0 )
    {
        int i;
        globvar++;
        var++;
        for ( i = 0; i < 50; i++ )
        {
            printf("***\n");
            sleep(1);
        }
    }
    else
        //sleep(2);
        return 0;
    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

    exit(0);
}
