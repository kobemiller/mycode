#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BLOCK_SIZE  100
#define BUF_SIZE    1000000

size_t bytesRead;

typedef struct
{
    pthread_mutex_t mutex;  //互斥量
    pthread_cond_t  cv;     //条件变量
    int             data;
} flag;

flag ourFlag = {
    PTHREAD_MUTEX_INITIALIZER,
    PTHREAD_COND_INITIALIZER,
    0
};

pthread_t thread1, thread2;     //等待线程
void* PrintCountRead(void* );   //线程函数

int main(int argc, char *argv[])
{
    FILE    *infile;
    char    *inbuf;
    int     status;

    if ( argc != 2 )
    {
        printf("Usage GetSetEvents filename\n");
        return (-1);
    }

    infile = fopen(argv[1], "r+b");
    if ( infile == NULL )
    {
        printf("Error opening %s\n", argv[1]);
        return (-1);
    }

    inbuf = (char*)malloc(BUF_SIZE);
    if ( inbuf == NULL )
    {
        printf("Could not allocate read buffer\n");
        return (-1);
    }

    //现在创建并启动两个新线程
    pthread_create(&thread1, NULL, PrintCountRead, (void*)NULL);
    pthread_create(&thread2, NULL, PrintCountRead, (void*)NULL);

    bytesRead = fread(inbuf, 1, BLOCK_SIZE, infile);
    if ( bytesRead < BLOCK_SIZE )
    {
        printf("Need a file longer than %d bytes\n", BLOCK_SIZE);
        return (-1);
    }
    else
    {
        //现在激发等待线程
        //首先，锁定互斥量
        status = pthread_mutex_lock(&ourFlag.mutex);
        if ( status != 0 )
        {
            printf("error locking mutex in main func.\n");
            exit(-1);
        }
        
        ourFlag.data = 1;   //更改数据项的值，然后广播该事件
        
        status = pthread_cond_broadcast(&ourFlag.cv);
        if ( status != 0 )
        {
            printf("error broadcasting condition var\n");
            exit(-1);
        }

        //释放互斥量
        status = pthread_mutex_unlock(&ourFlag.mutex);
        if ( status != 0 )
        {
            printf("error unlocking mutex in waiting function\n");
            exit(-1);
        }
    }

    while ( !feof(infile) && bytesRead < BUF_SIZE - BLOCK_SIZE )
        bytesRead += fread(inbuf, 1, BLOCK_SIZE, infile);

    printf("Read a total of %d bytes\n", (int)bytesRead);

    return 0;
}

//等待条件变量的线程函数
void *PrintCountRead(void* pv)
{
    int status;

    status = pthread_mutex_lock(&ourFlag.mutex);
    if ( status != 0 )
    {
        printf("error locking mutex in waiting func\n");
        exit(-1);
    }

    while ( ourFlag.data == 0 )
    {
        status = pthread_cond_wait(&ourFlag.cv, &ourFlag.mutex);
        if ( status != 0 )
        {
            printf("error waiting on condition variable\n");
            exit(-1);
        }
    }

    if ( ourFlag.data != 0 )
    {
        printf("condition was signaled. Main thread has read %06d bytes\n", (int)bytesRead);
    }

    status = pthread_mutex_unlock(&ourFlag.mutex);
    if ( status != 0 )
    {
        printf("error unlocking mutex in waiting func\n");
        exit(-1);
    }

    return pv;
}
