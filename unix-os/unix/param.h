/*
 * =====================================================================================
 *
 *       Filename:  param.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年11月16日 20时29分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

/* fundamental constants: do not change */
#define USIZE   16      /* size of user block (*64) */
#define NULL    0
#define NODEV   (-1)
#define ROOTINO 1       /* i number of all roots */
#define DIRSIZ  14      /* max characters per directory */

/* signals: do not change */
#define NSIG    20
#define SIGHUP  1       /* hangup */
#define SIGINT  2       /* interrupt (rubout) */
#define SIGQIT  3       /* quit (FS) */
#define SIGINS  4       /* illegal instruction */
#define SIGTRC  5       /* trace or breakpoint */


