// =====================================================================================
//
//       Filename:  system.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/05/2014 03:51:23 PM
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
#include <sys/wait.h>

int main()
{
    int r;
    printf("%d\n", getpid());
    r = system("ls -l home");
    printf("%d\n", r);              //错误的输出system返回值
    printf("%d\n", r>>8 & 255);     //正确的输出1
    printf("%d\n", WEXITSTATUS(r)); //正确的输出2

    return 0;
}
