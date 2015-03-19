/*
 * 线程局部变量与__thread
 */

/*
 * 1、pthread_once可以保证在整个进程空间init_routine函数仅被调用一次（它解决了多线程环境中使得互斥量和初始化代码都被初始化一次的问题）
 * 2、pthread_key_create的参数之一指向一个析构函数指针，当某个线程终止时该析构函数将被调用，并用对于一个进程内的给定键，该函数只能被调用一次
 * 3、pthread_setspecific和pthread_getspecific函数用来存放和获取与一个键关联的值
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_key_t key;
pthread_once_t once = PTHREAD_ONCE_INIT;

static void destructor(void *ptr)
{
    free(ptr);
}

void init_once(void)
{
    pthread_key_create(&key, destructor);
}

static void *get_buf(void)
{
    pthread_once(&once, init_once);

    if ( (ptr = pthread_getspecific(key)) == NULL )
    {
        ptr = malloc(1024);
        pthread_setspecific(key, ptr);
    }

    return ptr;
}

static void *thread_fn(void *arg)
{
    char *ptr = (char*)get_buf();

    sprintf(ptr, "hello world");
    printf(">>%s\n", ptr);

    return NULL;
}

void test()
{
    int i, n = 10;
    pthread_t tids[10];

    for ( i = 0; i < n; i++ )
        pthread_create(&tids[i], NULL, thread_fn, NULL);

    for ( i = 0; i < n; i++ )
        pthread_join(&tids[i], NULL);
}

