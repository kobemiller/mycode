// =====================================================================================
//
//       Filename:  udpA.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/17/2014 09:10:25 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int fd;                     //socket描述符号
    struct sockaddr_in ad;      //本机的IP地址
    char buf[100];              //接收数据缓冲
    struct sockaddr_in ad_snd;  //发送者IP
    socklen_t len;                //发送者IP长度
    int r;

    fd = socket(AF_INET, SOCK_DGRAM, 17);
    if ( fd == -1 )
        printf("socket: %m\n"), exit(-1);
    printf("建立socket成功\n");

    ad.sin_family = AF_INET;
    ad.sin_port = htons(9999);
    inet_aton("192.168.1.100", &ad.sin_addr);
    r = bind(fd, (struct sockaddr*)&ad, sizeof(ad));
    if ( r == -1 ) 
        printf("bind error: %m\n"), exit(-1);
    printf("绑定成功\n");

    len = sizeof(ad_snd);
    while ( 1 )
    {
        r = recvfrom(fd, buf, sizeof(buf), 0, (struct sockaddr*)&ad_snd, &len);
        if ( r > 0 )
        {
            buf[r] = 0;
            printf("发送者IP：%s, 数据: %s\n", inet_ntoa(ad_snd.sin_addr), buf);
        }
        if ( r == 0 )
            printf("关闭\n");
        if ( r == -1 )
        {
            printf("网络故障\n");
            close(fd);
            break;
        }
    }

    close(fd);
    return 0;
            
}
