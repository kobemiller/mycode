#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "memdev.h"

int main()
{
    int fd = 0;
    int cmd;
    int arg = 0;
    char buf[4096];

    fd = open("/dev/memdev0", O_RDWR);
    if (fd < 0)
    {
        printf("open dev mem0 error!\n");
        return -1;
    }

    printf("<---call MEMDEV_IOCPRINT--->\n");
    cmd = MEMDEV_IOCPRINT;
    if (ioctl(fd, cmd, &arg) < 0)
    {
        printf("call cmd MEMDEV_IOCPRINT failed!\n");
        return -1;
    }

    printf("<---call MEMDEV_IOCSETDATA--->\n");
    cmd = MEMDEV_IOCSETDATA;
    if (ioctl(fd, cmd, &arg) < 0)
    {
        printf("call cmd MEMDEV_IOCSETDATA failed\n");
        return -1;
    }

    printf("<---call MEMDEV_IOCGETDATA--->\n");
    cmd = MEMDEV_IOCGETDATA;
    if (ioctl(fd, cmd, &arg) < 0)
    {
        printf("call cmd MEMDEV_IOCGETDATA failed\n");
        return -1;
    }
    printf("<---user space MEMDEV_IOCGETDATA get data is %d--->\n", arg);

    close(fd);
    return 0;
}
