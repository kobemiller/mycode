#include <stdio.h>
/* 
int add(int a, int b)
{
    return a + b;
}

int main()
{
    int (*fun)(int) = add;
    //int (*fun)(int) = (int(*)(int))add;
    int r = fun(20);
    printf("r = %d\n", r);

    return 0;
}
*/
int __attribute__((fastcall)) add1(int* a, int* b)
{
    return *a + *b;
}
int __attribute__((stdcall)) add2(int* a, int* b)
{
    return (*a) * (*b);
}
int __attribute__((cdecl)) add3(int* a, int* b)
{
    return (*a) - (*b);
}

int main()
{
    int a = 20;
    int b = 10;
    int r1 = add1(&a, &b);
    int r2 = add2(&a, &b);
    int r3 = add3(&a, &b);

    printf("r1: %d\n", r1);
    printf("r2: %d\n", r2);
    printf("r3: %d"\n), r3;

    return 0;
}

