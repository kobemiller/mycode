/*
 * =====================================================================================
 *
 *       Filename:  sequeue2.h
 *
 *    Description:  队列的顺序存储结构2
 *                  出队元素时不移动元素，只改变队头元素的位置
 *
 *        Version:  1.0
 *        Created:  2015年02月16日 08时09分31秒
 *       Revision:  none
 *       Compiler:  gcc
 * =====================================================================================
 */

#define QUEUE_INIT_SIZE 10
#define QUEUE_INCREMENT 2
struct SqQueue2
{
    QElemType *base;
    int front;
    int rear;
    int queuesize;
};

void InitQueue(SqQueue2 &Q)
{
    if ( !(Q.base = (QElemType *)malloc(QUEUE_INIT_SIZE * sizeof(QElemType))) )
            exit(ERROR);
    Q.front = Q.rear = 0;
    Q.queuesize = QUEUE_INIT_SIZE;
}

void DestroyQueue(SqQueue2 &Q)
{
    if ( Q.base )
            free(Q.base);
    Q.base = NULL;
    Q.front = Q.rear = Q.queuesize = 0;
}

void ClearQueue(SqQueue2 &Q)
{
    Q.front = Q.rear = 0;
}

Status QueueEmpty(SqQueue2 Q)
{
    if ( Q.front == Q.rear )
            return TRUE;
    else
            return FALSE;
}

Status GetHead(SqQueue2 Q, QElemType &e)
{
    if ( Q.front == Q.rear )
            return ERROR;
    e = Q.base[Q.front];
    return OK;
}

int QueueLength(SqQueue2 Q)
{
    return (Q.rear - Q.front);
}

void EnQueue(SqQueue2 &Q, QElemType e)
{
    if ( Q.rear == Q.queuesize )
    {
        Q.base = (QElemType *)realloc(Q.base, (Q.queuesize + QUEUE_INCREMENT)*sizeof(QElemType));
        if ( !Q.base )
                exit(ERROR);
    }
    Q.base[Q.rear++] = e;
}

Status DeQueue(SqQueue2 &Q, QElemType &e)
{
    if ( Q.front == Q.rear )
            return ERROR;
    e = Q.base[Q.front++];
    return OK;
}

void QueueTraverse(SqQueue2 Q, void(*vi)(QElemType))
{
    int i = Q.front;
    while ( i != Q.rear )
            vi(Q.base[i++]);
    printf("\n");
}

void print(QElemType i)
{
    printf("%d ", i);
}

