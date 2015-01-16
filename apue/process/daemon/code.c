// =====================================================================================
//
//       Filename:  initialize.c
//
//    Description:  初始化一个守护进程
//
//        Version:  1.0
//        Created:  2015年01月06日 01时24分00秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include "../../apue.h"
#include "../../myerr.h"
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>
int log_to_stderr = 1;

/*
 * 初始化一个守护进程
 */
void daemonize(const char *cmd)
{
    int             i, fd0, fd1, fd2;
    pid_t           pid;
    struct rlimit   rl;
    struct sigaction sa;

    //clear file creation mask
    umask(0);

    //get maximum number of file descriptors
    if ( getrlimit(RLIMIT_NOFILE, &rl) < 0 )
        err_quit("%s: can't get file limit", cmd);

    //become a session leader to lose controlling tty
    if ( (pid = fork()) < 0 )
        err_quit("%s:can't fork", cmd);
    else if ( pid != 0 )
        exit(0);
    setsid();

    //ensure future opens won't allocate controlling ttys
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if ( sigaction(SIGHUP, &sa, NULL) < 0 )
        err_quit("%s: can't ignore SIGHUP", cmd);
    if ( (pid = fork()) < 0 )
        err_quit("%s: can't fork", cmd);
    else if ( pid != 0 )
        exit(0);

    //change the current working directory to the root so we
    //won't prevent file system from being unmounted
    if ( chdir("/") < 0 )
        err_quit("%s: can't change directory to /", cmd);

    //close all open file descriptors
    if ( rl.rlim_max == RLIM_INFINITY )
        rl.rlim_max = 1024;
    for ( i = 0; i < rl.rlim_max; i++ )
        close(i);

    //attach file descriptors 0, 1, 2to /dev/null
    fd0 = open("/dev/null", O_RDWR);
    fd1 = dup(0);
    fd2 = dup(0);

    //initialize the log file
    openlog(cmd, LOG_CONS, LOG_DAEMON);
    if ( fd0 != 0 || fd1 != 1 || fd2 != 2 )
    {
        syslog(LOG_ERR, "unexpected file descriptors %d %d %d", fd0, fd1, fd2);
        exit(1);
    }

}

/*
 * 保证只运行一个守护进程的一个副本
 */
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>

#define LOCKFILE "/var/run/daemon.pid"
#define LOCKMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)

extern int lockfile(int);

int already_running()
{
    int fd;
    char buf[16];

    fd = open(LOCKFILE, O_RDWR|O_CREAT, LOCKMODE);
    if ( fd < 0 )
    {
        syslog(LOG_ERR, "can't open %s: %s", LOCKFILE, strerror(errno));
        exit(1);
    }
    if ( lockfile(fd) < 0 )
    {
        if ( errno == EACCES || errno == EAGAIN )
        {
            close(fd);
            return(1);
        }
        syslog(LOG_ERR, "can't lock %s: %s", LOCKFILE, strerror(errno));
        exit(1);
    }
    ftruncate(fd, 0);
    sprintf(buf, "%ld", (long)getpid());
    write(fd, buf, strlen(buf)+1);

    return 0;
}

/*
 * 设置执行时关闭标志
 */
int set_cloexec(int fd)
{
    int         val;

    int ( (val = fcntl(fd, F_GETFD, 0)) < 0 )
        return -1;
    val |= FD_CLOEXEC;  //enable close-on-exec

    return fcntl(fd, F_SETFD, val);
}
