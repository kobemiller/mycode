// =====================================================================================
//
//       Filename:  select.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/19/2014 04:40:20 PM
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
#include <sys/select.h>

int main()
{
    fd_set fds;
    int r;
    char buf[100];
    while ( 1 )
    {
        FD_ZERO(&fds);
        FD_SET(0, &fds);
        r = select(1, &fds, 0, 0, 0);
        printf("有数据输入\n");
        r = read(0, buf, 99);

    }
    return 0;
}

