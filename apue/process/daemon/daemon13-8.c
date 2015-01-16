// =====================================================================================
//
//       Filename:  daemon13-8.c
//
//    Description:  守护进程重读配置文件的另一种实现
//                  单线程
//
//        Version:  1.0
//        Created:  2015年01月06日 21时33分27秒
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
#include <errno.h>
int log_to_stderr = 1;

extern int lockfile(int);
extern int already_running();

void reread()
{

}

void sigterm(int signo)
{
    syslog(LOG_INFO, "got SIGTERM; exiting");
    exit(0);
}

void sighup(int signo)
{
    syslog(LOG_INFO, "Re-reading configuration file");
    reread();
}

int main(int argc, char *argv[])
{
    char            *cmd;
    struct sigaction sa;

    if ( (cmd = strrchr(argv[0], '/')) == NULL )
        cmd = argv[0];
    else
        cmd++;

    //become a daemon
    daemonize(cmd);

    //make sure only one copy of the daemon is running
    if ( already_running() )
    {
        syslog(LOG_ERR, "daemon already running");
        exit(1);
    }

    //handle signals of interest
    sa.sa_handler = sigterm;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGHUP);
    sa.sa_flags = 0;
    if ( sigaction(SIGTERM, &sa, NULL) < 0 )
    {
        syslog(LOG_ERR, "can't catch SIGTERM: %s", strerror(errno));
        exit(1);
    }
    sa.sa_handler = sighup;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGTERM);
    sa.sa_flags = 0;
    if ( sigaction(SIGHUP, &sa, NULL) < 0 )
    {
        syslog(LOG_ERR, "can't catch SIGHUP: %s", strerror(errno));
        exit(1);
    }

    //proceed with the rest of the daemon

    exit(0);
}
