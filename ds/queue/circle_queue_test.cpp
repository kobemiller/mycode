/*
 * =====================================================================================
 *
 *       Filename:  circle_queue_test.cpp
 *
 *    Description:  循环队列的测试程序 
 *
 *        Version:  1.0
 *        Created:  2015年02月16日 15时10分56秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

typedef int QElemType;

#include "../ds.h"
#include "circle_queue.h"

int main()
{
    Status j;
    int i = 0, l;
    QElemType d;
    SqQueue Q;

    InitQueue(Q);
    printf("初始化队列后，队列空否 ? %u(1:yes 0:no)\n", QueueEmpty(Q));
    printf("请输入整形队列元素（不超过%d个）， -1为提前结束符:", MAX_QSIZE - 1);
    do
    {
        scanf("%d", &d);
        if ( d == -1 )
                break;
        i++;
        EnQueue(Q, d);
    } while ( i < MAX_QSIZE - 1 );
    printf("队列长度为%d\n", QueueLength(Q));
    printf("现在队列空否？%u(1:yes 0:no)\n", QueueEmpty(Q));
    printf("连续%d次由队头删除元素，队尾插入元素：\n", MAX_QSIZE);
    for ( l = 1; l <= MAX_QSIZE; l++ )
    {
        DeQueue(Q, d);
        printf("删除的元素是%d, 请输入待插入的元素：", d);
        scanf("%d", &d);
        EnQueue(Q, d);
    }
    l = QueueLength(Q);
    printf("现在队列中的元素为\n");
    QueueTraverse(Q, print);
    printf("共向队尾插入了%d个元素\n", i + MAX_QSIZE);
    if ( l - 2 > 0 )
            printf("现在由队头删除%d个元素:\n", l-2);
    while ( QueueLength(Q) > 2 )
    {
        DeQueue(Q, d);
        printf("删除的元素值为%d\n", d);
    }
    j = GetHead(Q, d);
    if ( j )
        printf("现在队头元素是%d\n", d);
    ClearQueue(Q);
    printf("清空队列后， 队列空否？%u(1:yes 0:no)\n", QueueEmpty(Q));
    DestroyQueue(Q);

    return 0;
}
