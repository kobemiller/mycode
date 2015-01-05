// =====================================================================================
//
//       Filename:  chatserv.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/18/2014 11:03:04 AM
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
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/mman.h>

int sfd;
int *fds;       //存放所有客户代理描述符号
int idx = 0;            //客户在数组中的下标
struct sockaddr_in dr;
int r;
int i;

int main()
{
    //1、建立服务器socket
    fds = mmap(0, 4*100, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_SHARED, 0, 0);
    bzero(fds, sizeof(fds));
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if ( sfd == -1 )
        printf("1:%m\n"), exit(-1);
    printf("socket OK!\n");
    //2、绑定地址
    dr.sin_family = AF_INET;
    dr.sin_port = htons(9988);
    dr.sin_addr.s_addr = inet_addr("192.168.1.100");
    r = bind(sfd, (struct sockaddr*)&dr, sizeof(dr));
    if ( r == -1 )
        printf("2:%m\n"), exit(-1);
    printf("bind OK!\n");
    //3、监听
    r = listen(sfd, 10);
    if ( r == -1 )
        printf("3:%m\n"), exit(-1);
    printf("listen OK!\n");
    //4、循环接收客户
    while ( 1 )
    {
        fds[idx] = accept(sfd, 0, 0);
        if ( fds[idx] == -1 )
            break;
        //5、建立一个子进程
        if ( fork() )
        {
            idx++;
            continue;
        }
        else
        {
            //6、子进程任务：接收客户数据并广播
            char buf[256];
            while ( 1 )
            {
                r = recv(fds[idx], buf, 255, 0);
                if (r == 0 )
                {
                    printf("有客户退出\n");
                    close(fds[idx]);
                    fds[idx] = 0;
                    break;
                }
                if ( r == -1 )
                {
                    printf("网络故障\n");
                    close(fds[idx]);
                    fds[idx] = 0;
                    break;
                }
                buf[r] = 0;
                printf("来自客户的数据:%s", buf);
                //广播
                for ( i = 0; i < 100; i++ )
                    if ( fds[i] > 0 )
                        send(fds[i], buf, r, 0);
            }
        }
    }
    return 0;
}

