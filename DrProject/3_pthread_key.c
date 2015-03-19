#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <omp.h>

pthread_key_t key;

//add 1 
//for test TLS in parallel programming

void *func1()
{
    double d = 3.14;

    pthread_setspecific(key, &d);
    //add 1
    double *tmp_d = (double *)pthread_getspecific(key);

    printf("func1: %u\n", pthread_self());
    printf("func1: %f\n", *((double *)pthread_getspecific(key)));
    //add 1
    printf("func1: 0x%p\n", (double *)pthread_getspecific(key));
    printf("func1: %f\n", *tmp_d);

    //add 1
    *tmp_d = (*tmp_d) * 10;
    printf("func1: %f\n", *((double *)pthread_getspecific(key)));
    printf("---------------------\n");
}

void *func2()
{
    int i = 5;

    pthread_setspecific(key, &i);
    //add 1
    int * tmp_i = (int *)pthread_getspecific(key);

    printf("func2: %u\n", pthread_self());
    printf("func2: %d\n", *((int *)pthread_getspecific(key)));
    //add 1
    printf("func2: 0x%p\n", (int *)pthread_getspecific(key));
    printf("func2: %d\n", *tmp_i);

    //add 1
    *tmp_i = (*tmp_i) * 10;
    printf("func2: %d\n", *((int *)pthread_getspecific(key)));
    printf("--------------------\n");
}

int main()
{
    pthread_t t1, t2;
    //add 1
    int i;

    pthread_key_create(&key, NULL);

#pragma omp parallel for
    //add 1
    for ( i = 0; i < 5; i++ )
    {
        pthread_create(&t1, NULL, func1, NULL);
        pthread_create(&t2, NULL, func2, NULL);
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    return 0;
}
