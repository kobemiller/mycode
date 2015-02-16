/*
 * =====================================================================================
 *
 *       Filename:  sequeue2_test.cpp
 *
 *    Description: sequeue2测试程序 
 *
 *        Version:  1.0
 *        Created:  2015年02月16日 08时27分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

typedef int QElemType;

#include "../ds.h"
#include "sequeue2.h"

int main()
{
    Status j;
    int i, n = 11;
    QElemType d;
    SqQueue2 Q;

    InitQueue(Q);
    printf("初始化队列后，队列空否？%u(1:yes 0:no)\n", QueueEmpty(Q));
    printf("队列长度为%d\n", QueueLength(Q));
    printf("请输入%d个整形队列元素: \n", n);
    for ( i = 0; i < n; i++ )
    {
        scanf("%d", &d);
        EnQueue(Q, d);
    }
    printf("队列长度为%d\n", QueueLength(Q));
    printf("现在队列空否？%u(1:yes 0:no)\n", QueueEmpty(Q));
    printf("现在队列中的元素为\n");
    QueueTraverse(Q, print);
    DeQueue(Q, d);
    printf("删除队头元素%d\n", d);
    printf("队列中的元素为\n");
    QueueTraverse(Q, print);
    j = GetHead(Q, d);
    if ( j )
        printf("队头元素为%d\n", d);
    else
        printf("没有对头元素（空队列）\n");
    ClearQueue(Q);
    printf("清空队列后，队列空否？%u(1:yes 0:no)\n", QueueEmpty(Q));
    j = GetHead(Q, d);
    if ( j )
        printf("队头元素为%d\n", d);
    else
        printf("没有对头元素（空队列）\n");
    DestroyQueue(Q);

    return 0;
}
