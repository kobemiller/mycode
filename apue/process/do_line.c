// =====================================================================================
//
//       Filename:  do_line.c
//
//    Description:  进行命令处理程序的典型骨架部分
//
//        Version:  1.0
//        Created:  12/09/2014 04:46:04 PM
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

#define TOK_ADD 5
void do_line(char*);
void cmd_add(void);
int get_token(void);

int main()
{
    char line[MAXLINE];
    while ( fgets(line, MAXLINE, stdin) != NULL )
        do_line(line);
    exit(0);
}

char* tok_ptr;          //global pointer for get_token

void do_line(char* ptr)     //process one line of input
{
    int cmd;
    tok_ptr = ptr;
    while ( (cmd = get_token()) > 0 )
    {
        switch ( cmd )
        case TOK_ADD:
            cmd_add();
            break;
    }
}

void cmd_add()
{
    int token;
    token = get_token();
    //rest of processing for this command
}
int get_token()
{
    //fetch next token from line pointed to by the tok_ptr
}



