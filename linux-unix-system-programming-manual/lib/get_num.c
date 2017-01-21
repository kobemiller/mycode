/*
 * =====================================================================================
 *
 *       Filename:  get_num.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年01月18日 19时36分44秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include "get_num.h"

static void gnFail(const char *fname, const char *msg,
        const char *arg, const char *name)
{
    fprintf(stderr, "%s error", fname);
    if ( name != NULL )
        fprintf(stderr, " (in %s)", name);
    fprintf(stderr, ": %s\n", msg);
    if ( arg != NULL && *arg != '\0' )
        fprintf(stderr, "       offending text: %s\n", arg);

    exit(EXIT_FAILURE);
}
