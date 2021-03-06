/*
 * bzero && memset
 */
/*
 * The bzero function sets the first n bytes of the byte area starting at s
 * to zero(bytes containing '\0')
 */
#include <string.h>

void bzero(void *s, size_t n);

/*
 * memset function fills the first n bytes of the memory area pointed to by
 * s with the constant byte c.
 * returns a pointer to the memory area s.
 */
#include <string.h>

void *memset(void *s, int c, size_t n);

/*
 *
 * that struct in_addr is a weird beast on different systems. Sometimes it's 
 * a crazy union with all kinds of #defines and other nonsense. But what you
 * should do is only use the s_addr field in this structure, because many
 * systems only implement that one.
 * http://beej.us/guide/bgnet/output/html/multipage/sockaddr_inman.html
 */

//IPv4套接字结构体
struct in_addr
{
    in_addr_t   s_addr;
};

struct sockaddr_in
{
    uint8_t         sin_len;
    sa_family_t     sin_family;
    in_port_t       sin_port;
    struct in_addr  sin_addr;
    char            sin_zero;
};

//通用套接字结构体
//唯一用途就是对只指向于协议的套接字地址结构的指针执行类型强制转换
struct sockaddr
{
    uint8_t         sa_len;
    sa_family_t     sa_family;
    char            sa_data[14];
};

//IPv6套接字结构体
struct in6_addr
{
    uint8_t         sa_addr[16];
};

#define SIN6_LEN
struct sockaddr_in6
{
    uint8_t         sin6_len;
    sa_family_t     sin6_family;
    in_port_t       sin6_port;
    uint32_t        sin6_flowinfo;
    struct in6_addr sin6_addr;
    uint32_t        sin6_scope_id;
};

//通用套接字结构体
struct sockaddr_storage
{
    uint8_t     sa_len;
    sa_family_t sa_family;

};

/*
 * IPv4和IPv6套接字地址结构是固定长度的，unix域结构和数据链路结构是可变长度的。
 */

#include <netinet/in.h>

/*
 * h-->host
 * n-->network
 * s-->port 
 * l-->IPv4
 * 在那些与网际协议所用字节序（大端）相同的系统中，这四个函数通常被定义为空宏。
 * ？？空宏
 * 理解为用不到的东西
 */
uint16_t htons(uint16_t host16bitvalue);
uint32_t htonl(uint32_t host32bitvalue);

uint16_t ntohs(uint16_t net16bitvalue);
uint32_t ntohl(uint32_t net16bitvalue);

#include <strings.h>
extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __THROW __attribute_pure__;
extern void bcopy (const void *__src, void *__dest, size_t __n) __THROW;
extern void bzero (void *__s, size_t __n) __THROW;

#include <string.h>
extern void *memset (void *__s, int __c, size_t __n) __THROW __nonnull ((1));
extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __THROW __attribute_pure__ __nonnull ((1, 2));
extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
		     size_t __n) __THROW __nonnull ((1, 2));

/*
 * inet_ntoa函数将二进制IPv4地址转换为相应的点分十进制数串
 * 由该函数的返回值所指向的字符串驻留在静态内存中，这意味着该函数是不可重入的。
 * 还要留意：该函数是以一个结构而不是结构指针作为函数参数。
 */

/*
 * inet_pton_ipv4.c
 */
int inet_pton(int family, const char *strptr, void *addrptr)
{
    if ( family == AF_INET )
    {
        struct in_addr in_val;
        if ( inet_aton(strptr, &in_val) )
        {
            memcpy(addrptr, &in_val, sizeof(struct in_addr));
            return 1;
        }
        return 0;
    }
    errno = EAFNOSUPPORT;
    return -1;
}

/*
 * inet_ntop_ipv4.c
 */
const char *inet_ntop(int family, const void *addrptr, char *strptr, size_t len)
{
    const u_char *p = (const u_char *)addrptr;

    if ( family == AF_INET )
    {
        char temp[INET_ADDRSTRLEN];

        snprintf(temp, sizeof(temp), "%d.%d.%d.%d", p[0], p[1], p[2], p[3]);
        if ( strlen(temp) >= len )
        {
            errno = ENOSPC;
            return NULL;
        }
        strcpy(strptr, temp);
        return (strptr);
    }
    errno = EAFNOSUPPORT;
    return NULL;
}

