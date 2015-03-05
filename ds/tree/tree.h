// =====================================================================================
//
//       Filename:  tree.h
//
//    Description:  树的顺序存储结构
//                  显然，按层序输入二叉树是最方便的。
//                  二叉树的顺序存储结构适合存完全二叉树或近似完全二叉树
//
//        Version:  1.0
//        Created:  2015年03月05日 04时13分33秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include <iostream>

#define MAX_TREE_SIZE 100   //二叉树的最大节点数
typedef TElemType SqBiTree[MAX_TREE_SIZE];
struct position
{
    int level, order;       //节点的层，本层序号
};

#define ClearBiTree     InitBiTree
#define DestroyBiTree   InitBiTree

void InitBiTree(SqBiTree T)
{
    int i;
    for ( i = 0; i < MAX_TREE_SIZE; i++ )
        T[i] = Nil;
}

void CreateBiTree(SqBiTree T)
{
    int i = 0;
    InitBiTree(T);
#if CHAR
    int l;
    char s[MAX_TREE_SIZE];
    std::cout << "请按层序输入节点的值（字符）， 空格表示空节点，节点数<=" << MAX_TREE_SIZE << ": " << std::endl;
    gets(s);
    l = strlen(s);
    for ( ; i < l; i++ )
        T[i] = s[i];
#else
    std::cout << "请按层序输入节点的值（整数）， 0表示空节点，输入999结束。节点数<=" << MAX_TREE_SIZE << ": " << std::endl;

    while ( 1 )
    {
        std::cin >> T[i];
        if ( T[i] == 999 )
        {
            T[i] = Nil;
            break;
        }
        i++;
    }
#endif
    for ( i = 1; i < MAX_TREE_SIZE; i++ )
        if ( i != 0 && T[(i+1) / 2 - 1] == Nil && T[i] != Nil )
        {
            std::cout << "出现无双亲的非根节点" << T[i] << std::endl;
            exit(ERROR);
        }
}

Status BiTreeEmpty(SqBiTree T)
{
    if ( T[0] == Nil )
        return TRUE;
    else
        return FALSE;
}

int BiTreeDepth(SqBiTree T)
{
    int i, j = -1;
    for ( i = MAX_TREE_SIZE - 1; i >= 0; i-- )
        if ( T[i] != Nil )
            break;
    i++;
    do
        j++;
    while ( i >= pow(2, j) );
    return j;
}

Status Root(SqBiTree T, TElemType &e)
{
    if ( BiTreeEmpty(T) )
        return ERROR;
    else
    {
        e = T[0];
        return OK;
    }
}

TElemType Value(SqBiTree T, position e)
{
    return T[int(pow(2, e.level - 1) + e.order - 2)];
}

Status Assign(SqBiTree T, position e, TElemType value)
{
    int i = int(pow(2, e.level - 1) + e.order - 2);
    if ( value != Nil && T[(i+1) / 2 - 1] == Nil )
        return ERROR;
    else if ( value == Nil && (T[i*2 + 1] != Nil || T[i*2 + 2] != Nil) )
        return ERROR;
    T[i] = value;
    return OK;
}

TElemType Parent(SqBiTree T, TElemType e)
{
    int i;
    if ( T[0] == Nil )
        return Nil;
    for ( i = 1; i <= MAX_TREE_SIZE; i++ )
        if ( T[i] == e )
            return T[(i+1) / 2 - 1];
    return Nil;
}

TElemType LeftChild(SqBiTree T, TElemType e)
{
    int i;
    if ( T[0] == Nil )
        return Nil;
    for ( i = 0; i <= MAX_TREE_SIZE - 1; i++ )
        if ( T[i] == e )
            return T[i*2 + 1];
    return Nil;
}

TElemType RightChild(SqBiTree T, TElemType e)
{
    int i;
    if ( T[0] == Nil )
        return Nil;
    for ( i = 0; i <= MAX_TREE_SIZE - 1; i++ )
        if ( T[i] == e )
            return T[i*2 + 2];
    return Nil;
}

TElemType LeftSibling(SqBiTree T, TElemType e)
{
    int i;
    if ( T[0] == Nil )
        return Nil;
    for ( i = 1; i <= MAX_TREE_SIZE - 1; i++ )
        if ( T[i] == e && i % 2 == 0 )
            return T[i - 1];
    return Nil;
}

