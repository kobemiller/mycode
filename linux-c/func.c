#include <stdio.h>
#include <stdlib.h>

int add(int a, int b)
{
    return a + b;
}

int a1 = 1;
static int a2 = 2;
const int a3 = 3;

int main()
{
    int b1 = 4;
    static b2 = 5;
    const b3 = 6;
    int* p1 = malloc(4);

    printf("a1:     %p\n", &a1);
    printf("a2:     %p\n", &a2);
    printf("a3:     %p\n", &a3);
    printf("b1:     %p\n", &b1);
    printf("b2:     %p\n", &b2);
    printf("b3:     %p\n", &b3);
    printf("p1:     %p\n", p1);
    printf("main:   %p\n", main);
    printf("add:    %p\n", add);
    printf("pid:    %d\n", getpid());

    while (1);

    return 0;
}
