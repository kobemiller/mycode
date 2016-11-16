#include "parse.h"
#include "init.h"
#include "macros.h"

char cmdline

int main()
{
    init();

    shell_loop();

    return 0;
}
