/*
 * =====================================================================================
 *
 *       Filename:  get_num.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年01月18日 19时33分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#ifndef     GET_NUM_H
#define     GET_NUM_H

#define     GN_NONNEG   01  //value must be >= 0
#define     GN_GT_0     02  //value must be > 0

#define     GB_ANY_BASE     0100
#define     GB_BASE_8       0200
#define     GB_BASE_16      0400

long getLong(const char *arg, int flags, const char *name);
int getInt(const char *arg, int flags, const char *name);


#endif      //GET_NUM_H
