#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    const char *p = "for((i=0; i<10;i++));do echo kobemiller;sleep 1;done";
    execlp("sh", "sh", "-c", p, "1>", "log", NULL);
    return 0;
}
