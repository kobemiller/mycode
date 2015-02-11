/*
 * =====================================================================================
 *
 *       Filename:  link_stack_test.cpp
 *
 *    Description:  链栈的测试程序
 *
 *        Version:  1.0
 *        Created:  2015年02月12日 03时12分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

typedef int SElemType;

#include "../ds.h"
#include "link_stack.h"

int main()
{
    int j;
    LinkStack s;
    SElemType e;

    InitStack(s);
    for ( j = 1; j <= 5; j++ )
            Push(s, 2*j);
    printf("栈中的元素从栈底到栈顶依次为: ");
    StackTraverse(s, print);
    Pop(s, e);
    printf("弹出栈顶元素为 %d\n", e);
    GetTop(s, e);
    printf("当前栈顶元素为 %d, 栈的长度为 %d\n", e, StackLength(s));
    ClearStack(s);
    printf("清空栈后，栈空否：%d(1:yes 0:no), 栈的长度为 %d\n", StackEmpty(s), StackLength(s));
    DestroyStack(s);

    return 0;
}
