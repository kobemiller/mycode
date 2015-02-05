// =====================================================================================
//
//       Filename:  double_circle_linklist_test.cpp
//
//    Description:  双向循环链表测试程序
//
//        Version:  1.0
//        Created:  2015年02月06日 01时25分08秒
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
#include "double_circle_linklist.h"

int main()
{
    DuLinkList L;
    int i, n;
    Status j;
    ElemType e;

    InitList(L);
    for ( i = 1; i <= 5; i++ )
        ListInsert(L, i, i);
    printf("正序输出链表：");
    ListTraverse(L, print);
    printf("逆序输出链表: ");
    ListTraverseBack(L, print);
    
    n = 2;
    ListDelete(L, n, e);
    printf("删除第%d个节点， 值为%d, 其余节点为 ", n, e);
    ListTraverse(L, print);
    
    printf("链表的元素个数为：%d\n", ListLength(L));
    printf("链表是否为空：%d(1:yes 0:no)\n", ListEmpty(L));
    ClearList(L);
    printf("清空后，链表是否为空：%d(1:yes 0:no)\n", ListEmpty(L));

    for ( i = 1; i <= 5; i++ )
        ListInsert(L, i, i);
    ListTraverse(L, print);
    n = 3;
    j = GetElem(L, n, e);
    if ( j )
        printf("链表的第%d个元素值为%d\n", n, e);
    else
        printf("不存在第%d个元素\n", n);
    
    n = 4;
    i = LocateElem(L, n, equal);
    if ( i )
        printf("等于%d的元素是第%d个\n", n, i);
    else
        printf("没有等于%d的元素\n", i);

    j = PriorElem(L, n, e);
    if ( j )
        printf("%d的前驱是%d\n", n, e);
    else
        printf("不存在%d的前驱\n", n);

    j = NextElem(L, n, e);
    if ( j )
        printf("%d的后继是%d\n", n, e);
    else
        printf("不存在%d的后继\n", n);
    
    DestroyList(L);

    return 0;
}
