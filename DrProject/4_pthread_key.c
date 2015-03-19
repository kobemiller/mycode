/*
 * 使用TLS，测试多线程效率
 * gcc -g 4_pthread_key.c -pthread -openmp 测试并行模式下程序的执行时间
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <omp.h>
#include <sys/time.h>

pthread_key_t key;

#define THREAD_NUM  50

void *thread()
{
    long i = 0;
    pthread_setspecific(key, &i);
    struct timeval start, end;
    float time_cost;

    long * count = (long *)pthread_getspecific(key);
    gettimeofday(&start, NULL);

    for ( i; i < 100000000; i++ )
        (*count)++;
    
    gettimeofday(&end, NULL);
    time_cost = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
    time_cost /= 1000000;

    printf("%u: *count = %ld, i = %ld, time_cost = %f\n", pthread_self(), *count, i, time_cost);
}

int main()
{
    pthread_t tid[THREAD_NUM];
    int i;
    pthread_key_create(&key, NULL);

#pragma omp parallel for
    for ( i = 0; i < THREAD_NUM; i++ )
        pthread_create(&tid[i], NULL, thread, NULL);
#pragma omp parallel for
    for ( i = 0; i < THREAD_NUM; i++ )
        pthread_join(tid[i], NULL);

    pthread_key_delete(key);
    return 0;
}
