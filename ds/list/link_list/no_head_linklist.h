// =====================================================================================
//
//       Filename:  no_head_linklist.h
//
//    Description:  不带头结点的单链表
//
//        Version:  1.0
//        Created:  2015年02月04日 09时23分34秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#define DestroyList ClearList

struct LNode
{
    ElemType data;
    LNode    *next;
};
typedef LNode *LinkList;

//构造一个空的线性表
void InitList(LinkList &L)
{
    L = NULL;
}

void ClearList(LinkList &L)
{
    LinkList p;
    while ( L )
    {
        p = L;
        L = L->next;
        free(p);
    }
}

Status ListEmpty(LinkList L)
{
    if ( L )
        return FALSE;
    else
        return TRUE;
}

int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L;
    while ( p )
    {
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{
    int j = 1;
    LinkList p = L;
    if ( i < 1 )
        return ERROR;
    while ( j < i && p )
    {
        j++;
        p = p->next;
    }
    if ( j == i )
    { 
        e = p->data;
        return OK;
    }
    else
        return ERROR;
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    int i = 0;
    LinkList p;

    while ( p )
    {
        i++;
        if ( compare(p->data, e) )
            return i;
        p = p->next;
    }
    return 0;
}

Status ListInsert(LinkList &L, int i, ElemType e)
{
    int j = 1;
    LinkList p = L, s;
    if ( i < 1 )
        return ERROR;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    
    if ( i == 1 )
    {
        s->next = L;
        L = s;
    }
    else
    {
        while ( j < i-1 && p )
        {
            p = p->next;
            j++;
        }
        if ( !p )
            return ERROR;
        s->next = p->next;
        p->next = s;
    }
    return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e)
{
    int j = 1;
    LinkList p = L, q;

    if ( i == 1 )
    { 
        L = p->next;
        e = p->data;
        free(p);
    }
    else
    {
        while ( j < i-1 && p->next )
        {
            p = p->next;
            j++;
        }
        if ( !p->next || j > i-1 )
            return ERROR;
        q = p->next;
        p->next = q->next;
        e = q->data;
        free(q);
    }
    return OK;
}

void ListTraverse(LinkList L, void(*vi)(ElemType))
{
    LinkList p = L;
    while ( p )
    {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
    LinkList q, p = L;
    while ( p->next )
    {
        q = p->next;
        if ( q->data == cur_e )
        {
            pre_e = p->data;
            return OK;
        }
        p = q;
    }
    return INFEASIBLE;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
    LinkList p = L;
    while ( p->next )
    {
        if ( p->data == cur_e )
        {
            next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return INFEASIBLE;
}


