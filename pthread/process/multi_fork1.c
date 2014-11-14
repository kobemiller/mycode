#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_process(int num)
{
    pid_t pid[num];
    int i;
    for ( i = 0; i < num; i++ )
    {
        if ( (pid[i] = fork()) == -1 )
        {
            perror("fork error\n");
            exit(1);
        }
        else if ( pid[i] == 0 )
        {
            pid[i] = getpid();
            exit(0);
        }
        else if ( pid[i] > 0 )
        {
            sleep(5);
            printf("The main process's pid = %d\n", getpid());
        }
    }
    for ( i = 0; i < num; i++ )
        printf("pid[%d] = %d\n", i, pid[i]);
}

int main()
{
    int num = 5;
    create_process(num);
    return 0;
}
