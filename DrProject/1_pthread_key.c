#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_key_t key;

struct test_struct
{
    int i;
    float k;
};

void *child1(void* arg)
{
    struct test_struct struct_data;

    struct_data.i = 10;
    struct_data.k = 3.1415;

    pthread_setspecific(key, &struct_data);
    printf("结构体struct_data的地址为 0x%p\n", &(struct_data));
    printf("child1中pthread_getspecific(key)返回指针为：0x%p\n", (struct test_struct *)pthread_getspecific(key));

    printf("利用pthread_getspecific(key)打印child1线程中与key关联的结构体成员值：\nstruct_data.i：%d\nstruct_data.k：%f\n",
            ((struct test_struct *)pthread_getspecific(key))->i, ((struct test_struct *)pthread_getspecific(key))->k);
    printf("---------------------------------------------------\n");
}

void *child2(void* arg)
{
    int temp = 20;
    sleep(2);
    printf("child2中变量temp的地址为0x%p\n", &temp);
    pthread_setspecific(key, &temp);
    printf("child2中pthread_getspecific(key)返回的指针为：0x%p\n", (int *)pthread_getspecific(key));

    printf("利用pthread_getspecific(key)打印child2线程中与key关联的整形变量temp的值：%d\n", *((int*)pthread_getspecific(key)));
}

int main()
{
    pthread_t tid1, tid2;

    pthread_key_create(&key, NULL);

    pthread_create(&tid1, NULL, (void*)child1, NULL);
    pthread_create(&tid2, NULL, (void*)child2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    pthread_key_delete(key);

    return 0;
}
