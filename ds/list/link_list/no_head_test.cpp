// =====================================================================================
//
//       Filename:  no_head_test.c
//
//    Description:  不带头节点的单链表的测试程序
//
//        Version:  1.0
//        Created:  2015年02月04日 10时12分51秒
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
#include "no_head_linklist.h"

int main()
{
    LinkList L;
	ElemType e, e0;
	Status i;
	int j, k;

	InitList(L);
	for ( j = 1; j <= 5; j++ )
		i = ListInsert(L, 1, j);
	printf("在L的表头依次插入1~5后：L= ");
	i = ListEmpty(L);
	printf("L是否空：i = %d(1:是 0：否)\n", i);
	ClearList(L);
	printf("清空L后：L= ");
	i = ListEmpty(L);
	printf("L是否空：i = %d(1:是 0：否)\n", i);
	for ( j = 1; j <= 10; j++ )
		ListInsert(L, j, j);
	printf("在L的表尾依次插入1~10后：L= ");
	ListTraverse(L, print);
	GetElem(L, 5, e);
	printf("第5个元素的值为%d\n", e);
	for ( j = 0; j <=1; j++ )
	{
		k = LocateElem(L, j, equal);
		if ( k )
			printf("第%d个元素的值为%d\n", k, j);
		else
			printf("没有值为%d的元素\n", j);
	}
	for ( j = 1; j <= 2; j++ )
	{
		GetElem(L, j, e0);
		i = PriorElem(L, e0, e);
		if ( i == INFEASIBLE )
			printf("元素%d无前驱\n", e0);
		else
			printf("元素%d的前驱为%d\n", e0, e);
	}
	for ( j = ListLength(L) - 1; j <= ListLength(L); j++ )
	{
		GetElem(L, j, e0);
		i = NextElem(L, e0, e);
		if ( i == INFEASIBLE )
			printf("元素%d无后继\n", e0);
		else
			printf("元素%d的后继为%d\n", e0, e);
	}
	k = ListLength(L);
	for ( j = k+1; j >= k; j-- )
	{
		i = ListDelete(L, j, e);
		if ( i == ERROR )
			printf("删除第%d个元素失败\n", j);
		else
			printf("删除第%d个元素成功，其值为%d\n", j, e);
	}
	printf("依次输出L的元素：");
	ListTraverse(L, print);
	DestroyList(L);
	printf("销毁L后：L= %u\n", L);
}

