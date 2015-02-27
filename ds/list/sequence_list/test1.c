// =====================================================================================
//
//       Filename:  test1.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  2015年01月30日 16时10分15秒
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
#include "sqlist.h"

void Union1(Sqlist &La, Sqlist &Lb)
{
    ElemType e;
    int i;
    int la_len, lb_len;
    la_len = ListLength(La);
    lb_len = ListLength(Lb);

    for ( i = 1; i <= lb_len; i++ )
    {
        GetElem(Lb, i, e);
        printf("e = %d\n", e);
        if ( !LocateElem(La, e, equal) )
            ListInsert_before(La, ++la_len, e);
    }
}
/* 
 * Union测试
int main()
{
    Sqlist La, Lb;
    int j;
    InitList(La);
    for ( j = 1; j <= 5; j++ )
        ListInsert_before(La, j, j);
    printf("La = ");
    ListTraverse(La, print1);

    InitList(Lb);
    for ( j = 1; j <= 5; j++ )
        ListInsert_before(Lb, j, 2*j);
    printf("Lb = ");
    ListTraverse(Lb, print1);

    Union(La, Lb);
    printf("new La = ");
    ListTraverse(La, print1);

    return 0;
}
*/

/* merge test
int main()
{
    Sqlist La, Lb, Lc;
    int j, a[4] = {3, 5, 8, 11}, b[7] = {2, 6, 8, 9, 11, 15, 20};

    InitList(La);
    for ( j = 1; j <= 4; j++ )
        ListInsert_before(La, j, a[j-1]);
    printf("La = ");
    ListTraverse(La, print1);
    InitList(Lb);
    for ( j = 1; j <= 7; j++ )
        ListInsert_before(Lb, j, b[j-1]);
    printf("Lb = ");
    ListTraverse(Lb, print1);

    MergeList(La, Lb, Lc);
    printf("Lc = ");
    ListTraverse(Lc, print1);

    return 0;
}
*/
 
int main()
{
    Sqlist La, Lb, Lc;
    int j;

    InitList(La);
    for ( j = 1; j <= 5; j++ )
        ListInsert_before(La, j, j);
    printf("La = ");
    ListTraverse(La, print1);

    InitList(Lb);
    for ( j = 1; j <= 5; j++ )
        ListInsert_before(Lb, j, 2*j);
    printf("Lb = ");
    ListTraverse(Lb, print1);

    MergeList2(La, Lb, Lc);
    printf("Lc = ");
    ListTraverse(Lc, print1);

    DestroyList(La);
    return 0;
}

