#ifndef MSG_H
#define MSG_H
#pragma once

#include <unistd.h>
#include <sys/msg.h>
#include <string.h>
struct task_info
        {
            int id;
            char name[100];
            int cnt;
        };


class CMsg
{
    public:
        CMsg();
        ~CMsg();
        int receive(struct task_info data);
        int execute();
        int msg_init();
    private:
        struct MSG_TASK
        {
            long msg_type;
            struct task_info task;
        };
        struct MSG_TASK msg_task;
        int msgid;
        int pid;
};

#endif
