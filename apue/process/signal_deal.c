// =====================================================================================
//
//       Filename:  signal_deal.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/06/2014 12:12:02 AM
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
    printf("我是信号：%d\n", sig);
}

int main()
{
    signal(SIGINT, handle);

    while ( 1 )
    {
        printf("进程在执行\n");
        sleep(1);
    }
    return 0;
}
