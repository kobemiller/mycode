// =====================================================================================
//
//       Filename:  sig10-6.c
//
//    Description:  在信号处理程序中调用不可再入函数
//
//        Version:  1.0
//        Created:  12/25/2014 09:06:14 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include "../apue.h"
#include "../myerr.h"
#include <pwd.h>
int log_to_stderr = 1;

static void my_alarm(int signo)
{
    struct passwd*  rootptr;
    printf("in signal handler\n");
    if ( (rootptr = getpwnam("root")) == NULL )
        err_sys("getpwnam(root) error");
    alarm(1);
}

int main()
{
    struct passwd*  ptr;
    signal(SIGALRM, my_alarm);
    alarm(1);
    for ( ;; )
    {
        if ( (ptr = getpwnam("km")) == NULL )
            err_sys("getapwnam error");
        if ( strcmp(ptr->pw_name, "km") != 0 )
            printf("return value corrupted, pw_name = %s\n", ptr->pw_name);
    }
    return 0;
}
