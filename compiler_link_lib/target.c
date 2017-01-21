/*
 * =====================================================================================
 *
 *       Filename:  target.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年11月30日 21时13分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <bfd.h>

int main()
{
    const char **t = bfd_target_list();
    while ( *t )
    {
        printf("%s\n", *t);
        t++;
    }
    return 0;
}
