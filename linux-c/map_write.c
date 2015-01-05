#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/mman.h>

struct stu
{
    char    name[20];
    int     age;
    float   score;
};

int main()
{
    int fd;
    struct stu *s;  //文件在虚拟内存的映射首地址
    struct stat st;
    int size;       //文件大小
    int count;      //记录条数
    struct stu record;

    memset(&record, 0, sizeof(struct stu));
    //打开文件
    fd = open("newstu.dat", O_RDWR|O_CREAT|O_EXCL, 0666); 
    if ( fd == -1 )
    {
        fd = open("newstu.dat", O_RDWR);
        if ( fd == -1 )
            printf(":%m\n"), exit(-1);
    }
    //得到文件大小，文件记录条数
    fstat(fd, &st);
    size = st.st_size;
    count = size / sizeof(struct stu);
    ftruncate(fd, size + sizeof(struct stu)); //文件大小改变只要在munmap之前调用都有效
    //映射到一个虚拟的地址
    s = mmap(0, size + sizeof(struct stu), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    //把数据写入虚拟地址
    printf("请输入姓名：");
    scanf("%s", s[count].name);
    printf("输入年龄：");
    scanf("%d", &(s[count].age));
    printf("输入成绩：");
    scanf("%f", &(s[count].score));

    //卸载虚拟地址
    munmap(s, sizeof(struct stu) + size);
    //关闭文件
    close(fd);

    return 0;
}
