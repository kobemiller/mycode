/*
 * =====================================================================================
 *
 *       Filename:  sysutil.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年01月05日 17时00分37秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */
#include "sysutil.h"

int tcp_server(const char *host, unsigned short port)
{
    return 0;
}

int getlocalip(char *ip)
{
    char host[100] = {0};
    if ( gethostname(host, sizeof(host)) < 0 )
        return -1;
    struct hostent *hp;
    if ( (hp = gethostbyname(host)) == NULL )
        return -1;
    strcpy(ip, inet_ntoa(*(struct in_addr *)hp->h_addr));

    return 0;
}

void activate_nonblock(int fd)
{
    int ret;
    int flags = fcntl(fd, F_GETFL);
    if ( flags == -1 )
        ERR_EXIT("fcntl");

    flags |= O_NONBLOCK;
    ret = fcntl(fd, F_SETFL, flags);
    if ( ret == -1 )

}
