// =====================================================================================
//
//       Filename:  getip.c
//
//    Description:  
//
//        Version:  1.0
//        Created:  12/17/2014 08:29:50 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include <stdio.h>
#include <netdb.h>

int main()
{
    struct hostent *ent;
    ent = gethostbyname("www.baidu.com");
    //printf("%s\n", ent->h_aliases[0]);
    printf("%hhu.%hhu.%hhu.%hhu\n", 
            ent->h_addr[0],
            ent->h_addr[1],
            ent->h_addr[2],
            ent->h_addr[3]);
    return 0;
}
