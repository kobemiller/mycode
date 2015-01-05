#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int a = 9999;

int main()
{
    char filename[100];
    int fd;
    int data;
    //得到文件名
    sprintf(filename, "/proc/%d/mem", getpid());
    //打开文件
    fd = open(filename, O_RDWR);
    if ( fd == -1 )
    {
        printf("open error\n");
        exit(-1);
    }
    //读取a地址这个位置的数据
    pread(fd, &data, 4, (int)&a);
    printf("%d\n", data);
    close(fd);

    return 0;
}
