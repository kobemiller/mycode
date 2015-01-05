// =====================================================================================
//
//       Filename:  shmA.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/09/2014 10:55:39 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>

int main()
{
    key_t key;
    int shmid;
    int *p;
    //1、创建共享内存shmget
    key = ftok(".", 255);
    if ( key == -1 )
        printf("ftok error:%m\n"), exit(-1);
    shmid = shmget(key, 4, IPC_CREAT|IPC_EXCL|0666);
    if ( shmid == -1 )
        printf("shmget error:%m\n"), exit(-1);
    //2、挂载共享内存shmat
    p = shmat(shmid, 0, 0);
    if ( p == (int*)-1 )
        printf("shmat error:\m"), exit(-1);
    //3、访问共享内存
    //4、卸载共享内存shmdt
    //5、删除共享内存shmctl
    shmctl(shmid, IPC_RMID, 0);
    return 0;
}
