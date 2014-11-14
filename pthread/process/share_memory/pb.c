#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

static int cnt = 0;
void handle();

int main()
{
    pid_t pid;
    int i;

    for ( i = 0; i < 20; i++ )
    {
        if ( (pid = fork()) == -1 )
        {
            perror("fork error");
            exit(1);
        }
        else if ( pid == 0 )
        {
            printf("process(%d):%d\n", getpid(), ++cnt);
            handle();
            return;
        }
        else if ( pid > 0 )
        {
            if ( cnt > 10 )
            {
                printf("fork to the max\n");
                return(1);
            }
        }
    }
    
    return 0;
}
void handle()
{
    pid_t pid;
    int status, i;
    if ( (pid = fork()) == -1 )
    {
        perror("fork error");
        exit(1);
    }
    if ( pid > 0 )
    {
        printf("process(%d): wait = %d\n", getpid(), wait(&status));
    }
    else if ( pid == 0 )
    {
        for ( i = 0; i < 30; i++ ){
            printf("\n********\n");
            printf("process(%d):%d\n", getpid(), i);
            printf("\n********\n");
            sleep(1);
        }
    }
    cnt--;
    return;
}
