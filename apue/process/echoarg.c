// =====================================================================================
//
//       Filename:  echoarg.c
//
//    Description:  将所有的命令行参数回显到标准输出
//
//        Version:  1.0
//        Created:  12/09/2014 02:38:33 PM
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

int main(int argc, char* argv[])
{
    int i;
    for ( i = 0; i < argc; i++ )
    //for ( i = 0; argv[i] != NULL; i++ )
    //因为argv[argc] == NULL
        printf("argv[%d]: %s\n", i, argv[i]);
    exit(0);
}
