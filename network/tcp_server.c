// =====================================================================================
//
//       Filename:  tcp_server.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/18/2014 12:28:13 AM
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
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int serverfd;
    int cfd;
    int r;
    struct sockaddr_in sadr;
    struct sockaddr_in cadr;
    socklen_t len;

    //1、socket
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if ( serverfd == -1 )
        printf("1:%m\n"), exit(-1);
    printf("建立服务器socket成功\n");

    //2、bind
    sadr.sin_family = AF_INET;
    sadr.sin_port = htons(9999);
    inet_aton("192.168.1.100", &sadr.sin_addr);
    r = bind(serverfd, (struct sockaddr*)&sadr, sizeof(sadr));
    if ( r == -1 )
        printf("2:%m\n"), exit(-1);
    printf("地址绑定成功\n");

    //3、listen
    r = listen(serverfd, 10);
    if ( r == -1 )
        printf("3:%m\n"), exit(-1);
    printf("监听服务器成功\n");

    //4、accept
    while ( 1 )
    {
        len = sizeof(cadr);
        cfd = accept(serverfd, (struct sockaddr*)&cadr, &len);
        printf("有人链接：%d, IP:%s:%u\n", cfd, inet_ntoa(cadr.sin_addr), ntohs(cadr.sin_port));
    }

    return 0;
}
