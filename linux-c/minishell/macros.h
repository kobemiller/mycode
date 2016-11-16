#ifndef _MACROS_H
#define _MACROS_H

#define MAXLNE      1024
#define MAXARG      20
#define PIPELINE    5
#define MAXNAME     100     //IO重定向文件名的最大长度

typedef struct command
{
    char *argcs[MAXARG + 1];
} COMMAND;

#endif //_MACROS_H
