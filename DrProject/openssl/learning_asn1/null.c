/*
 * 说明赋值为NULL的语句为假
 */
#include <stdio.h>

int main()
{
    int *h;
    printf("%d\n", ((h = NULL) ? 5 : 9));
}
