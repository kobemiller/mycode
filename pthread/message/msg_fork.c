#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/msg.h>
#include <string.h>

#define MAX_TEXT 512
struct msg_st
{
    long int msg_type;
    char text[MAX_TEXT];
};

int main()
{
    int running = 1;
    pid_t pid;
    struct msg_st data;
    char buffer[BUFSIZ];
    int msgid = -1;

    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if ( msgid == -1 )
    {
        printf("msgget error\n");
        exit(-1);
    }

    if ( (pid = fork()) == -1 )
    {
        printf("fork error\n");
        exit(-1);
    }
    else if ( pid > 0 )
		while ( running )
		{
		    printf("Enter some text: ");
		    fgets(buffer, BUFSIZ, stdin);
		    data.msg_type = 1;
		    strcpy(data.text, buffer);
		    if ( msgsnd(msgid, (void *)&data, MAX_TEXT, 0) == -1 )
		    { 
		        printf("msgsnd error\n");
		        exit(-1);
		    }
		    if ( strncmp(buffer, "end", 3) == 0 )
		        running = 0;
		    sleep(1);
		}
    else if ( pid == 0 )
    	while ( running )
	    {
	        if ( msgrcv(msgid, (void *)&data, BUFSIZ, 0, 0) == -1 )
	        {
                printf("msgrcv error\n");
                exit(-1);
	        }
	        printf("You wrote: %s\n", data.text);
	        if ( strncmp(data.text, "end", 3) == 0 )
	            running = 0;
	    }
    return 0;
}
