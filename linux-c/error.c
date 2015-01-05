#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

extern int errno;//方法3需要的全局变量

int main()
{
    void* p = sbrk(10000000000000000 * 3);
    if ( p == (void*)-1 )
        perror("sbrk");                     //方法1
        printf("%m\n");                     //方法2
        printf("%s\n", strerror(errno));    //方法3

    return 0;    
}
