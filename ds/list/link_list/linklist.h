// =====================================================================================
//
//       Filename:  linklist.h
//
//    Description: 线性表的链式表示 
//
//        Version:  1.0
//        Created:  2015年01月30日 21时15分41秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

//单链表存储结构
struct LNode
{
    ElemType    data;
    LNode       *next;
};

typedef LNode *LinkList;

//构造一个空的线性表
void InitList(LinkList &L)
{
    L = (LinkList)malloc(sizeof(LNode));    //产生头结点，并使L指向头结点
    if ( !L )
        exit(OVERFLOW);
    L->next = NULL;
}

//销毁线性表L
void DestroyList(LinkList &L)
{
    LinkList q;
    while ( L )
    {
        q = L->next;
        free(L);
        L = q;
    }
}

//重置L为空表
void ClearList(LinkList L)
{
    LinkList p, q;
    p = L->next;
    while ( p )
    {
        q = p->next;
        free(p);
        p = q;
    }
    
    L->next = NULL;
}

//判空
Status ListEmpty(LinkList L)
{
    if ( L->next )
        return FALSE;
    else
        return TRUE;
}

//L中数据元素的个数
int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    while ( p )
    {
        i++;
        p = p->next;
    }
    return i;
}

//返回第i个元素的值
Status GetElem(LinkList L, int i, ElemType &e)
{
    int j = 1;
    LinkList p = L->next;

    while ( p && j < i )
    {
        p = p->next;
        j++;
    }
    if ( !p || j > i )
        return ERROR;
    e = p->data;

    return OK;
}

//返回L中第1个与e满足关系compare（）的数据元素的位序
//若不存在，则返回0
int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    int i = 0;

    LinkList p = L->next;
    while ( p )
    {
        i++;
        if ( compare(p->data, e) )
            return i;
        p = p->next;
    }
    return 0;
}

//若cur_e是L的数据元素，且不是第一个，则用pre_e返回他的前驱
Status PriorElem(LinkList L, ElemType cur_e, ElemType &pre_e)
{
    LinkList q, p = L->next;
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

//若cur_e是L的数据元素，且不是最后一个，则用next_e返回他的后继
Status NextElem(LinkList L, ElemType cur_e, ElemType &next_e)
{
    LinkList p = L->next;
    while ( p->next )
    {
        if ( p->data == cur_e )
        {
            next_e = p->data;
            return OK;
        }
        p = p->next;
    }
    return INFEASIBLE;
}

//在单链表第i个位置之前插入元素e
Status ListInsert(LinkList L, int i, ElemType e)
{
    int j = 0;
    LinkList p = L, s;
    
    while ( p && j < i - 1 )
    {
        p = p->next;
        j++;
    }
    if ( !p || j > i - 1 )
        return ERROR;
    s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}

//删除第i个元素
Status ListDelete(LinkList L, int i, ElemType &e)
{
    int j = 0;
    LinkList  p = L, q;

    while ( p->next && j < i-1 )
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

    return OK;
}

//依次对L的每个数据元素调用函数vi（）
void ListTraverse(LinkList L, void(*vi)(ElemType))
{
    LinkList p = L->next;

    while ( p )
    {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}

//将所有在线性表Lb中但不在La中的数据元素插入La中
void Union(LinkList La, LinkList Lb)
{
    ElemType e;
    int La_len, Lb_len;
    int i;

    La_len = ListLength(La);
    Lb_len = ListLength(Lb);

    for ( i = 1; i <= Lb_len; i++ )
    {
        GetElem(Lb, i, e);
        if ( !LocateElem(La, e, equal) )
            ListInsert(La, ++La_len, e);
    }
}

//merge
//La和Lb中的数据元素按值非递减排列
//归并La和Lb得到新的线性表Lc，Lc也按值非递减排列
void MergeList(LinkList La, LinkList Lb, LinkList &Lc)
{
    int i = 1, j = 1, k = 0;
    int La_len, Lb_len;
    ElemType ai, bj;
    
    InitList(Lc);
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);

    while ( i <= La_len && j <= Lb_len )
    {
        GetElem(La, i, ai);
        GetElem(Lb, j, bj);

        if ( ai <= bj )
        {
            ListInsert(Lc, ++k, ai);
            ++i;
        }
        else
        {
            ListInsert(Lc, ++k, bj);
            ++j;
        }
    }

    while ( i <= La_len )
    {
        GetElem(La, i++, ai);
        ListInsert(Lc, ++k, ai);
    }
    while ( j <= Lb_len )
    {
        GetElem(Lb, j++, bj);
        ListInsert(Lc, ++k, bj);
    }

}

//createlist
//逆位序（插在表头）输入n个元素的值，建立带表头结构的单链线性表
void CreateList(LinkList &L, int n)
{
    int i;
    LinkList p;

    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    printf("请输入%d个数据\n", n);
    for ( i = n; i > 0; i-- )
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        p->next = L->next;
        L->next = p;
    }
}

//createlist
//正位序（插在表尾）输入n个元素的值，建立带表头结构的单链表
void CreateList2(LinkList &L, int n)
{
    int i;
    LinkList p, q;

    L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    q = L;
    printf("请输入%d个数据\n", n);
    for ( i = 1; i <= n; i++ )
    {
        p = (LinkList)malloc(sizeof(LNode));
        scanf("%d", &p->data);
        q->next = p;
        q = q->next;
    }
    p->next = NULL;
}

//mergelist
void MergeList2(LinkList La, LinkList &Lb, LinkList &Lc)
{
    LinkList pa = La->next, pb = Lb->next, pc;
    Lc = pc = La;

    while ( pa && pb )
    {
        if ( pa->data <= pb->data )
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(Lb);
    Lb = NULL;
}

