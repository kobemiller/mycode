/*
 * 二级指针
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int main()
{
    char **p;
    char *tmp;
    int i, j;

    p = (char **)malloc(15 * sizeof(char *));
    for ( i = 0; i < 15; i++ )
        *(p+i) = (char *)malloc(256);
    for ( i = 0; i < 10; i++ )
        scanf("%s", *(p+i));
    printf("\n");

    for ( i = 0; i < 10; i++ )
        printf("%s\n", *(p+i));
    printf("\n");

    char **f, **t;
    f = p;
    t = &(p[1]);
    for ( i = 11; i >=2; i--)
    {
        printf("%s  %s\n", t[i], f[i]);
        t[i] = f[i];
    }

    for ( i = 0; i < 15; i++ )
        printf("%s\n", *(p+i));
    printf("\n");
    memmove(&(p[3]), &(p[2]), sizeof(char *) * 8);

    for ( i = 0; i < 15; i++ )
        printf("%s\n", *(p+i));
    printf("\n");

    return 0;
}
