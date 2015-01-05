#include <stdio.h>
#include <unistd.h>

int isPrimer(int a)
{
    int r = 0;
    int i;
    for ( i = 2; i < a; i++ )
    {
        if ( a % i == 0 )
            return 1;
    }
    return 0;
}

int main()
{
    int i = 2;
    int b;
    int *r;
    r = sbrk(0);
    for ( ; i < 10000; i++ )
    {
        b = isPrimer(i);
        if ( b == 0 )
        {
            brk(4);
            *r = i;
            r = sbrk(0);
        }
    }
    
    while ( )

    return 0;
}
