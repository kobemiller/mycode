/*
 * =====================================================================================
 *
 *       Filename:  1.c
 *
 *    Description:  从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删除元素的值，空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行
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

int main()
{
    Sqlist La;
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
