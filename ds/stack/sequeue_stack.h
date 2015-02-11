/*
 * =====================================================================================
 *
 *       Filename:  stack.h
 *
 *    Description:  栈的顺序存储
 *
 *        Version:  1.0
 *        Created:  2015年02月11日 11时16分53秒
 *       Revision:  none
 *       Compiler:  gcc
 * =====================================================================================
 */

#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2
struct SqStack
{
    SElemType   *base;
    SElemType   *top;
    int         stacksize;
};

void InitStack(SqStack &S)
{
    if ( !(S.base= (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType))) )
            exit(OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack &S)
{
    free(S.base);
    S.base = NULL;
    S.top = NULL;
    S.stacksize = 0;
}

void ClearStack(SqStack &S)
{
    S.top = S.base;
}

Status StackEmpty(SqStack S)
{
    if ( S.top == S.base )
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack S)
{
    return S.top - S.base;
}

Status GetTop(SqStack S, SElemType &e)
{
    if ( S.top > S.base )
    {
            e = *(S.top - 1);
            return OK;
    }
    else
            return ERROR;
}

void Push(SqStack &S, SElemType e)
{
    if ( S.top - S.base >= S.stacksize )
    {
        S.base = (SElemType *)realloc(S.base, (S.stacksize + STACK_INCREMENT) * sizeof(SElemType));
        if ( !S.base )
                exit(OVERFLOW);
        S.top = S.base + S.stacksize;
        S.stacksize += STACK_INCREMENT;
    }
    *(S.top)++ = e;
}

Status Pop(SqStack &S, SElemType &e)
{
    if ( S.top == S.base )
            return ERROR;
    e = *--S.top;
    return OK;
}

void StackTraverse(SqStack S, void (*visit)(SElemType))
{
    while ( S.top > S.base )
            visit(*S.base++);
    printf("\n");
}

void print(SElemType c)
{
    printf("%d ", c);
}


