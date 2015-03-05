/*
 * =====================================================================================
 *
 *       Filename:  sequeue_stack_test.cpp
 *
 *    Description:  顺序栈的测试程序
 *
 *        Version:  1.0
 *        Created:  2015年02月11日 21时34分45秒
 *       Revision:  none
 *       Compiler:  gcc
 * =====================================================================================
 */

typedef int SElemType;

#include "../ds.h"
#include "sequeue_stack.h"

int main()
{
    int j;
    SqStack s;
    SElemType e;
    InitStack(s);
    for ( j = 1; j <= 12; j++ )
            Push(s, j);
    printf("栈中元素依次为：");
    StackTraverse(s, print_SElemType);
    Pop(s, e);
    printf("弹出的栈顶元素 e = %d\n", e);
    GetTop(s, e);
    printf("栈顶元素 e = %d, 栈的长度 %d\n", e, StackLength(s));
    ClearStack(s);
    printf("清空栈后，栈空否：%d(1:yes 0:no)\n", StackEmpty(s));
    DestroyStack(s);
    printf("销毁栈后，s.top = %u, s.base = %u, s.stacksize = %d\n", 
                s.top, s.base, s.stacksize);

    return 0;
}
