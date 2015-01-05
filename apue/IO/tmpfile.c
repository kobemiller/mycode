// =====================================================================================
//
//       Filename:  tmpfile.c
//
//    Description:  tmpnam和tmpfile函数实例
//
//        Version:  1.0
//        Created:  12/04/2014 08:33:41 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:   (), 
//        Company:  
//
// =====================================================================================

#include "../apue.h"
#include "../myerr.h"

int log_to_stderr = 1;

int main()
{
    char name[L_tmpnam], line[MAXLINE];
    FILE* fp;

    printf("%s\n", tmpnam(NULL));   //first temp name
    tmpnam(name);                   //second temp name
    printf("%s\n", name);

    if ( (fp = tmpfile()) == NULL ) //create temp file
        err_sys("tmpfile error");
    fputs("one line of output\n", fp);  //write to temp file
    rewind(fp);                         //then read it back
    if ( fgets(line, sizeof(line), fp) == NULL )
        err_sys("fgets error");
    fputs(line, stdout);                //print the line we wrote

    return 0;
}
