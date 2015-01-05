// =====================================================================================
//
//       Filename:  demo1clnt.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/18/2014 02:37:57 AM
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
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

int main()
{
    int sfd;
    int ffd;
    int r;
    int rv;
    int len;
    char buf[128];
    struct sockaddr_in dr;
    char filename[] = "udpA.c";

    //1、建立socket
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if ( sfd == -1 )
        printf(":%m\n"), exit(-1);
    printf("socket成功\n");

    //2、连接到服务器
    dr.sin_family = AF_INET;
    dr.sin_port = htons(9988);
    inet_aton("192.168.1.100", &dr.sin_addr);
    r = connect(sfd, (struct sockaddr*)&dr, sizeof(dr));
    if ( r == -1 )
        printf(":%m\n"), close(sfd), exit(-1);
    printf("connect成功\n");

    //3、打开文件
    ffd = open(filename, O_RDONLY);
    if ( ffd == -1 )
        printf(":%m\n"), close(sfd), exit(-1);
    printf("open成功\n");

    //4、发送文件名
    len = strlen(filename);
    r = send(sfd, &len, sizeof(len), 0);
    r = send(sfd, filename, len, 0);
    if ( r == -1 )
        printf(":%m\n"), close(sfd), exit(-1);
    printf("发送文件名成功\n");

    //5、循环发送数据
    while ( 1 )
    {
        r = read(ffd, buf, 128);
        if ( r == -1 )
            break;
        else if ( r == 0 )
            break;
        else if ( r > 0 )
        {
            rv = send(sfd, &r, sizeof(r), 0);
            if ( rv == -1 )
                break;
            send(sfd, buf, r, 0);   
            if ( rv == -1 )
                break;
        }
    }
    //6、读取到文件尾，发送0数据包
    r = 0;
    rv = send(sfd, &r, sizeof(r), 0);
    close(ffd);
    close(sfd);
    printf("大功告成\n");

    return 0;
}
