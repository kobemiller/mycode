// =====================================================================================
//
//       Filename:  circle_linklist.h
//
//    Description:  循环单链表
//
//        Version:  1.0
//        Created:  2015年02月05日 21时08分35秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

struct LNode
{
    ElemType    data;
    LNode       *next;
};
typedef LNode *LinkList;

void InitList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));
    if ( !L )
        exit(OVERFLOW);
    L->next = L;
}

void DestroyList(LinkList &L)
{
    LinkList q, p = L->next;
    while ( p != L )
    {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);
    L = NULL;
}

void ClearList(LinkList &L)
{
    LinkList p, q;
    L = L->next;
    p = L->next;

    while ( p != L )
    {
        q = p->next;
        free(p);
        p = q;
    }

    L->next = L;
}

Status ListEmpty(LinkList L)
{
    if ( L->next == L )
        return TRUE;
    else
        return FALSE;
}

int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;

    while ( p != L )
    {
        i++;
        p = p->next;
    }
    return i;
}

Status GetElem(LinkList L, int i, ElemType &e)
{
    int j = 1;
    LinkList p = L->next->next;
    if ( i <= 0 || i > ListLength(L) )
        return ERROR;
    while ( j < i )
    {
        p = p->next;
        j++;
    }
    e = p->data;
    return OK;
}

int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    int i = 0;
    LinkList p = L->next->next;

    while ( p != L->next )
    {
        i++;
        if ( compare(p->data, e) )
            return i;
        p = p->next;
    }
    return 0;
}

Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
    LinkList q, p = L->next->next;
    q = p->next;

    while ( q != L->next )
    {
        if ( q->data == cur_e )
        {
            pre_e = p->data;
            return TRUE;
        }
        p = q;
        q = q->next;
    }
    return FALSE;
}

Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
    LinkList p = L->next->next;
    while ( p != L )
    {
        if ( p->data == cur_e )
        {
            next_e = p->next->data;
            return TRUE;
        }
        p = p->next;
    }
    return FALSE;
}

Status ListInsert(LinkList &L, int i, ElemType e)
{
    LinkList p = L->next, s;
    int j = 0;

    if ( i <= 0 || i > ListLength(L) + 1 )
        return ERROR;
    while ( j < i-1 )
    {
        p = p->next;
        j++;
    }
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    if ( p == L )
        L = s;
    return OK;
}

Status ListDelete(LinkList &L, int i, ElemType &e)
{
    LinkList p = L->next, q;
    int j = 0;

    if ( i <= 0 || i > ListLength(L) )
        return ERROR;
    while ( j < i-1 )
    {
        p = p->next;
        j++;
    }
    q = p->next;
    e = q->data;
    p->next = q->next;
    if ( L == q )
        L = p;
    free(q);
    return OK;
}

void ListTraverse(LinkList L, void(*vi)(ElemType))
{
    LinkList p = L->next->next;
    while ( p != L->next )
    {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}

//两个仅设尾指针的循环链表合并
void MergeList(LinkList &La, LinkList Lb)
{
    LinkList p = Lb->next;
    Lb->next = La->next;
    La->next = p->next;
    free(p);
    La = Lb;
}


