#include <stdlib.h>
#include <iostream>
#include "msg.h"

CMsg::CMsg()
{
    msg_init();

    if ( (pid = fork()) == -1 )
        std::cerr << "fork error" << std::endl;
    else if ( pid == 0 )
        execute();
    std::cout << "over" << std::endl;
}
CMsg::~CMsg()
{

}
int CMsg::receive(struct task_info data)
{
    msg_task.msg_type = 1;
    msg_task.task = data;
    if ( msgsnd(msgid, &msg_task, sizeof(msg_task), 0) == -1 )
        std::cerr << "msgsnd error" << std::endl;
    else 
        std::cout << "msgsnd success" << std::endl;

    return 0;
}

int CMsg::execute()
{
    while ( 1 )
    {
        if ( msgrcv(msgid, &msg_task, sizeof(msg_task), 0, 0) == -1 )
            std::cerr << "msgrcv error" << std::endl;
        std::cout << msg_task.task.id << std::endl;
        std::cout << msg_task.task.name << std::endl;
        std::cout << msg_task.task.cnt << std::endl;
     //   std::cout << "end" << std::endl;
    }

    return 0;
}
int CMsg::msg_init()
{
    key_t MSGKEY = 2048;
    msgid = msgget(MSGKEY, IPC_CREAT|IPC_EXCL|0666);
    if ( msgid == -1 )
    {
        msgid = msgget(MSGKEY,0);
       // std::cerr << "msgget error" << std::endl;
       //  exit(-1);
    }

    return 0;
}
