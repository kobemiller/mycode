// =====================================================================================
//
//       Filename:  array_test.cpp
//
//    Description:  array.h测试程序 
//
//        Version:  1.0
//        Created:  2015年03月04日 23时40分47秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

typedef int ElemType;

#include "../ds.h"
#include "array.h"

int main()
{
    Array   A;
    int     i, j, k, *p, dim = 3, bound1 = 3, bound2 = 4, bound3 = 2;
    ElemType e, *p1;

    InitArray(A, dim, bound1, bound2, bound3);
    p = A.bounds;
    printf("A.bounds = ");
    for ( i = 0; i < dim; i++ )
        printf("%d ", *(p+i));
    p = A.constants;
    printf("\nA.constants = ");
    for ( i = 0; i < dim; i++ )
        printf("%d ", *(p+i));
    printf("\n%d页%d行%d列矩阵元素如下：\n", bound1, bound2, bound3);
    for ( i = 0; i < bound1; i++ )
    {
        for ( j = 0; j < bound2; j++ )
        {
            for ( k = 0; k < bound3; k++ )
            {
                Assign(A, i * 100 + j * 10 + k, i, j, k);
                Value(e, A, i, j, k);
                printf("A[%d][%d][%d] = %2d ", i, j, k, e);
            }
            printf("\n");
        }
        printf("\n");
    }
    p1 = A.base;
    printf("A.base = \n");
    for ( i = 0; i < bound1 * bound2 * bound3; i++ )
    {
        printf("%4d", *(p1 + i));
        if ( i % (bound2 * bound3) == bound2 * bound3 - 1 )
            printf("\n");
    }
    printf("A.dim = %d\n", A.dim);
    DestroyArray(A);

    printf("1. 最大值为%d\n", Max(4, 7, 9, 5, 8));
    printf("2. 最大值为%d\n", Max(3, 17, 36, 25));
    return 0;
}
