// =====================================================================================
//
//       Filename:  maxheap_test.c
//
//    Description:  小根堆的测试程序
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

#include "minheap.h"

int main()
{
    int a[] = {80, 40, 30, 60, 90, 70, 10, 50, 20};
    int i, len = LENGTH(a);

    printf("==依次添加：");
    for ( i = 0; i < len; i++ )
    {
        printf("%d ", a[i]);
        minheap_insert(a[i]);
    }
    printf("\n==小根堆：");
    minheap_print();

    i = 85;
    minheap_insert(i);
    printf("\n==添加元素：%d", i);
    printf("\n==小根堆：");
    minheap_print();

    i = 90;
    minheap_remove(i);
    printf("\n==删除元素：%d", i);
    printf("\n==小根堆：");
    minheap_print();
    printf("\n");

    return 0;
}
