#include <stdio.h>
#include <unistd.h>     //相当于windows下的windows.h

int main()
{
    printf("pid: %d\n", getpid());
    while ( 1 );
    return 0;
}
