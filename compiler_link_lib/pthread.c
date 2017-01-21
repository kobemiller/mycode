/*
 * =====================================================================================
 *
 *       Filename:  pthread.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年11月26日 20时10分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <pthread.h>

int __attribute__((weak)) pthread_create(pthread_t*, const pthread_attr_t*,
       void* (*)(void*), void*);

int main()
{
    if ( pthread_create )
    {
        printf("This is multi_thread version!\n");
        //run the multi_thread version
        //main_multi_thread();
    }
    else
    {
        printf("This is single_thread version!\n");
        //run the single_thread version
        //main_single_thread();
    }
}
