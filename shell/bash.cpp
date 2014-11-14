#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    std::string cmd = "while true;do echo hello world;sleep 1;done";
    const char *p = cmd.c_str();
    int32_t pid;
    if ( (pid = fork()) == -1 )
    {
        std::cout << "fork error";
        exit(-1);
    }
    else if ( pid == 0 )
    {
        if ( execlp("sh", "sh", "-c", p, " >", "log", NULL) < 0 )
        {
            std::cout << "execlp error";
            exit(-1);
        }
    }
    else if ( pid > 0 )
        std::cout << pid << std::endl;
    return 0;
}
