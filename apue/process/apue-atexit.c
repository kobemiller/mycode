// =====================================================================================
//
//       Filename:  apue-atexit.c
//
//    Description:  终止处理程序实例
//                  终止处理程序每登记一次，就会被调用一次
//
//        Version:  1.0
//        Created:  12/09/2014 02:31:02 PM
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
static void my_exit1(void);
static void my_exit2(void);

int main()
{
    if ( atexit(my_exit2) != 0 )
        err_sys("can't register my_exit2");
    if ( atexit(my_exit1) != 0 )
        err_sys("can't register my_exit1");
    if ( atexit(my_exit1) != 0 )
        err_sys("can't register my_exit1");
    printf("main is done\n");

    return 0;
}

static void my_exit1(void)
{
    printf("first exit handler\n");
}
static void my_exit2(void)
{
    printf("second exit handler\n");
}
