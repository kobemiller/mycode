// =====================================================================================
//
//       Filename:  alarm.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/06/2014 12:34:54 AM
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

void deal(int s)
{
    printf("fuck you!!!\n");
}

int main()
{
    signal(SIGALRM, deal);
    alarm(5);
    while(1);
    return 0;
}
