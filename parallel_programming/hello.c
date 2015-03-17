// =====================================================================================
//
//       Filename:  hello.c
//
//    Description:  并行编程
//
//        Version:  1.0
//        Created:  2015年03月13日 16时30分02秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include <stdio.h>
#include <omp.h>

int main()
{
    printf("start:\n");
#pragma omp parallel
    {
        int i;
        printf("hello.\n");
        for ( i = 1; i <= 3; i++ )
            printf("%d\n", i);
    }
    printf("end\n");
    return 0;
}
