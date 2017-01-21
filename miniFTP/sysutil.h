/*
 * =====================================================================================
 *
 *       Filename:  sysutil.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2017年01月05日 17时00分25秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 * =====================================================================================
 */
#ifndef     SYSUTIL_H
#define     SYSUTIL_H

#include "common.h"

int getlocalip(char *ip);

void activate_nonblock(int fd);
void deactivate_nonblock(int fd);

int read_timeout(int fd, unsigned int wait_seconds);
int write_timeout(int fd, unsigned int wait_seconds);
int accept_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds);
int connect_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds);

ssize_t readn(int fd, void *buf, size_t count);
ssize_t writen(int fd, const void *buf, size_t count);
ssize_t recv_peek(int sockfd, void *buf, size_t len);
ssize_t readline(int sockfd, void *buf, size_t maxline);

void send_fd(int sockfd, int fd);
int recv_fd(const int sockfd);

#endif      //SYSUTIL_H
