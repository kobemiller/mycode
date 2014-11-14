#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>

int main()
{
    int     shm_id;
    char*   shm_ptr;
    pid_t   pid;
    
    shm_id = shmget(IPC_PRIVATE, (size_t)100, IPC_CREAT|0777);
    if ( shm_id == -1 )
    {
        perror("shmget");
        exit(1);
    }
    if ( (pid = fork()) == -1 )
        perror("fork");
    if ( pid == 0 )
    {
        shm_ptr = shmat(shm_id, NULL, 0);
        if ( shm_ptr == (void *)-1 )
        {
            perror("shmat");
            exit(2);
        }
        strcpy(shm_ptr, "kobemiller");
        shmdt(shm_ptr);
        return 0;
    }
    else ( pid > 0 )
    {
        sleep(3);
        shmctl(shmid, IPC_STAT, NULL);
    }
    reutrn 0;
}
