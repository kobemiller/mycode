/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *
 *        Version:  1.0
 *        Created:  2015年02月17日 11时18分37秒
 *       Revision:  none
 *       Compiler:  gcc
 * =====================================================================================
 */

typedef int ElemType;

#include "../ds.h"
#include "../func.h"
#include "../list/sequence_list/sqlist.h"

int func(Sqlist &L, ElemType &e);
int reverse(Sqlist &L);
int delete_same_x(Sqlist &L, ElemType e);
int delete_between_s_and_t_sorted(Sqlist &L, ElemType s, ElemType t);
int delete_between_s_and_t_unsorted(Sqlist &L, ElemType s, ElemType t);
int delete_repeat(Sqlist &L);
int merge_two_sorted(Sqlist La, Sqlist Lb, Sqlist &Lc);
void reverse_left_right(Sqlist L, int left, int right);
void revert_a_and_b(Sqlist La, Sqlist Lb, Sqlist &Lc);
int mid_search(Sqlist La, Sqlist Lb, int n);

int main()
{
    Sqlist La, Lb, Lc;
    int i;
    ElemType e;
    InitList(La);
    for ( i = 0; i < 10; i++ )
        ListInsert_before(La, i, i);
    printf("BEFORE: ");
    ListTraverse(La, print1);
    func(La, e);
    printf("AFTER: ");
    ListTraverse(La, print1);
    printf("e = %d\n", e);

    reverse(La);
    ListTraverse(La, print1);

    ClearList(La);
    
    for ( i = 0; i < 10; i++ )
        ListInsert_before(La, i, i % 3);
    ListTraverse(La, print1);
    delete_same_x(La, 1);
    ListTraverse(La, print1);

    ClearList(La);
    for ( i = 0; i < 10; i++ )
        ListInsert_before(La, i, i);
    ListTraverse(La, print1);
    delete_between_s_and_t_sorted(La, 3, 6);
    ListTraverse(La, print1);

    ClearList(La);
    for ( i = 0; i < 10; i++ )
        ListInsert_before(La, i, rand() % 10);
    ListTraverse(La, print1);
    delete_between_s_and_t_unsorted(La, 3, 6);
    ListTraverse(La, print1);

    ClearList(La);
    for ( i = 0; i < 10; i++ )
        ListInsert_before(La, i, rand() % 10);
    ListTraverse(La, print1);
    delete_repeat(La);
    ListTraverse(La, print1);

    ClearList(La);
    InitList(Lb);
    InitList(Lc);
    for ( i = 0; i < 10; i++ )
    {
        ListInsert_before(La, i, i);
        ListInsert_before(Lb, i, 2*i);
    }
    ListTraverse(La, print1);
    ListTraverse(Lb, print1);
    merge_two_sorted(La, Lb, Lc);
    ListTraverse(Lc, print1);

    revert_a_and_b(La, Lb, Lc);
    ListTraverse(Lc, print1);

    printf("中位数: %d\n", mid_search(La, Lb, 9));

    //DestroyList(La);
    return 0;
}

int func(Sqlist &L, ElemType &e)
{
    int i, pos;
    int len = ListLength(L);
    if ( ListEmpty(L) )
        return ERROR;
    e = *(L.elem);
    for ( i = 1; i < len; i++ )
    {
        if ( *(L.elem + i) < e )
        {
            pos = i;
            e = *(L.elem + i);
        }
    }   
    
    *(L.elem + pos - 1) = *(L.elem + len - 1);
    return 0;
}

int reverse(Sqlist &L)
{
    ElemType e;
    int len = ListLength(L);
    int i;
    for ( i = 1; i < len/2; i++ )
    {
        e = *(L.elem + i - 1);
        *(L.elem + i - 1) = *(L.elem + len - i);
        *(L.elem + len - i) = e;
    }
    return 0;
}

/*
 * 时间复杂度o(n),空间复杂度o(1)的算法，实现删除顺序表中所有值为x的元素
 * 思路：用k记录表中不等于x的元素个数，边扫描边统计k，并将不等于x的元素向前放置k位置上
 * 最后修改表长
 */
int delete_same_x(Sqlist &L, ElemType e)
{
    int i;
    int count = 0;
    for ( i = 0; i < ListLength(L); i++ )
    {
        if ( *(L.elem + i) != e )
        {
            *(L.elem + count) = *(L.elem + i); 
            count++;
        }
    }
    L.length = count;
    return 0;
}

/* 
 * 从有序顺序表中删除其值在给定的s到t之间的所有元素
 * 思路：先寻找值大于等于s的第一个元素（第一个删除的元素），
 *      再寻找值大于t的第一个元素（最后一个删除的元素的下一个元素），
 *      然后将后边的元素前移
 */
int delete_between_s_and_t_sorted(Sqlist &L, ElemType s, ElemType t)
{
    int i, j;

    if ( s >= t && ListEmpty(L) )
        return ERROR;
    for ( i = 0; i < ListLength(L) && *(L.elem + i) < s; i++ );
    if ( i > ListLength(L) )
        return ERROR;
    for ( j = i; j < ListLength(L) && *(L.elem + j) <= t; j++ );
    for ( ; j < ListLength(L); i++, j++ )
        *(L.elem + i) = *(L.elem + j);
    L.length = i;

    return 0;
}

