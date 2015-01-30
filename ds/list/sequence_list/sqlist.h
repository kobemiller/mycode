// =====================================================================================
//
//       Filename:  sqlist.h
//
//    Description:  线性表的动态分配顺序存储结构
//
//        Version:  1.0
//        Created:  2015年01月29日 23时40分22秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#define LIST_INIT_SIZE  10  //线性表存储空间的初始分配量
#define LIST_INCREMENT  2   //线性表存储空间的分配增量

struct Sqlist
{
    ElemType    *elem;      //存储空间基址
    int         length;     //当前长度
    int         listsize;   //当前分配的存储容量
};

//顺序表示的线性表的12个基本操作

/*
 * 操作结果：构造一个空的顺序线性表
 */
void InitList(Sqlist &L)
{
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if ( !L.elem )
        exit(OVERFLOW);
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
}

/*
 * 初始条件：顺序表已存在
 * 操作结果：销毁顺序表
 */
void DestroyList(Sqlist &L)
{
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
}

/*
 * 初始条件：顺序表已存在
 * 操作结果：将顺序表重置为空表
 */
void ClearList(Sqlist &L)
{
    L.length = 0;
}

/*
 * 初始条件：顺序表已存在
 * 操作结果：若为空表，返回TRUE；否则返回FALSE
 */
Status ListEmpty(Sqlist L)
{
    if ( L.length == 0 )
        return TRUE;
    else
        return FALSE;
}

/*
 * 初始条件：顺序表已存在，1 <= i <= ListLength(L)
 * 操作结果：用e返回顺序表中第i个数据元素的值
 */
Status GetElem(Sqlist L, int i, ElemType &e)
{
    if ( i < 1 || i > L.length )
        return ERROR;
    e = *(L.elem + i - 1);
    return OK;
}

/*
 * 初始条件：顺序表已存在
 * 操作结果：返回表中数据元素的个数
 */
int ListLength(Sqlist L)
{
    return L.length;
}

/*
 * 查找：
 * 操作结果：返回表中第一个与e满足关系compare的数据元素的位序，
 * 若元素不存在，返回0
 */
int LocateElem(Sqlist L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    ElemType *p;
    int i = 1;
    p = L.elem;

    while ( i <= L.length && !compare(*p++, e) )
        ++i;

    if ( i <= L.length )
        return i;
    else 
        return 0;
}

/*
 * 返回前驱节点：
 * 操作结果：若cur_e是表的数据元素，且不是第一个，则用pre_e返回他的前驱
 * 否则操作失败，pre_e无定义
 */
Status PriorElem(Sqlist L, ElemType cur_e, ElemType &pre_e)
{
    int i = 2;
    ElemType *p = L.elem + 1;

    while ( i <= L.length && *p != cur_e )
    {
        p++;
        i++;
    }

    if ( i > L.length )
        return INFEASIBLE;
    else
    {
        pre_e = *--p;
        return OK;
    }
}

/*
 * 返回后继节点：
 * 操作结果：若cur_e是表的数据元素，且不是最后一个，则用next_e返回他的后继
 * 否则操作失败，next_e无定义
 */
Status NextElem(Sqlist L, ElemType cur_e, ElemType &next_e)
{
    int i = 1;
    ElemType *p = L.elem;

    while ( i < L.length && *p != cur_e )
    {
        p++;
        i++;
    }

    if ( i >= L.length )
        return INFEASIBLE;
    else
    {
        next_e = *++p;
        return OK;
    }
}

/*
 * 前插：
 * 操作结果：在表中第i个位置之前插入新的数据元素，表的长度+1
 */
Status ListInsert_before(Sqlist &L, int i, ElemType e)
{
    ElemType *newbase, *q, *p;
    if ( i < 1 || i > L.length + 1 )
        return ERROR;
    if ( L.length >= L.listsize )       //存储空间已满，增加存储
    {
        if ( !(newbase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREMENT)*sizeof(ElemType))) )
            exit(OVERFLOW);
        L.elem = newbase;
        L.listsize += LIST_INCREMENT;
    }
    
    q = L.elem + i - 1;
    
    //插入位置及以后的元素后移
    for ( p = L.elem + L.length - 1; p >= q; --p )
        *(p+1) = *p;
    *q = e;
    ++L.length;

    return OK;
}

/*
 * 后插：
 * 操作结果：在表中第i个位置之后插入新的数据元素，表的长度+1
 */
