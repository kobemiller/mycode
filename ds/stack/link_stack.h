/*
 * =====================================================================================
 *
 *       Filename:  link_stack.h
 *
 *    Description:  链栈的基本操作
 *
 *        Version:  1.0
 *        Created:  2015年02月12日 03时01分23秒
 *       Revision:  none
 *       Compiler:  gcc
 * =====================================================================================
 */

typedef SElemType ElemType;

#include "../list/link_list/no_head_linklist.h"

typedef LinkList LinkStack;

#define InitStack       InitList
#define DestroyStack    DestroyList
#define ClearStack      ClearList
#define StackEmpty      ListEmpty
#define StackLength     ListLength

Status GetTop(LinkStack S, SElemType &e)
{
    return GetElem(S, 1, e);
}

Status Push(LinkStack &S, SElemType e)
{
    return ListInsert(S, 1, e);
}

Status Pop(LinkStack &S, SElemType &e)
{
    return ListDelete(S, 1, e);
}

void StackTraverse(LinkStack S, void (*visit)(SElemType))
{
    LinkStack temp, p = S;
    InitStack(temp);
    while ( p )
    {
        Push(temp, p->data);
        p = p->next;
    }
    ListTraverse(temp, visit);
}

void print(SElemType c)
{
    printf("%d ", c);
}

