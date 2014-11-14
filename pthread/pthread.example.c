#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
pthread_t ntid;
void print_tids(const char *s)
{
    pid_t pid;
    pthread_t tid;
    pid = getpid();
    tid = pthread_self();
    printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);
}
void *thr_fn(void *arg)
{
    print_tids("new thread:");
}
int main()
{
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if ( err != 0 )
        perror("can't create thread"), exit(-1);
    print_tids("main thread:");
    sleep(1);

    return 0;
}
