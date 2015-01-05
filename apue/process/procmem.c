// =====================================================================================
//
//       Filename:  procmem.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/05/2014 09:29:46 PM
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

int main()
{
    int a = 20;
    int *b = malloc(sizeof(int));
    *b = 40;
    if ( fork() )
    {
        printf("parent: a = %d,     &a = %d\n", a, &a);
        printf("parent: *b = %d,    b = %d\n ", *b, b);
    }
    else
    {
        printf("parent: a = %d,     &a = %d\n", a, &a);
        printf("parent: *b = %d,    b = %d\n ", *b, b);
    }
    return 0;
}
