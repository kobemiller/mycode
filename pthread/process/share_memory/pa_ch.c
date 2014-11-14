#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int shm_id;
    int* shm_ptr;
    pid_t pid;
    int i;

    shm_id = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT|0777);
    shm_ptr = shmat(shm_id, NULL, 0);
    *shm_ptr = 0;
    pid = fork();
    if ( pid > 0 )
    {
        for ( i = 0; i < 30; i++ )
        {
            if ( *shm_ptr >= 10 )
            {
                printf("process(%d):fork to the max\n", getpid());
                exit(2);
            }
            printf("-%d-", *shm_ptr);
            sleep(1);
        }
    }
    else if ( pid == 0 )
    {
        for ( i = 0; i < 30; i++ ){
            printf("\n********\n");
            printf("process(%d):\n", getpid());
            (*shm_ptr)++;
            printf("-%d-", *shm_ptr);
            printf("\n********\n");
            sleep(1);
        }
    }
    return 0;
}
