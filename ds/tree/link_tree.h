// =====================================================================================
//
//       Filename:  link_tree.h
//
//    Description:  二叉树的二叉链表存储结构
//
//        Version:  1.0
//        Created:  2015年03月05日 13时24分08秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

typedef struct BiTNode
{
    TElemType   data;
    BiTNode     *lchild, *rchild;
}BiTNode, *BiTree;

void InitBiTree(BiTree &T)
{
    T = NULL;
}

void DestroyBiTree(BiTree &T)
{
    if ( T )
    {
        if ( T->lchild )
            DestroyBiTree(T->lchild);
        if ( T->rchild )
            DestroyBiTree(T->rchild);
        free(T);
        T = NULL;
    }
}

void PreOrderTraverse(BiTree T, void (*Visit)(TElemType))
{
    if ( T )
    {
        Visit(T->data);
        PreOrderTraverse(T->lchild, Visit);
        PreOrderTraverse(T->rchild, Visit);
    }
}

void InOrderTraverse(BiTree T, void (*Visit)(TElemType))
{
    if ( T )
    {
        InOrderTraverse(T->lchild, Visit);
        Visit(T->data);
        InOrderTraverse(T->rchild, Visit);
    }
}

#define ClearBiTree DestroyBiTree

void CreateBiTree(BiTree &T)
{
    TElemType ch;
    scanf("form, &ch");
    if ( ch == Nil )
        T = NULL;
    else
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        if ( !T )
            exit(OVERFLOW);
        T->data = ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

Status BiTreeEmpty(BiTree T)
{
    if ( T )
        return FALSE;
    else
        return TRUE;
}

int BiTreeDepth(BiTree T)
{
    int i, j;
    if ( !T )
        return 0;
    if ( T->lchild )
        i = BiTreeDepth(T->lchild);
    else
        i = 0;
    if ( T->rchild )
        j = BiTreeDepth(T->rchild);
    else
        j = 0;
    return i > j ? i+1 : j+1;
}

TElemType Root(BiTree T)
{
    if ( BiTreeEmpty(T) )
        return Nil;
    else
        return T->data;
}

TElemType Value(BiTree p)
{
    return p->data;
}

void Assign(BiTree p, TElemType value)
{
    p->data = value;
}

typedef BiTree QElemType;
#include "../queue/link_queue.h"

TElemType Parent(BiTree T, TElemType e)
{
    LinkQueue q;
    QElemType a;
    if ( T )
    {
        InitQueue(q);
        EnQueue(q, T);
        while ( !QueueEmpty(q) )
        {
            DeQueue(q, a);
            if ( a->lchild && a->lchild->data == e || a->rchild && a->rchild->data == e )
                return a->data;
            else
            {
                if ( a->lchild )
                    EnQueue(q, a->lchild);
                if ( a->rchild )
                    EnQueue(q, a->rchild);
            }
        }
    }
    return Nil;
}

BiTree Point(BiTree T, TElemType s)
{
    LinkQueue q;
    QElemType a;
    if ( T )
    {
        InitQueue(q);
        EnQueue(q, T);
        while ( !QueueEmpty(q) )
        {
            DeQueue(q, a);
            if ( a->data == s )
                return a;
            if ( a->lchild )
                EnQueue(q, a->lchild);
            if ( a->rchild )
                EnQueue(q, a->rchild);
        }
    }
    return NULL;
}

TElemType LeftChild(BiTree T, TElemType e)
{
    BiTree a;
    if ( T )
    {
        a = Point(T, e);
        if ( a && a->lchild )
            return a->lchild->data;
    }
    return Nil;
}

TElemType RightChild(BiTree T, TElemType e)
{
    BiTree a;
    if ( T )
    {
        a = Point(T, e);
        if ( a && a->rchild )
            return a->rchild->data;
    }
    return Nil;
}

TElemType LeftSibling(BiTree T, TElemType e)
{
    TElemType a;
    BiTree p;
    if ( T )
    {
        a = Parent(T, e);
        if ( a != Nil )
        {
            p = Point(T, a);
            if ( p->lchild && p->rchild && p->rchild->data == e )
                return p->lchild->data;
        }
    }
    return Nil;
}

TElemType RightSibling(BiTree T, TElemType e)
{
    TElemType a;
    BiTree p;
    if ( T )
    {
        a = Parent(T, e);
        if ( a != Nil )
        {
            p = Point(T, a);
            if ( p->lchild && p->rchild && p->lchild->data == e )
                return p->rchild->data;
        }
    }
    return Nil;
}

Status InsertChild(BiTree p, int LR, BiTree c)
{
    if ( p )
    {
        if ( LR == 0 )
        {
            c->rchild = p->lchild;
            p->lchild = c;
        }
        else
        {
            c->rchild = p->rchild;
            p->rchild = c;
        }
        return OK;
    }
    return ERROR;
}

Status DeleteChild(BiTree p, int LR)
{
    if ( p )
    {
        if ( LR == 0 )
            ClearBiTree(p->lchild);
        else
            ClearBiTree(p->rchild);
        return OK;
    }
    return ERROR;
}

typedef BiTree SElemType;
#include "../stack/sequeue_stack.h"

void InOrderTraverse1(BiTree T, void (*Visit)(TElemType))
{
    SqStack S;
    InitStack(S);
    while ( T || !StackEmpty(S) )
    {
        if ( T )
        {
            Push(S, T);
            T = T->lchild;
        }
        else
        {
            Pop(S, T);
            Visit(T->data);
            T = T->rchild;
        }
    }
    printf("\n");
}

void InOrderTraverse2(BiTree T, void (*Visit)(TElemType))
{
    SqStack S;
    BiTree p;
    InitStack(S);
    Push(S, T);
    while ( !StackEmpty(S) )
    {
        while ( GetTop(S, p) && p )
            Push(S, p->lchild);
        Pop(S, p);
        if ( !StackEmpty(S) )
        {
            Pop(S, p);
            Visit(p->data);
            Push(S, p->rchild);
        }
    }
    printf("\n");
}

void PostOrderTraverse(BiTree T, void (*Visit)(TElemType))
{
    if ( T )
    {
        PostOrderTraverse(T->lchild, Visit);
        PostOrderTraverse(T->rchild, Visit);
        Visit(T->data);
    }
}

void LevelOrderTraverse(BiTree T, void (*Visit)(TElemType))
{
    LinkQueue q;
    QElemType a;
    if ( T )
    {
        InitQueue(q);
        EnQueue(q, T);
        while ( !QueueEmpty(q) )
        {
            DeQueue(q, a);
            Visit(a->data);
            if ( a->lchild != NULL )
                EnQueue(q, a->lchild);
            if ( a->rchild != NULL )
                EnQueue(q, a->rchild);
        }
        printf("\n");
    }
}

void visitT(TElemType e)
{
    printf(form" " , e);
}

