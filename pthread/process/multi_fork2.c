#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int i, num = 5;
    pid_t p[num];
    for ( i = 0; i < num; i++ )  
        p[i] = fork();
    for ( i = 0; i < num; i++ )
        printf("pid[%d] = %d\n", i, p[i]);

    return 0;
}
