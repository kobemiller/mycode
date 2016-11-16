#include "init.h"
#include <stdio.h>
#include <signal.h>

void signal_handler(int sig);

void init()
{
    signal(SIGINT, signal_handler);
    signal(SIGQUIT, SIG_IGN);
}

void signal_handler(int sig)
{
    printf("\n[minishell]$");
    fflush(stdout);
}
