/*
 * =====================================================================================
 *
 *       Filename:  macros_c_c++.c
 *
 *    Description:  c/c++预定义宏
 *
 *        Version:  1.0
 *        Created:  2015年04月10日 09时20分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <stdio.h>

int main()
{
    printf("Date: %s\n", __DATE__);
    printf("Time: %s\n", __TIME__);
    printf("File: %s\n", __FILE__);
    printf("Line: %d\n", __LINE__);

    return 0;
}
