/*
 * =====================================================================================
 *
 *       Filename:  sequence_queue.h
 *
 *    Description:  顺序队列--非循环表示和实现
 *
 *        Version:  1.0
 *        Created:  2015年02月13日 07时31分33秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#define QUEUE_INIT_SIZE 10
#define QUEUE_INCREMENT 2

struct SqQueue1
{
    QElemType   *base;
    int         rear;
    int         queuesize;
};

void InitQueue(SqQueue1 &Q)
{
    if ( !(Q.base = (QElemType*)malloc(QUEUE_INIT_SIZE * sizeof(QElemType))) )
            exit(ERROR);
    Q.rear = 0;
    Q.queuesize = QUEUE_INIT_SIZE;
}

void DestroyQueue(SqQueue1 &Q)
{
    free(Q.base);
    Q.base = NULL;
    Q.rear = Q.queuesize = 0;
}

void ClearQueue(SqQueue1 &Q)
{
    Q.rear = 0;
}

Status QueueEmpty(SqQueue1 Q)
{
    if ( Q.rear == 0 )
            return TRUE;
    else
            return FALSE;
}

int QueueLength(SqQueue1 Q)
{
    return Q.rear;
}

Status GetHead(SqQueue1 Q, QElemType &e)
{
    if ( Q.rear )
    {
        e = *Q.base;
        return OK;
    }
    else
        return OK;
}

void EnQueue(SqQueue1 &Q, QElemType e)
{
    if ( Q.rear == Q.queuesize )
    {
        Q.base = (QElemType *)realloc(Q.base, (Q.queuesize + QUEUE_INCREMENT) * sizeof(QElemType));
        if ( !Q.base )
               exit(ERROR);
        Q.queuesize += QUEUE_INCREMENT;
    }
    Q.base[Q.rear++] = e;
}

Status DeQueue(SqQueue1 &Q, QElemType &e)
{
    int i;
    if ( Q.rear )
    {
        e = *Q.base;
        for ( i = 1; i < Q.rear; i++ )
            Q.base[i-1] = Q.base[i];
        Q.rear--;
        return OK;
    }
    else
        return ERROR;
}

void QueueTraverse(SqQueue1 Q, void(*vi)(QElemType))
{
    int i;
    for ( i = 0; i < Q.rear; i++ )
            vi(Q.base[i]);
    printf("\n");
}

void print(QElemType i)
{
    printf("%d ", i);
}

