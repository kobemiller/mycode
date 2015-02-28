// =====================================================================================
//
//       Filename:  double_circle_link_list.cpp
//
//    Description:  循环双向链表练习
//
//        Version:  1.0
//        Created:  2015年02月28日 23时25分47秒
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
#include "../list/link_list/double_circle_linklist.h"

/*
 * 判断带头结点的循环双链表是否对称
 * 思路：p从左往右扫描，q从右往左扫描，直到他们指向同一节点（链表节点个数为奇数时）
 * 或者是相邻（链表节点为偶数时），若所指节点值相同，则继续进行，否则返回
 */
void duichen(DuLinkList L)
{
    DuLinkList p, n;
    p = L->prior;
    n = L->next;

    while ( n != p && n->next != p )
        if ( p->data == n->data )
        {
            p = p->prior;
            n = n->next;
        }
        else
        {
            printf("不对称\n");
            return;
        }
    printf("对称\n");
}

int main()
{
    DuLinkList La;
    int i, j;

    InitList(La);
    for ( i = 1; i < 5; i++ )
        ListInsert(La, i, i);
    for ( j = 4; j > 0; j-- )
        ListInsert(La, i++, j);
    ListTraverse(La, print);
    duichen(La);


    return 0;
}
