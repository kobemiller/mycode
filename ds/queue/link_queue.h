/*
 * =====================================================================================
 *
 *       Filename:  link_queue.h
 *
 *    Description:  链队列的表示和实现
 *
 *        Version:  1.0
 *        Created:  2015年02月12日 19时25分24秒
 *       Revision:  none
 *       Compiler:  gcc
 * =====================================================================================
 */

typedef struct QNode
{
    QElemType   data;
    QNode       *next;
}*QueuePtr;
struct LinkQueue
{
    QueuePtr front, rear;
};

void InitQueue(LinkQueue &Q)
{
    if ( !(Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode))) )
        exit(OVERFLOW);
    Q.front->next = NULL;
}

void DestroyQueue(LinkQueue &Q)
{
    while ( Q.front )
    {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
}

void ClearQueue(LinkQueue &Q)
{
    QueuePtr p, q;
    Q.rear = Q.front;
    p = Q.front->next;
    Q.front->next = NULL;
    while ( p )
    {
        q = p;
        p = p->next;
        free(q);
    }
}

Status QueueEmpty(LinkQueue Q)
{
    if ( Q.front->next == NULL )
            return TRUE;
    else
            return FALSE;
}

int QueueLength(LinkQueue Q)
{
    int i = 0;
    QueuePtr p;
    p = Q.front;
    while ( Q.rear != p )
    {
        i++;
        p = p->next;
    }
    return i;
}

Status GetHead(LinkQueue Q, QElemType &e)
{
    QueuePtr p;
    if ( Q.front == Q.rear )
            return ERROR;
    p = Q.front->next;
    e = p->data;
    return OK;
}

void EnQueue(LinkQueue &Q, QElemType e)
{
    QueuePtr p;
    if ( !(p = (QueuePtr)malloc(sizeof(QNode))) )
        exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

Status DeQueue(LinkQueue &Q, QElemType &e)
{
    QueuePtr p;
    if ( Q.front == Q.rear )
            return ERROR;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if ( Q.rear == p )
            Q.rear = Q.front;
    free(p);

    return OK;
}

void QueueTraverse(LinkQueue Q, void (*vi)(QElemType))
{
    QueuePtr p;
    p = Q.front->next;
    while ( p )
    {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}

void print(QElemType i)
{
    printf("%d ", i);
}

