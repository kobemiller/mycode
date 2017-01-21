/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年01月05日 16时59分54秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include "sysutil.h"

int main()
{
    if ( getuid() != 0 )
    {
        fprintf(stderr, "miniftp: must be started as root\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}
