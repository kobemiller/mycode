/*
 * =====================================================================================
 *
 *       Filename:  sequeue_queue_test.cpp
 *
 *    Description:  循环队列的测试程序
 *
 *        Version:  1.0
 *        Created:  2015年02月16日 07时53分44秒
 *       Revision:  none
 *       Compiler:  gcc
 * =====================================================================================
 */

typedef int QElemType;

#include "../ds.h"
#include "sequence_queue.h"

int main()
{
    Status j;
    int i, k = 5;
    QElemType d;
    SqQueue1 Q;

    InitQueue(Q);
    printf("初始化队列后，队列空否？%u(1:yes 0:no)\n", QueueEmpty(Q));
    for ( i = 1; i <= k; i++ )
            EnQueue(Q, i);
    printf("依次入队%d个元素后，队列中的元素为 ", k);
    QueueTraverse(Q, print);
    printf("队列长度为 %d，队列空否？%u(1:yes 0:no)\n", QueueLength(Q), QueueEmpty(Q));
    DeQueue(Q, d);
    printf("出队一个元素, 其值为%d\n", d);
    j = GetHead(Q, d);
    if ( j )
            printf("现在对头元素是%d\n", d);
    ClearQueue(Q);
    printf("清空队列后，队列空否？%u(1:yes 0:no)\n", QueueEmpty(Q));
    DestroyQueue(Q);

    return 0;
}
