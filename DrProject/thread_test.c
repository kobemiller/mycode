#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid)
{
    //本函数输出线程的标示符，然后退出
    printf("hello world. Greeting from thread %d0.\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUMBER_OF_THREADS];
    int status, i;

    for ( i = 0; i < NUMBER_OF_THREADS; i++ )
    {
            printf("main here. Creating thread %d0\n", i);
            status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);
            if ( status != 0 )
            {
                printf("oops. pthread_create returned error code %d0\n", status);
                exit(-1);
            }
    }
    sleep(1);

    return 0;
}
