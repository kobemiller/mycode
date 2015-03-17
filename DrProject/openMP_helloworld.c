#include <stdio.h>
#include <omp.h>

int main()
{
    int i, j;

    printf("hello from serial.\n");
    printf("Thread number = %d\n", omp_get_thread_num());
#pragma omp parallel
    {
        printf("hello from parallel. Thread number = %d\n", omp_get_thread_num());
    }
    printf("hello from serial again.\n");

#pragma omp parallel for private (j)
    for ( i = 0; i < 2; i++ )
        for ( j = 6; j < 10; j++ )
            printf("i = %d j = %d\n", i, j);

    printf("\n");
    for ( i = 0; i < 2; i++ )
#pragma omp parallel for
        for ( j = 6; j < 10; j++ )
            printf("i = %d j = %d\n", i, j);

    return 0;
}
