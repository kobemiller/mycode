/*
 * =====================================================================================
 *
 *       Filename:  error_functions.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年01月18日 17时22分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */

#ifndef     ERROR_FUNCTIONS_H
#define     ERROR_FUNCTIONS_H

void errMsg(const char *format, ...);

#ifdef  __GNUC__

#define NORETURN    __attribute__ ((__noreturn__))
#else
#define NORETURN
#endif

void errExit(const char *format, ...) NORETURN;
void err_exit(const char *format, ...) NORETURN;
void errExitEN(int errnum, const char *format, ...) NORETURN;
void fatal(const char *format, ...) NORETURN;
void usageErr(const char *format, ...) NORETURN;
void cmdLineErr(const char *format, ...) NORETURN;

#endif      //ERROR_FUNCTIONS_H