TElemType RightSibling(SqBiTree T, TElemType e)
{
    int i;
    if ( T[0] == Nil )
        return Nil;
    for ( i = 1; i <= MAX_TREE_SIZE - 1; i++ )
        if ( T[i] == e && i % 2 )
            return T[i + 1];
    return Nil;
}

void Move(SqBiTree q, int j, SqBiTree T, int i)
{
    if ( q[2*j + 1] != Nil )
        Move(q, (2*j + 1), T, (2*i + 1));
    if ( q[2*j + 2] != Nil )
        Move(q, (2*j + 2), T, (2*i + 2));
    T[i] = q[j];
    q[j] = Nil;
}

void InsertChild(SqBiTree T, TElemType p, int LR, SqBiTree c)
{
    int j, k, i = 0;
    for ( j = 0; j < int(pow(2, BiTreeDepth(T))) - 1; j++ )
        if ( T[j] == p )
            break;
    k = 2 * j + 1 + LR;
    if ( T[k] != Nil )
        Move(T, k, T, 2*k + 2);
    Move(c, i, T, k);
}

typedef int QElemType;
#include "../queue/link_queue.h"

Status DeleteChild(SqBiTree T, position p, int LR)
{
    int i;
    Status k = OK;
    LinkQueue q;
    InitQueue(q);
    i = (int)pow(2, p.level - 1) + p.order - 2;
    if ( T[i] == Nil )
        return ERROR;
    i = i * 2 + 1 + LR;
    while ( k )
    {
        if ( T[2 * i + 1] != Nil )
            EnQueue(q, 2 * i + 1);
        if ( T[2 * i + 2] != Nil )
            EnQueue(q, 2 * i + 2);
        T[i] = Nil;
        k = DeQueue(q, i);
    }
    return OK;
}

void (*VisitFunc)(TElemType);
void PreTraverse(SqBiTree T, int e)
{
    VisitFunc(T[e]);
    if ( T[2*e + 1] != Nil )
        PreTraverse(T, 2*e + 1);
    if ( T[2*e + 2] != Nil )
        PreTraverse(T, 2*e + 2);

}

void PreOrderTraverse(SqBiTree T, void (*Visit)(TElemType))
{
    VisitFunc = Visit;
    if ( !BiTreeEmpty(T) )
        PreTraverse(T, 0);
    printf("\n");
}

void InTraverse(SqBiTree T, int e)
{
    if ( T[2*e + 1] != Nil )
        InTraverse(T, 2*e + 1);
    VisitFunc(T[e]);
    if ( T[2*e + 2] != Nil )
        InTraverse(T, 2*e + 2);
}

void InOrderTraverse(SqBiTree T, void (*Visit)(TElemType))
{
    VisitFunc = Visit;
    if ( !BiTreeEmpty(T) )
        InTraverse(T, 0);
    printf("\n");
}

void PostTraverse(SqBiTree T, int e)
{    
    if ( T[2*e + 1] != Nil )
        PostTraverse(T, 2*e + 1);
    if ( T[2*e + 2] != Nil )
        PostTraverse(T, 2*e + 2);
    VisitFunc(T[e]);
}

void PostOrderTraverse(SqBiTree T, void (*Visit)(TElemType))
{
    VisitFunc = Visit;
    if ( !BiTreeEmpty(T) )
        PostTraverse(T, 0);
    printf("\n");
}

void LevelOrderTraverse(SqBiTree T, void (*Visit)(TElemType))
{
    int i = MAX_TREE_SIZE - 1, j;
    while ( T[i] == Nil )
        i--;
    for ( j = 0; j <= i; j++ )
        if ( T[j] != Nil )
            Visit(T[j]);
    printf("\n");
}

void Print(SqBiTree T)
{
    int j, k;
    position p;
    TElemType e;

    for ( j = 1; j <= BiTreeDepth(T); j++ )
    {
        printf("第%d层: ", j);
        for ( k = 1; k <= pow(2, j-1); k++ )
        {
            p.level = j;
            p.order = k;
            e = Value(T, p);
            if ( e != Nil )
                printf("%d: %d ", k, e);
        }
        printf("\n");
    }
}

void visit(TElemType e)
{
    std::cout << e << ' ';
}

