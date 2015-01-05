// =====================================================================================
//
//       Filename:  get_exit_status.c
//
//    Description:  获取线程退出状态
//
//        Version:  1.0
//        Created:  12/26/2014 10:38:25 AM
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

void* thr_fn1(void* arg)
{
    printf("thread 1 returning\n");
    sleep(5);
    return((void*)1);
}

void* thr_fn2(void* arg)
{
    printf("thread 2 exiting\n");
    pthread_exit((void*)2);
}

int main()
{
    int         err;
    pthread_t   tid1, tid2;
    void        *tret;

    err = pthread_create(&tid1, NULL, thr_fn1, NULL);
    if ( err != 0 )
        err_exit(err, "can't create thread 1");
    err = pthread_create(&tid2, NULL, thr_fn2, NULL);
    if ( err != 0 )
        err_exit(err, "can't create thread 1");

    err = pthread_join(tid1, &tret);
    if ( err != 0 )
        err_exit(err, "can't join with thread1");
    printf("thread 1 exit code %ld\n", (long)tret);
    err = pthread_join(tid2, &tret);
    if ( err != 0 )
        err_exit(err, "can't join with thread2");
    printf("thread 2 exit code %ld\n", (long)tret);

    exit(0);
}
