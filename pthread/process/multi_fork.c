#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void create_process(int num)
{
    pid_t pid;
    int i;
    for ( i = 0; i < num; i++ )
    {
        pid = fork();
        if ( pid == 0 || pid == -1 )
            break;
    }
    if ( pid == -1 )
    {
        perror("fork error\n");
        exit(1);
    }
    else if ( pid == 0 )
    {
        printf("child pid = %d, parent pid = %d\n", getpid(), getppid());
        exit(0);
    }
    else
    {
        printf("parent pid = %d\n", getpid());
        sleep(5);
        exit(0);
    }
}

int main()
{
    int num = 8;
    create_process(num);
    return 0;
}
