/*
 * =====================================================================================
 *
 *       Filename:  b.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年11月24日 19时53分29秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */
int shared = 1;

void swap(int *a, int *b)
{
    *a ^= *b ^= *a ^= *b;
}
