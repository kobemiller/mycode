#include <pthread.h>
#include <stdio.h>
#include <string.h>

pthread_key_t p_key;
pthread_key_create(&p_key, NULL);

void func1()
{
    int *tmp = (int*)pthread_getspecific(p_key);
    printf("%d is running in %s\n", *tmp, __func__);
}

void *thread_func(void *args)
{
    printf("%d: before setspecific, p_key = %d\n", (int)pthread_self(), (int)p_key);
    pthread_setspecific(p_key, args);

    printf("%d: before getspecific, p_key = %d\n", pthread_self(), (int)p_key);
    int *tmp = (int*)pthread_getspecific(p_key);
    printf("%d: after getspecific, p_key = %d\n", pthread_self(), (int)p_key);
    printf("%d is running in %s\n", *tmp, __func__);

    *tmp = (*tmp) * 100;

    func1();
}

int main()
{
    pthread_t pa, pb;
    int a = 1;
    int b = 2;
    printf("processID:%d, threadID:%d\n", getpid(), pthread_self());
        pthread_create(&pb, NULL, thread_func, &b);
        pthread_create(&pa, NULL, thread_func, &a);
        pthread_join(pa, NULL);
        pthread_join(pb, NULL);

    printf("%d\n", (int)p_key);

    return 0;

}
