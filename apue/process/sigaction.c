#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle(int sig)
{
    printf("OOOOk\n");
    sleep(3);
    printf("Koooo\n");
}

int main()
{
    struct sigaction act = {0};
    act.sa_handler = handle;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask, SIGINT);
    act.sa_flags = 0;

    sigaction(SIGUSR1, &act, 0);
    while ( 1 );

    return 0;
}
