// =====================================================================================
//
//       Filename:  link_list.cpp
//
//    Description: 链表练习题 
//
//        Version:  1.0
//        Created:  2015年02月28日 09时44分31秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

typedef int ElemType;

#include "../ds.h"
#include "../func.h"
#include "../list/link_list/linklist.h"

/*
 * 删除带头结点的单链表中所有值为x的节点，并释放其空间
 * 思路：用p从头至尾扫描链表，pre指向p的前驱节点，若p指向节点的值为x，则删
 * 除，并让p指向下一个节点，否则让pre和p同步后移一个节点
 */
void delete_x(LinkList &L, ElemType e)
{
    LinkList p, pre, q;
    pre = L;
    p = L->next;
    while ( p )
    {
        if ( p->data == e )
        {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

/*
 * 从尾到头反向输出带头结点的单链表的每个节点
 * 思路：递归输出
 * 思路：新建一个单链表，采用头插法将原链表每个值输入到新链表中，然后再输出
 */
void reverse_print(LinkList p)
{
    if ( p->next )
        reverse_print(p->next);
    printf("%d ", p->data);
}

/*
 * 在头结点的单链表中删除一个最小值节点的高效算法（假设最小值节点唯一）
 * 思路：用p从头到尾扫描单链表，pre指向p的前驱，pos指向最小值节点的前驱，一边扫描一边比较，最后pos指向最小值的前驱节点，然后删除最小值节点
 */
void delete_min(LinkList &L)
{
    LinkList pos, p, pre;
    ElemType e;
    pre = L;
    p = L->next;
    e = p->data;

    while ( p )
    {
        if ( p->data < e )
        {
            pos = pre;
            e = p->data;
        }
        pre = p;
        p = p->next;
    }
    p = pos->next;
    pos->next = p->next;
    free(p);
}

/*
 * 将带头结点的单链表就地逆置（辅助空间为O（1））
 * 思路：将头结点摘下，然后从第一个节点开始，依次前插到头结点后边
 */
void reverse(LinkList &L)
{
    LinkList p = L->next;
    LinkList r;
    L->next = NULL;

    while ( p )
    {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
}

/*
 * 无序带头结点单链表，删除表中所有大于最小值小于最大值的元素
 * 思路：先找到最大值最小值，然后逐个删除
 */
void delete_between_min_and_max(LinkList &L)
{
    ElemType min, max;
    LinkList p = L->next;
    LinkList pre = L;
    min = max = p->data;
    while ( p )
    {
        if ( p->data < min )
            min = p->data;
        if ( p->data > max )
            max = p->data;
        p = p->next;
    }
    p = L->next;
    while ( p )
    {
        if ( p->data > min && p->data < max )
        {
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

/*
 * 给定两个单链表，找出两个链表的公共节点
 * 思路：由于每个单链表节点只有一个next域，所以从第一个公共节点开始往后，链表都是重合的
 * 先遍历两个链表，得到链表的长度，并求出长度差，在长链表上先遍历长度之差个节点之后，再
 * 同步遍历两个链表，直到找到相同的节点，或者一直到链表结束
 * 时间复杂度O(len1 + len2)
 */
void search_common(LinkList La, LinkList Lb)
{
    int len1 = ListLength(La);
    int len2 = ListLength(Lb);
    int dist;
    LinkList longlist, shortlist;

    if ( len1 > len2 )
    {
        longlist = La->next;
        shortlist = Lb->next;
        dist = len1 - len2;
    }
    else
    {
        longlist = Lb->next;
        shortlist = La->next;
        dist = len2 - len1;
    }

    while ( dist-- )
        longlist = longlist->next;
    while ( longlist )
    {
        if ( longlist == shortlist )
            ListTraverse(longlist, print);
        else
        {
            longlist = longlist->next;
            shortlist = shortlist->next;
        }
    }
}

/*
 * 按递增次序输出单链表中各节点的数据元素，并释放节点所占存储空间
 * 思路：对链表进行遍历，在每趟遍历中查找出整个链表中最小值元素，输出并释放节点所占空间；
 * 再查找次小值，如此下去直至链表为空
 */
void print_and_delete_sorted(LinkList &L)
{
    LinkList pos, pre, p;
    ElemType min;

    while ( L->next )
    {
        p = L->next;
        pos = L;
        pre = L;
        min = p->data;
        while ( p )
        {
            if ( p->data < min )
            {
                pos = pre;
                min = p->data;
            }
            pre = p;
            p = p->next;
        }
        p = pos->next;
        printf("%d ", p->data);
        pos->next = p->next;
        free(p);
    }
    printf("\n");
}

/*
 * 将一个带头结点的单链表A分解为两个带头结点的单链表A和B，使得A中含有原表中奇数位元素
 * B中含有偶数位元素，且保持其相对顺序不变
 * 思路：设置一个访问序号，每访问一个节点序号自动加1，然后根据序号的奇偶性将节点插入A或B
 */
void ListInsert_after(LinkList L, ElemType e)
{
    LinkList p = L;
    LinkList s = (LinkList)malloc(sizeof(LNode));
    while ( p->next )
        p = p->next;
    s->data = e;
    p->next = s;
    s->next = NULL;
}
void ListDelete_no_i(LinkList &L, LinkList p)
{
    LinkList cur = p->next;
    p->next = cur->next;
    free(cur);
}
void split(LinkList &La, LinkList &Lb)
{
    LinkList pre, pa, pb;
    int i = 1;
    pre = La;
    pa = La->next;
    pb = Lb->next;

    while ( pa )
    {
        if ( i++ % 2 == 0 )
        {
            ListInsert_after(Lb, pa->data);
            ListDelete_no_i(La, pre);
        }
        pre = pa;
        pa = pa->next;
    }
}

/*
 * 在递增有序的单链表中，有数值相同的元素存在，去重
 * 思路：由于是有序表，所有相同值域的节点都是相邻的，用p扫描链表，
 * 若p节点的值等于其后继节点的值，则删除后继节点，否则p后移
 */
void Delete_repeat_sorted(LinkList &L)
{
    LinkList pre, p, q;
    pre = L->next;
    p = pre->next;
    
    while ( p )
    {
        if ( pre->data != p->data )
        {
            pre = p;
            p = p->next;
        }
        else
        {
            q = p->next;
            pre->next = q;
            free(p);
            p = q;
        }
    }
}

/*
 * 两个递增排列的单链表，归并为一个递减排列的单链表，并要求利用
 * 原来两个单链表的节点存放归并后的单链表
 * 思路：先将一个链表头作为最终结果链表的头部，然后依次比较取较小的进行头插
 */
void merge_sorted(LinkList &La, LinkList &Lb)
{
    LinkList pos, pa, pb;
    pa = La->next;
    pb = Lb->next;
    La->next = NULL;

    while ( pa && pb )
    {
        if ( pa->data <= pb->data )
        {
            pos = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = pos;
        }
        else
        {
            pos = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = pos;
        }
    }
    if ( pa )
    {
        pb = pa;
    }
    while ( pb )
    {
        pos = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = pos;
    }
    free(Lb);
}

/*
 * A和B两个带头结点的单链表，元素递增有序，从A和B中公共元素产生单链表C，要求不破坏A，B的节点
 * 思路：尾插法建立单链表C，通过比较复制的方法产生C
 */
void merge_common(LinkList La, LinkList Lb, LinkList &Lc)
{
    LinkList pa, pb, pc;
    pa = La->next;
    pb = Lb->next;
    pc = Lc;

    while ( pa && pb )
    {
        if ( pa->data < pb->data )
            pa = pa->next;
        else if ( pa->data > pb->data )
            pb = pb->next;
        else
        {
            LinkList s = (LinkList)malloc(sizeof(LNode));
            s->data = pa->data;
            while ( pc->next )
                pc = pc->next;
            pc->next = s;
            s->next = NULL;
            pa = pa->next;
            pb = pb->next;
        }
    }
}

/*
 * 判断序列B是否是序列A的连续子序列
 * 思路：在A序列中找到第一个与B序列第一个元素相等的元素，
 * 然后开始同时往下比
 */
void child_sequence(LinkList La, LinkList Lb)
{
    LinkList pa, pb;
    pa = La->next;
    pb = Lb->next;

    while ( pa && pa->data != pb->data )
        pa = pa->next;
    if ( pa )
        while ( pa && pb )
        {
            if ( pa->data == pb->data )
            {
                pa = pa->next;
                pb = pb->next;
            }
            else
            {
                printf("不是\n");
                return;
            }
        }
    if ( pb )
    {
        printf("不是\n");
        return;
    }
    printf("yes\n");
}

/*
 * 带头结点的单链表，查找链表中倒数第k个位置上的节点
 * 思路：仅通过一趟遍历
 * 定义两个指针p，q，初始时都指向第一个节点，p沿链表移动，
 * 当p移动到第k个节点时，p，q同时移动，当p移动到链表末尾时，
 * q恰好是倒数第k个元素
 */
int search_k(LinkList L, int k)
{
    LinkList p, q;
    p = q = L->next;
    int i = 0;

    while ( p )
        if ( i < k )
        {
            p = p->next;
            i++;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    if ( i < k )
        return ERROR;
    else
    {
        printf("%d\n", q->data);
        return 0;
    }
}

int main()
{
    LinkList La, Lb, Lc;
    ElemType e;
    int i;

    InitList(La);
    InitList(Lb);
    InitList(Lc);

    for ( i = 0; i < 10; i++ )
        ListInsert(La, 1, (i+1)% 4);
    ListTraverse(La, print);

    delete_x(La, 3);
    ListTraverse(La, print);

    ClearList(La);
    for ( i = 0; i < 10; i++ )
        ListInsert(La, 1, i+1);
    ListTraverse(La, print);
    reverse_print(La->next);
    printf("\n");

    delete_min(La);
    ListTraverse(La, print);
    
    reverse(La);
    ListTraverse(La, print);

    delete_between_min_and_max(La);
    ListTraverse(La, print);

    ClearList(La);
    for ( i = 0; i < 10; i++ )
        ListInsert(La, 1, i+1);
    ListTraverse(La, print);
    print_and_delete_sorted(La);

    ClearList(La);
    for ( i = 0; i < 10; i++ )
        ListInsert(La, 1, i+1);
    ListTraverse(La, print);
    split(La, Lb);
    ListTraverse(La, print);
    ListTraverse(Lb, print);

    ClearList(La);
    for ( i = 9; i > 6; i-- )
        ListInsert(La, 1, i);
    for ( i = 7; i > 5; i-- )
        ListInsert(La, 1, i);
    for ( i = 6; i > 4; i-- )
        ListInsert(La, 1, i);
    ListTraverse(La, print);
    Delete_repeat_sorted(La);
    ListTraverse(La, print);

    ClearList(La);
    ClearList(Lb);
    for ( i = 10; i > 0; i-- )
    {
        ListInsert(La, 1, i);
        ListInsert(Lb, 1, i*2);
    }
    ListTraverse(La, print);
    ListTraverse(Lb, print);
    merge_sorted(La, Lb);
    ListTraverse(La, print);

    ClearList(La);
    InitList(Lb);
    for ( i = 10; i > 0; i-- )
    {
        ListInsert(La, 1, i);
        ListInsert(Lb, 1, i*2);
    }
    ListTraverse(La, print);
    ListTraverse(Lb, print);
    merge_common(La, Lb, Lc);
    ListTraverse(Lc, print);

    ClearList(La);
    ClearList(Lb);
    for ( i = 10; i > 0; i-- )
        ListInsert(La, 1, i);
    for ( i = 6; i > 2; i-- )
        ListInsert(Lb, 1, i);
    ListTraverse(La, print);
    ListTraverse(Lb, print);
    child_sequence(La, Lb);

    search_k(La, 4);

    return 0;
}
