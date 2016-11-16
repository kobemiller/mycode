#include "parse.h"
#include <stdio.h>

#define MAXLEN 1024

void shell_loop()
{
    while ( 1 )
    {
        printf("[minishell]$ ");
        fflush(stdout);

        if ( read_command() == -1 )
            break;
        parse_command();
        execute_command();
    }

    printf("\nexit\n");
}

int read_command()
{
    char cmd[MAXLEN + 1];
    if ( fgets(cmd, MAXLEN, stdin) == NULL )
        return -1;

    return 0;
}

/*
 * 解析命令
 */
int parse_command()
{
    /*
     * 1、判断是否有输入重定向
     * 2、判断是否有管道
     * 3、判断是否有输出重定向
     * 4、判断是否是后台作业
     * 5、判断命令结束
     */
    return 0;
}

int execute_command()
{
    pid_t pid;
    int exec_ret;

    if ( (pid = fork()) == -1 )
        ERR_EXIT("fork");
    else if ( pid == 0 )
        if ( (ret = execlp()) == -1 )
            ERR_EXIT("execlp");
    wait(NULL);

    return 0;
}