/*
 * sock_ntop.c
 */
char *sock_ntop(const struct sockaddr* sa, socklen_t salen)
{
    char portstr[8];
    static char str[128];

    switch ( sa->sa_family )
    {
        case AF_INET:
            {
                struct sockaddr_in *sin = (struct sockaddr_in *)sa;
                if ( inet_ntop(AF_INET, &sin->sin_addr, str, sizeof(str)) == NULL )
                    return NULL;
                if ( ntohs(sin->sin_port) != 0 )
                {
                    snprintf(portstr, sizeof(portstr), ":%d", ntohs(sin->sin_port));
                    strcat(str, portstr);
                }
                return (str);
            }
    }
}

/*
 * readn.c
 */
ssize_t readn(int fd, void *vptr, size_t n)
{
    size_t nleft;
    ssize_t nread;
    char *ptr;

    ptr = vptr;
    nleft  = n;
    while ( nleft > 0 )
    {
        if ( (nread = read(fd, ptr, nleft)) < 0 )
        {
            if ( errno == EINTR )
                nread = 0;
            else
                return -1;
        }
        else if ( nread == 0 )
            break;
        nleft -= nread;
        ptr += nread;
    }
    return (n-nleft);
}

ssize_t writen(int fd, const void *vptr, size_t n)
{
    size_t nleft;
    ssize_t nwritten;
    const char *ptr;

    ptr = vptr;
    nleft = n;
    while ( nleft > 0 )
    {
        if ( (nwritten = write(fd, ptr, nleft)) <= 0 )
            if ( nwritten < 0 && errno == EINTR )
                nwritten = 0;
            else
                return -1;
        nleft -= nwritten;
        ptr += nwritten;
    }
    return n;
}

/*
 * readline1.c
 */
ssize_t readline(int fd, void *vptr, size_t maxlen)
{
    ssize_t n, rc;
    char    c, *ptr;

    ptr = vptr;
    for ( n = 1; n < maxlen; n++ )
    {
        again:
        if ( (rc = read(fd, &c, 1)) == 1 )
        {
            *ptr++ = c;
            if ( c == '\n' )
                break;
        }
        else if ( rc == 0 )
        {
            *ptr = 0;
            return (n - 1);
        }
        else
        {
            if ( errno == EINTR )
                goto again;
            return -1;
        }
    }
    *ptr = 0;
    return n;
}

/*
 * readline.c
 */
static int  read_cnt;
static char *read_ptr;
static char read_buf[MAXLINE];

