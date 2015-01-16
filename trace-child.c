// =====================================================================================
//
//       Filename:  trace-child.c
//
//    Description:  父进程追踪子进程状态
//
//        Version:  1.0
//        Created:  2015年01月08日 00时29分00秒
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

child_handler(int sig)
{
    pid_t pid;
    int status;

    //WUNTRACED and WCONTINUED allow waitpid() to catch stopped and continued children
    //(in addition to terminated children)
    while ( (pid = waitpid(-1, &status, WNOHANG|WUNTRACED|WCONTINUED)) != 0 )
    {
        if ( pid == -1 )
            if ( errno == ECHILD )      //no more children
                break;
            else
                perror("waitpid");      //unexpected error
        if ( verbose )
            printf("\tinit: SIGCHLD handler: PID %ld terminated\n", (long)pid);
    }
}

