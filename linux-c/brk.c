#include <stdio.h>
#include <unistd.h>

int main()
{
    int* p = sbrk(4);       //分配4字节整数
    *p = 888;
    printf("*p: %d\n", *p);
    

    return 0;
}