static ssize_t my_read(int fd, char *ptr)
{
    if ( read_cnt <= 0 )
    {
        again:
        if ( (read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0 )
        {
            if ( errno == EINTR )
                goto again;
            return -1;
        }
        else if ( read_cnt === 0 )
            return 0;
        read_ptr = read_buf;
    }

    read_cnt--;
    *ptr = *read_ptr++;
    return 1;
}

ssize_t readline(int fd, void *vptr, size_t maxlen)
{
    ssize_t n, rc;
    char    c, *ptr;

    ptr = vptr;
    for ( n = 1; n < maxlen; n++ )
    {
        if ( (rc = my_read(fd, &c)) == 1 )
        {
            *ptr++ = c;
            if ( c == '\n' )
                break;
        }
        else if ( rc == 0 )
        {
            *ptr = 0;
            return (n - 1);
        }
        else
            return -1;
    }
    *ptr = 0;
    return n;
}

ssize_t readlinebuf(void **vptrptr)
{
    if ( read_cnt )
        *vptrptr = read_ptr;
    return read_cnt;
}

/*
 * linux支持一个新的套接字类型SOCK_PACKET, 支持对数据链路的访问
 */
/*
 * AF_***与PF_***
 * AF_***表示地址族，PF_***表示协议族
 * 头文件<sys/socket.h>中为一个给定的协议定义的PF_值总是与协议AF_值相等
 */

/*
 * 典型的并发服务器模型
 */
{
    pid_t   pid;
    int     listenfd, connfd;

    listenfd = Socket();
    bind(listenfd, ...);
    listen(listenfd, LISTENQ);

    for ( ; ; )
    {
        connfd = accept();

        if ( (pid = fork()) == 0 )
        {
            close(listenfd);
            doit(connfd);
            close(connfd);
            exit(0);
        }
        close(connfd);
    }
}

int sockfd_to_family(int sockfd)
{
    struct sockaddr_storage ss;
    socklen_t len;

    len = sizeof(ss);
    if ( getsockname(sockfd, (SA*)&ss, &len) < 0 )
        return -1;
    return (ss.sin_family);
}

/*
 * TIME_WAIT状态
 * 1、可靠的实现TCP全双工连接的终止
 * 2、允许老的重复分节在网络中消逝
 */

typedef void sigfunc(int);
//void (*signal(int signo, void (*func)(int))) (int);
sigfunc *signal(int signo, sigfunc *func);

sigfunc *signal(int signo, sigfunc *func)
{
    struct sigaction act, oact;

    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    if ( signo == SIGALRM )
    {
#ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT;
#endif
    }
    else
    {
#ifdef SA_RESTART
        act.sa_flags |= SA_RESTART;
#endif
    }

    if ( sigaction(signo, &act, &oact) < 0 )
        return (SIG_ERR);
    return (oact.sa_handler);
}
/*
 * 1、信号处理函数在被调用时其他信号被阻塞
 * 2、unix默认信号是不排队的
 *
 */

void sig_chld(int signo)
{
    pid_t   pid;
    int     stat;

    pid = wait(&stat);
    /*
     * 在信号处理函数中调用printf这样的标准IO函数是不合适的，
     * 可重入问题
     */
    printf("child %d terminated\n", pid);

    return;
}

#include <sys/wait.h>
pid_t wait(int *statloc);
pid_t waitpid(pid_t pid, int *statloc, int options);
/*
 * wait和waitpid返回两个值：已终止子进程的pid和statloc指针返回的子进程终止状态（一个整数）
 * options参数允许我们指定附加选项，最常用的是WNOHANG：告知内核在没有已终止子进程时不要阻塞
 */

/*
 * tcpcli04.c
 */
int main(int argc, char **argv)
{
    int i, sockfd[5];
    struct sockaddr_in servaddr;

    if ( argc != 2 )
        err_quit("usage: tcpcli <IPaddress>");
    for ( i = 0; i < 5; i++ )
    {
        sockfd[i] = socket(AF_INET, SOCK_STREAM, 0);

        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_port = htons(SERV_PORT);
        inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

        connect(sockfd[i], (SA*)&servaddr, sizeof(servaddr));
    }

    str_cli(stdin, sockfd[0]);

    return 0;
}

/*
 * 调用waitpid的sig_chld
 */
void sig_chld(int signo)
{
    pid_t   pid;
    int     stat;

    while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0 )
        printf("child %d terminated\n", pid);

    return;
}

/*
 * tcpserv04.c
 */
int main(int argc, char **argv)
{
    int     listenfd, connfd;
    pid_t   childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;
    void sig_chld(int);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(listenfd, (SA*)&servaddr, sizeof(servaddr));

    listen(listenfd, LISTENQ);

    signal(SIGCHLD, sig_chld);

    for ( ; ; )
    {
        clilen = sizeof(cliaddr);
        if ( (connfd = accept(listen, (SA*)&cliaddr, &clilen)) < 0 )
            if ( errno == EINTR )
                continue;
            else
                err_sys("accept error");
        if ( (childpid = fork()) == 0 )
        {
            close(listenfd);
            str_echo(connfd);
            exit(0);
        }
        close(connfd);
    }

    return 0;
}

/*
 * 调用writen两次：第一次把文本行数据的第一个字节写入套接字
 * 第二次把同一文本行中剩余字节写入套接字。
 * 目的是让第一次writen引发一个RST，再让第二个writen产生SIGPIPE
 */
void str_cli(FILE *fp, int sockfd)
{
    char sendline[MAXLINE], recvline[MAXLINE];

    while ( fgets(sendline, MAXLINE, fp) != NULL )
    {
        writen(sockfd, sendline, 1);
        sleep(1);
        writen(sockfd, sendline + 1, strlen(sendline) - 1);

        if ( readline(sockfd, recvline, MAXLINE) == 0 )
            err_quit("str_cli: server terminated prematurely");
        fputs(recvline, stdout);
    }
}

