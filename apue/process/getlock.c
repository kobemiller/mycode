// =====================================================================================
//
//       Filename:  getlock.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/05/2014 11:27:30 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int fd;
    int r;
    struct flock lk = {0};;

    fd = open("a.txt", O_RDWR);
    if ( fd == -1 )
        printf("::%m\n"), exit(-1);
    r = fcntl(fd, F_GETLK, &lk);
    if ( r == 0 )
        printf("取得锁成功\n");
    if ( lk.l_type == F_WRLCK )
        printf("写锁\n");
    printf("start: %d, len: %d\n", lk.l_start, lk.l_len);
    return 0;
}
