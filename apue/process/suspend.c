// =====================================================================================
//
//       Filename:  suspend.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/08/2014 08:00:57 PM
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

void handle(int sig)
{
    printf("外部中断处理中...\n");
    sleep(3);
    printf("外部中断处理完毕\n");
}

int main()
{
    int sum = 0;
    int i;
    sigset_t sigs, sigt, sigu;
    sigemptyset(&sigs);
    sigemptyset(&sigt);
    sigemptyset(&sigu);

    sigaddset(&sigs, SIGINT);
    signal(SIGINT, handle);

    sigprocmask(SIG_BLOCK, &sigs, 0);
    for ( i = 0; i < 10; i++ )
    {
        printf("正在拷贝电影<%d>\n", i);
        sleep(5);
        printf("拷贝电影<%d>\n", i);
        sigpending(&sigu);
        if ( sigismember(&sigu, SIGINT) )
            sigsuspend(&sigt);
    }
    printf("所有电影拷贝完毕\n");
    sigprocmask(SIG_UNBLOCK, &sigs, 0);
    printf("over!\n");

    return 0;
}
