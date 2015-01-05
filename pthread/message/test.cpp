#include "msg.h"

int main()
{
    CMsg m;
    struct task_info a1;
    a1.id = 1;
    strcpy(a1.name, "kobe");;
    struct task_info a2;
    a2.id = 2;
    strcpy(a2.name, "miller");;
    struct task_info a3;
    a3.id = 3;
    strcpy(a3.name, "kobe");;

    m.receive(a1);
    m.receive(a2);
    m.receive(a3);

    return 0;
}
