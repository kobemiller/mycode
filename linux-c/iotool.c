#include <stdio.h>

int inputInt(const char* info)
{
    int r;
    printf("%s:\n", info);
    scanf("%d", &r);
    return r;
}
