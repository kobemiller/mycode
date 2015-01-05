// =====================================================================================
//
//       Filename:  sockA.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/17/2014 12:25:02 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <linux/un.h>

int main()
{
    int fd, r;
    char* buf;
    //建立socket
    fd = socket(AF_UNIX, SOCK_DGRAM, 0);
    if ( fd == -1 )
        printf("socket error: %m\n"), exit(-1);
    //构造本地文件地址
    struct sockaddr_un addr = {0};
    addr.sun_family = AF_UNIX;
    memcpy(addr.sun_path, "my.sock", strlen("my.sock"));
    //绑定socket到地址
    r = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    if ( r == -1 )
        printf("bind error: %m\n"), exit(-1);
    printf("地址绑定成功\n");
    //接收数据
    bzero(buf, sizeof(buf));
    r = read(fd, buf, sizeof(buf));
    buf[r] = 0;
    printf("%s\n", buf);
    //关闭
    close(fd);
    //删除socket文件

    return 0;
}
