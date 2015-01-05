// =====================================================================================
//
//       Filename:  atexit.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/05/2014 11:10:44 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include <stdio.h>
#include <stdlib.h>

void fun()
{
    printf("over\n");
}

int main()
{
    atexit(fun);
    printf("processing...\n");
    return 0;
}
