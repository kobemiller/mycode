// =====================================================================================
//
//       Filename:  parent-child.c
//
//    Description: 所有子进程，在父进程结束时，都将被结束？？？ 
//
//        Version:  1.0
//        Created:  12/15/2014 01:51:59 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    if ((pid = fork()) < 0)
	perror("fork error");
    else if (pid == 0)
	while (1)
	    printf("parent:%ld;my:%ld\tI'm child\n", getppid(), getpid()),
		sleep(3);
    else if (pid > 0)
	while (1)
	    printf("parent:%ld;my:%ld\tI'm parent\n", getppid(), getpid()),
		sleep(3);

    return 0;
}
