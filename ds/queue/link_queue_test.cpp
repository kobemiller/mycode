/*
 * =====================================================================================
 *
 *       Filename:  link_queue_test.cpp
 *
 *    Description:  链式队列的测试程序
 *
 *        Version:  1.0
 *        Created:  2015年02月12日 19时47分48秒
 *       Revision:  none
 *       Compiler:  gcc
 * =====================================================================================
 */

typedef int QElemType;

#include "../ds.h"
#include "link_queue.h"

int main()
{
    int i;
    QElemType d;
    LinkQueue q;
    
    InitQueue(q);
    printf("成功的构造了一个空队列！\n");
    printf("是否空队列? %d(1:yes 0:no)\n", QueueEmpty(q));
    printf("队列的长度为%d\n", QueueLength(q));

    EnQueue(q, -5);
    EnQueue(q, 5);
    EnQueue(q, 10);
    printf("插入三个元素后，队列的长度为%d\n", QueueLength(q));
    printf("是否空队列? %d(1:yes 0:no)\n", QueueEmpty(q));
    printf("队列的元素依次为 ");
    QueueTraverse(q, print_QElemType);
    i = GetHead(q, d);
    if ( i == OK )
            printf("队头元素是：%d\n", d);
    DeQueue(q, d);
    printf("删除了队头元素%d\n", d);
    i = GetHead(q, d);
    if ( i == OK )
            printf("新的队头元素是：%d\n", d);
    ClearQueue(q);
    printf("清空队列后，q.front = %u q.rear = %u q.front->next = %u\n", 
                q.front, q.rear, q.front->next);
    DestroyQueue(q);
    printf("销毁队列后, q.front = %u q.rear = %u\n", q.front, q.rear);

    return 0;
}
