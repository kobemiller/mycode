/*
 * =====================================================================================
 *
 *       Filename:  tlpi_hdr.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年01月18日 17时16分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#ifndef     TLPI_HDR_H
#define     TLPI_HDR_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "get_num.h"
#include "error_functions.h"

typedef enum { FALSE, TRUE } Boolean;

#define min(m, n) ((m) < (n) ? (m) : (n))
#define max(m, n) ((m) > (n) ? (m) : (n))

#endif      //TLPI_HDR_H
