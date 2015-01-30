// =====================================================================================
//
//       Filename:  test.c
//
//    Description:  顺序表的检验主程序
//
//        Version:  1.0
//        Created:  2015年01月30日 01时21分01秒
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

//判定平方关系
Status sq(ElemType c1, ElemType c2)
{
    if ( c1 == c2 * c2 )
        return TRUE;
    else 
        return FALSE;
}

//元素值加倍
void dbl(ElemType &c)
{
    c *= 2;
}

int main()
{
    Sqlist L;
    ElemType e, e0;
    Status i;
    int j, k;
    
    InitList(L);
    printf("初始化后：L.elem = %d, L.length = %d, L.listsize = %d\n", L.elem, L.length, L.listsize);

    for ( j = 1; j <= 5; j++ )
        i = ListInsert_before(L, 1, j);
    printf("在L的表头依次插入1~5后：");
    for ( j = 1; j <= 5; j++ )
        printf("%d, ", *(L.elem + j - 1));
    printf("\n");
    printf("插入后：L.elem = %d, L.length = %d, L.listsize = %d\n", L.elem, L.length, L.listsize);

    i = ListEmpty(L);
    printf("L是否空：i = %d(1:是 0:否)\n", i);

    ClearList(L);
    printf("清空L后：L.elem = %d, L.length = %d, L.listsize = %d\n", L.elem, L.length, L.listsize);

    for ( j = 1; j <= 10; j++ )
        i = ListInsert_before(L, j, j);
    printf("在L的表尾依次插入1~10后：");
    for ( j = 1; j <= 10; j++ )
        printf("%d, ", *(L.elem + j - 1));
    printf("\n");
    printf("插入后：L.elem = %d, L.length = %d, L.listsize = %d\n", L.elem, L.length, L.listsize);

    ListInsert_before(L, 1, 0);
    printf("在L的表头插入0后：");
    for ( j = 1; j <= ListLength(L); j++ )
        printf("%d, ", *(L.elem + j - 1));
    printf("\n");
    printf("插入后：L.elem = %d, L.length = %d, L.listsize = %d\n", L.elem, L.length, L.listsize);

    GetElem(L, 5, e);
    printf("第5个元素的值为：%d\n", e);

    for ( j = 10; j <= 11; j++ )
    {
        k = LocateElem(L, j, equal);
        if ( k )
            printf("第%d个元素的值为%d\n", k, j);
        else
            printf("没有值为%d的元素\n", j);
    } 
    
    for ( j = 3; j <= 4; j++ )
    {
        k = LocateElem(L, j, sq);
        if ( k )
            printf("第%d个元素的值为%d的平方\n", k, j);
        else
            printf("没有值为%d的平方的元素\n", j);
    }

    for ( j = 1; j <= 2; j++ )
    {
        GetElem(L, j, e0);
        i = PriorElem(L, e0, e);
        if ( i == INFEASIBLE )
            printf("元素%d无前驱\n", e0);
        else
            printf("元素%d的前驱为：", e0, e);
    }

    for ( j = ListLength(L)-1; j <=ListLength(L); j++ )
    {
        GetElem(L, j, e0);
        i = NextElem(L, e0, e);
        if ( i == INFEASIBLE )
            printf("元素%d无后继\n", e0);
        else
            printf("元素%d的后继为%d\n", e0, e);
    }

    k = ListLength(L);
    for ( j = k+1; j >=k; j-- )
    {
        i = ListDelete(L, j, e);
        if ( i == ERROR )
            printf("删除第%d个元素失败\n", j);
        else
            printf("删除第%d个元素成功，其值为%d\n", j, e);
    }

    printf("依次输出L的元素：");
    ListTraverse(L, print1);
    printf("加倍后:");
    ListTraverse(L, dbl);
    ListTraverse(L, print1);

    DestroyList(L);

    printf("销毁后：L.elem = %d, L.length = %d, L.listsize = %d\n", L.elem, L.length, L.listsize);

    return 0;
}
