// =====================================================================================
//
//       Filename:  asynio.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/19/2014 03:45:33 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include <stdio.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

void handle(int sig)
{
    char buf[200];
    int r;
    r = read(0, buf, 199);
    buf[r] = 0;
    printf(":%s", buf);
}
int main()
{
    fcntl(0, F_SETFL, O_ASYNC);
    fcntl(0, F_SETOWN, getpid());
    signal(SIGIO, handle);
    while ( 1 );

    return 0;
}
