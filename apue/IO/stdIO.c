// =====================================================================================
//
//       Filename:  stdIO.c
//
//    Description:  将标准输入复制到标准输出
//
//        Version:  1.0
//        Created:  12/03/2014 08:51:54 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================
#include "../apue.h"
#include "../myerr.h"

int log_to_stderr = 1;
#define BUFFSIZE    4096

int main()
{
    /*用read和write将标准输入复制到标准输出
    int n;
    char buf[BUFFSIZE];

    while ( (n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0 )
        if ( write(STDOUT_FILENO, buf, n) != n )
            err_sys("write error");
    if ( n < 0 )
        err_sys("read error");
    */
    /*用fgets和fputs将标准输入复制到标准输出 
    char buf[MAXLINE];
    while ( fgets(buf, MAXLINE, stdin) != NULL )
        if ( fputs(buf, stdout) == EOF )
            err_sys("output error");
    if ( ferror(stdin))
        err_sys("input error");
    */
    /*用getc和putc将标准输入复制到标准输出*/
    int c;
    while ( (c = getc(stdin)) != EOF )
        if ( putc(c, stdout) == EOF )
            err_sys("output error");
    if ( ferror(stdin) )
        err_sys("input error");

    return 0;
}