/* 从顺序表中删除其值在给定的s到t之间的所有元素
 * 思路：
 * 先找到第一个在s到t之间的元素，然后从这个元素开始将每个不在s到t之间的元素向前复制
 */
int delete_between_s_and_t_unsorted(Sqlist &L, ElemType s, ElemType t)
{
    int i, j;
    if ( s >= t && ListEmpty(L) )
        return ERROR;
    for ( i = 0; i < L.length && (*(L.elem + i) < s || *(L.elem + i) > t); i++ );
    if ( i > L.length )
        return ERROR;
    for ( j = i+1; j < L.length; j++)
    {
        if ( *(L.elem + j) < s || *(L.elem + j) > t )
            *(L.elem + i++) = *(L.elem + j);
    }
    L.length = i;

    //另外一种实现：
    //从前向后扫描顺序表，用k记录下元素值在s到t之间元素的个数（初始时k=0）。
    //对于当前扫描的元素，若其值不在s到t之间，则前移k个位置；否则删除该元素，并k++
    /*
     * int i, k;
     * if ( L.length == 0 || s > t )
     *      return ERROR;
     * for ( i = 0; i < L.length; i++ )
     * {
     *      if ( *(L.elem + i) >= s && *(L.elem + i) <= t )
     *          k++;
     *      else
     *          *(L.elem + i - k) = *(L.elem + i);
     * }
     * L.length -= k;
     */

    return 0;
}

/*
 * 从有序表中删除值重复的元素
 * 思路：用类似于直接插入排序的思想
 *      初始时将第一个元素看作是非重复的有序表，之后依次判断后面的元素是否与前面的非重复有序表的最后一个元素相同，
 *      相同则继续往后判断，不同则插入前面的非重复有序表
 */
int delete_repeat(Sqlist &L)
{
    if ( L.length == 0 )
        return ERROR;
    int i, j;
    for ( i = 0, j = 1; j < L.length; j++ )
        if ( *(L.elem + i) < *(L.elem + j) )
            *(L.elem + (++i)) = *(L.elem + j);
    L.length = i+1;

    return 0;
}

/* 
 * 将两个有序表合并为一个有序表
 * 思路：按顺序不断取下两个顺序表表头较小的节点存入新的表中*/
int merge_two_sorted(Sqlist La, Sqlist Lb, Sqlist &Lc)
{
    int i = 0, j = 0, k = 0;
    while ( i < La.length && j < Lb.length )
    {
        if ( *(La.elem + i) <= *(Lb.elem + j) )
            *(Lc.elem + k++) = *(La.elem + i++);
        else
            *(Lc.elem + k++) = *(Lb.elem + j++);
    }
    while ( i < La.length )
        *(Lc.elem + k++) = *(La.elem + i++);
    while ( j < Lb.length )
        *(Lc.elem + k++) = *(Lb.elem + j++);
    Lc.length = k;
        
    return 0;
}

/*
 * 将left到right的元素逆置
 */
void reverse_left_right(Sqlist L, int left, int right)
{
    if ( left <= right && right > L.length )
        exit(ERROR);
    int mid = (left + right) / 2;
    int i;
    ElemType e;
    for ( i = 0; i <= mid - left; i++ )
    {
        e = *(L.elem + left + i);
        *(L.elem + left + i) = *(L.elem + right - i);
        *(L.elem + right - i) = e;
    }
}

/*
 * 互换两个表的位置
 * 思路：经过三次逆置
 */
void revert_a_and_b(Sqlist La, Sqlist Lb, Sqlist &Lc)
{
    int i = 0, k = 0;
    while ( i < La.length )
        *(Lc.elem + k++) = *(La.elem + i++);
    i = 0;
    while ( i < Lb.length )
        *(Lc.elem + k++) = *(Lb.elem + i++);
    reverse_left_right(Lc, 0, k-1);
    reverse_left_right(Lc, 0, Lb.length-1);
    reverse_left_right(Lc, Lb.length, k-1);
}

/*
 * 求中位数
 */
int mid_search(Sqlist La, Sqlist Lb, int n)
{
    int fa = 0, la = n-1, ma;
    int fb = 0, lb = n-1, mb;

    while ( fa != la || fb != lb )
    {
        ma = (fa + la) / 2;
        mb = (fb + lb) / 2;
        if ( *(La.elem + ma) == *(Lb.elem + mb) )
            return *(La.elem + ma);
        else if ( *(La.elem + ma) < *(Lb.elem + mb) )
        {
            if ( (fa + la) % 2 == 0 )
            {
                fa = ma;
                lb = mb;
            }
            else 
            {
                fa = ma + 1;
                lb = mb;
            }
        }
        else
        {
            if ( (fb + lb) % 2 == 0 )
            {
                la = ma;
                fb = mb;
            }
            else
            {
                la = ma;
                fb = mb + 1;
            }
        }
    }
    return *(La.elem + fa) < *(Lb.elem + fb) ? *(La.elem + fa) : *(Lb.elem + fb);
}
