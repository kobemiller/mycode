#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p1 = malloc(4);
    int *p2 = malloc(4);
    int *p3 = malloc(4);
    int *p4 = malloc(4);
    int *p5 = malloc(4);

    printf("%p\n", p1);
    printf("%p\n", p2);
    printf("%p\n", p3);
    printf("%p\n", p4);
    printf("%p\n", p5);

    return 0;
}
