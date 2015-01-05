// =====================================================================================
//
//       Filename:  tid.c
//
//    Description:  打印线程ID
//
//        Version:  1.0
//        Created:  12/26/2014 10:21:22 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================
#include "../apue.h"
#include "../myerr.h"
#include <pthread.h>
int log_to_stderr = 1;

pthread_t ntid;

void printids(const char* s)
{
    pid_t       pid;
    pthread_t   tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid, 
            (unsigned long)tid, (unsigned long)tid);
}

void* thr_fn(void* arg)
{
    printids("new thread: ");
    return ((void*)0);
}

int main()
{
    int err;
    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if ( err != 0 )
        err_exit(err, "can't create thread");
    printids("main thread: ");
    sleep(1);

    return 0;
}
