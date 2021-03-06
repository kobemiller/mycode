typedef int ElemType;

#include "../../ds.h"
#include "../../func.h"
#include "linklist.h"

int main()
{
	LinkList L;
	ElemType e, e0;
	Status i;
	int j, k;

	InitList(L);
	for ( j = 1; j <= 5; j++ )
		i = ListInsert(L, 1, j);
    printf("1~5:L = ");
    ListTraverse(L, print);

	i = ListEmpty(L);
    printf("L真真i = %d(1:yes 0:no)\n", i);

	ClearList(L);
    printf("真L真");
    ListTraverse(L, print);

	i = ListEmpty(L);
    printf("L真真i = %d(1:yes 0:no)\n", i);

	for ( j = 1; j <= 10; j++ )
		ListInsert(L, j, j);
    printf("�L真真真�1~10�L = ");
	ListTraverse(L, print);

	GetElem(L, 5, e);
    printf("�5真真真%d\n", e);

	for ( j = 0; j <=1; j++ )
	{
		k = LocateElem(L, j, equal);
		if ( k )
            printf("�%d真真真%d\n", k, j);
		else
            printf("真真%d真�\n", j);
	}

	for ( j = 1; j <= 2; j++ )
	{
		GetElem(L, j, e0);
		i = PriorElem(L, e0, e);
		if ( i == INFEASIBLE )
            printf("真%d真�\n", e0);
		else 
            printf("真%d真真%d\n", e0, e);
	}

	for ( j = ListLength(L) - 1; j <= ListLength(L); j++ )
	{
		GetElem(L, j, e0);
		i = NextElem(L, e0, e);

		if ( i == INFEASIBLE )
            printf("真%d真�\n", e0);
		else 
            printf("真%d真真%d\n", e0, e);
	}

	k = ListLength(L);
	for ( j = k+1; j >= k; j-- )
	{
		i = ListDelete(L, j, e);
		if ( i == ERROR )
            printf("真�%d真真�\n", j);
		else 
            printf("真�%d真真真真�%d\n", j, e);
	}

    printf("真真L真真");
	ListTraverse(L, print);
	DestroyList(L);

    return 0;
}
