// =====================================================================================
//
//       Filename:  circle_linklist_test.cpp
//
//    Description:  循环单链表测试程序
//
//        Version:  1.0
//        Created:  2015年02月05日 23时14分17秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

typedef int ElemType;

#include "../../ds.h"
#include "../../func.h"
#include "circle_linklist.h"

/*
int main()
{
    LinkList L;
    ElemType e;
    int j;
    Status i;

    InitList(L);
    i = ListEmpty(L);
    printf("L是否空 i = %d(1:yes 0:no)\n", i);
    ListInsert(L, 1, 3);
    ListInsert(L, 2, 5);

    i = GetElem(L, 1, e);
    j = ListLength(L);
    printf("L中数据元素个数= %d, 第1个数据元素的值为%d\n", j, e);
    printf("L中数据元素依次为 ");
    ListTraverse(L, print);
    PriorElem(L, 5, e);
    printf("5前面的元素的值为%d\n", e);
    NextElem(L, 3, e);
    printf("3后边的元素的值为%d\n", e);

    printf("L是否空 i = %d(1:yes 0:no)\n", ListEmpty(L));
    j = LocateElem(L, 5, equal);
    if ( j )
        printf("L 的第%d个元素为5\n", j);
    else
        printf("不存在值为5的元素\n");
    i = ListDelete(L, 2, e);
    printf("删除的第二个元素：%d\n", e);
    if ( i )
    {
        printf("删除的元素值为%d, 现在L中的数据元素依次为", e);
        ListTraverse(L, print);
    }
    else
        printf("删除不成功\n");
    ClearList(L);
    printf("清空L后， L是否空: %d(1:yes 0:no)\n", ListEmpty(L));
    DestroyList(L);

    return 0;
}
*/

/*
 * test for mergelist
 */
int main()
{
    int n = 5, i;
    LinkList La, Lb;

    InitList(La);
    for ( i = 1; i <= n; i++ )
        ListInsert(La, i, i);
    printf("La = ");
    ListTraverse(La, print);

    InitList(Lb);
    for ( i = 1; i <= n; i++ )
        ListInsert(Lb, i, i*2);
    printf("Lb = ");
    ListTraverse(Lb, print);

    //MergeList(La, Lb);
    La = La->next;
    Lb = Lb->next;
    merge_list_head(La, Lb);
    printf("La + Lb = ");
    ListTraverse(La, print);

    return 0;
}
