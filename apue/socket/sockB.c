// =====================================================================================
//
//       Filename:  sockB.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/17/2014 12:47:02 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/un.h>

int main()
{
    int fd, r;
    struct sockaddr_un addr = {0};
    //建立socket
    fd = socket(AF_UNIX, SOCK_DGRAM, 0);
    //连接到指定的地址
    addr.sun_family = AF_UNIX;
    memcpy(addr.sun_path, "my.sock", strlen("my.sock"));
    r = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
    //发送数据
    write(fd, "hello world", strlen("hello world"));
    //关闭
    close(fd);
    return 0;
}