Status ListInsert_next(Sqlist &L, int i, ElemType e)
{
    ElemType *newbase, *q, *p;
    if ( i < 1 || i > L.length )
        return ERROR;
    if ( L.length >= L.listsize )
    {
        if ( !(newbase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREMENT)*sizeof(ElemType))) )
            exit(OVERFLOW);
        L.elem = newbase;
        L.length += LIST_INCREMENT;
    }

    q = L.elem + i - 1;     //q指向插入点

    //插入位置以后的元素后移
    for ( p = L.elem + L.length - 1; p > q; --p )
        *(p+1) = *p;
    *(p+1) = e;     //解决了在最后一个元素之后插入的操作一致性问题
    ++L.length;

    return OK;
}

/*
 * 删除
 * 删除第i个数据元素，并用e返回其值，表的元素减1
 */
Status ListDelete(Sqlist &L, int i, ElemType &e)
{
    ElemType *p, *q;

    if ( i < 1 || i > L.length )
        return ERROR;

    p = L.elem + i - 1;     //p是删除的元素

    e = *p;

    q = L.elem + L.length - 1;  
    for ( ++p; p <= q; ++p )    //删除元素之后的元素前移
        *(p-1) = *p;
    L.length--;

    return OK;
}

/*
 * 遍历顺序表
 * 操作结果：依次对表中每个元素调用函数vi()
 * vi的形参加‘&’，表明可通过调用vi()改变元素的值
 */
void ListTraverse(Sqlist L, void (*vi)(ElemType&))
{
    ElemType *p;
    int i;
    p = L.elem;
    for ( i = 0; i < L.length; i++ )
        vi(*p++);
    printf("\n");
}

Status ListInsert_at_end(Sqlist &L, int i, ElemType e)
{
    ElemType *newbase;
    if ( i < 1 || i > L.length )
        return ERROR;
    if ( L.length >= L.listsize )
    {
        if ( !(newbase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREMENT)*sizeof(ElemType))) )
            exit(OVERFLOW);
        L.elem = newbase;
        L.length += LIST_INCREMENT;
    }

    *(L.elem + L.length) = e;
    L.length++;

    return OK;
}

/*
 * union
 * 将所有在线性表b中但不在a中的数据元素插入到a中
 */
void Union(Sqlist &La, Sqlist &Lb)
{
    ElemType e;
    int La_len, Lb_len;
    int i;
    
    La_len = ListLength(La);    //求线性表长度
    Lb_len = ListLength(Lb);
    
    for ( i = 1; i <= Lb_len; i++ )     
    {
        GetElem(Lb, i, e);      //依次取Lb中各元素
        if ( !LocateElem(La, e, equal) )    //如果La中没有和e相等的，就插入
            ListInsert_before(La, ++La_len, e);
    }
}

/*
 * merge
 * 已知线性表La和Lb中的数据元素按值非递减排列
 * 归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列
 */
void MergeList(Sqlist La, Sqlist Lb, Sqlist &Lc)
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
            ListInsert_before(Lc, ++k, ai);
            ++i;
        }
        else
        {
            ListInsert_before(Lc, ++k, bj);
            ++j;
        }
    }
    while ( i <= La_len )
    {
        GetElem(La, i++, ai);
        ListInsert_before(Lc, ++k, ai);
    }
    while ( j <= Lb_len )
    {
        GetElem(Lb, j++, bj);
        ListInsert_before(Lc, ++k, bj);
    }
}

/*
 * merge
 * 另外一种方法
 */
void MergeList1(Sqlist La, Sqlist Lb, Sqlist &Lc)
{
    ElemType *pa, *pa_last, *pb, *pb_last, *pc;
    pa = La.elem;
    pb = Lb.elem;
    Lc.listsize = Lc.length = La.length + Lb.length;
    pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if ( !Lc.elem )
        exit(OVERFLOW);
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;

    while ( pa <= pa_last && pb <= pb_last )
    {
        if ( *pa <= *pb )
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }

    while ( pa <= pa_last )
        *pc++ = *pa++;
    while ( pb <= pb_last )
        *pc++ = *pb++;
}

/*
 * merge
 * 第3种方法
 * 如果两者相等，只将一个插入Lc
 */
void MergeList2(Sqlist La, Sqlist Lb, Sqlist &Lc)
{
    ElemType *pa, *pa_last, *pb, *pb_last, *pc;
    pa = La.elem;
    pb = Lb.elem;
    Lc.listsize = La.length + Lb.length;
    pc = Lc.elem = (ElemType *)malloc(Lc.listsize * sizeof(ElemType));
    if ( !Lc.elem )
        exit(OVERFLOW);
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;

    while ( pa <= pa_last && pb <= pb_last )
        switch ( comp(*pa, *pb) ) 
        {
            case 0:     pb++;
            case -1:
                        *pc++ = *pa++;
                        break;
            case 1:     *pc++ = *pb++;
        }
    while ( pa <= pa_last )
        *pc++ = *pa++;
    while ( pb <= pb_last )
        *pc++ = *pb++;
    Lc.length = pc - Lc.elem;
}



