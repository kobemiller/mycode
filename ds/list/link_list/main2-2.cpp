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
    printf("L¿¿¿¿i = %d(1:yes 0:no)\n", i);

	ClearList(L);
    printf("¿¿L¿¿");
    ListTraverse(L, print);

	i = ListEmpty(L);
    printf("L¿¿¿¿i = %d(1:yes 0:no)\n", i);

	for ( j = 1; j <= 10; j++ )
		ListInsert(L, j, j);
    printf("¿L¿¿¿¿¿¿¿1~10¿L = ");
	ListTraverse(L, print);

	GetElem(L, 5, e);
    printf("¿5¿¿¿¿¿¿%d\n", e);

	for ( j = 0; j <=1; j++ )
	{
		k = LocateElem(L, j, equal);
		if ( k )
            printf("¿%d¿¿¿¿¿¿%d\n", k, j);
		else
            printf("¿¿¿¿%d¿¿¿\n", j);
	}

	for ( j = 1; j <= 2; j++ )
	{
		GetElem(L, j, e0);
		i = PriorElem(L, e0, e);
		if ( i == INFEASIBLE )
            printf("¿¿%d¿¿¿\n", e0);
		else 
            printf("¿¿%d¿¿¿¿%d\n", e0, e);
	}

	for ( j = ListLength(L) - 1; j <= ListLength(L); j++ )
	{
		GetElem(L, j, e0);
		i = NextElem(L, e0, e);

		if ( i == INFEASIBLE )
            printf("¿¿%d¿¿¿\n", e0);
		else 
            printf("¿¿%d¿¿¿¿%d\n", e0, e);
	}

	k = ListLength(L);
	for ( j = k+1; j >= k; j-- )
	{
		i = ListDelete(L, j, e);
		if ( i == ERROR )
            printf("¿¿¿%d¿¿¿¿¿\n", j);
		else 
            printf("¿¿¿%d¿¿¿¿¿¿¿¿¿%d\n", j, e);
	}

    printf("¿¿¿¿L¿¿¿¿");
	ListTraverse(L, print);
	DestroyList(L);

    return 0;
}
