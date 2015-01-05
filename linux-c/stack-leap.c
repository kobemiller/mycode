#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int a1 = 10;
    int a2 = 20;
    int a3 = 30;
    
    int* p1 = malloc(sizeof(int));
    int* p2 = malloc(sizeof(int));
    int* p3 = malloc(sizeof(int));

    printf("a1: %p\n", &a1);
    printf("a2: %p\n", &a2);
    printf("a3: %p\n", &a3);

    printf("p1: %p\n", p1);
    printf("p2: %p\n", p2);
    printf("p3: %p\n", p3);

    while ( 1 );
    return 0;
}
