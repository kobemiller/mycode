// =====================================================================================
//
//       Filename:  maxheap_test.c
//
//    Description:  大根堆的测试程序
//
//        Version:  1.0
//        Created:  2015年03月08日 19时27分27秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include "maxheap.h"

int main()
{
    int a[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
    int i, len = LENGTH(a);

    printf("==依次添加：");
    for ( i = 0; i < len; i++ )
    {
        printf("%d ", a[i]);
        maxheap_insert(a[i]);
    }
    printf("\n==最大堆：");
    maxheap_print();

    i = 85;
    maxheap_insert(i);
    printf("\n==添加元素：%d", i);
    printf("\n==大根堆：");
    maxheap_print();

    i = 90;
    maxheap_remove(i);
    printf("\n==删除元素：%d", i);
    printf("\n==大根堆：");
    maxheap_print();
    printf("\n");

    return 0;
}
