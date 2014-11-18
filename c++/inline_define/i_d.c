#include <stdio.h>

int foo(int x)
{
    int result;
    result = x * x;
    return result;
}

int main()
{
    printf("***hello***\n");

    int a = foo(3);
    printf("a = %d\n", a);

    int b = foo(a++);
    printf("b = %d\n", b);

    return 0;
}
